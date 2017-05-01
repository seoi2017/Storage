#include<bits/stdc++.h>
#define N 100003
using namespace std;
typedef long long ll_t;
inline void in(ll_t &x){
    char a=getchar();x=0; 
    while(a<'0' || a>'9')a=getchar();
    while(a>='0' && a<='9')x=x*10+(a-'0'),a=getchar();
}
inline void out(ll_t x){
    int num=0;char c[20];
    while(x)c[++num]=(x%10)+48,x/=10;
    while(num)putchar(c[num--]);
    putchar('\n'); 
}
struct node_t{
    ll_t add,sum,mul,l,r;
    node_t *lc,*rc;
}s[N<<2],*root;
ll_t n,m,P,tl,tr,tc,ts,top=0;
node_t *build(ll_t l,ll_t r){
    node_t *now=&s[++top];
    now->l=l,now->r=r,now->mul=1;
    if(l^r){
        node_t *&lson=now->lc,*&rson=now->rc;
        ll_t mid=(l+r)>>1;
        lson=build(l,mid);
        rson=build(mid+1,r);
        now->sum=(lson->sum+rson->sum)%P;
    }
    else in(now->sum);
    return now;
}
inline void pushdown(node_t *now,node_t *lson,node_t *rson){
    ll_t &fadd=now->add,&fmul=now->mul;
    lson->mul=(lson->mul*fmul)%P,lson->add=(lson->add*fmul+fadd)%P;
    rson->mul=(rson->mul*fmul)%P,rson->add=(rson->add*fmul+fadd)%P;
    lson->sum=(lson->sum*fmul+(lson->r-lson->l+1)*fadd)%P;
    rson->sum=(rson->sum*fmul+(rson->r-rson->l+1)*fadd)%P;
    fadd=0,fmul=1;
}
void addup(node_t *now,ll_t l,ll_t r,ll_t s){
    ll_t nl=now->l,nr=now->r;
    if(l<=nl && r>=nr){
        now->add=(now->add+s)%P;
        now->sum=(now->sum+(nr-nl+1)*s)%P;
        return;
    }
    node_t *lson=now->lc,*rson=now->rc;
    if(now->add^0|now->mul^1)pushdown(now,lson,rson);
    ll_t mid=(nl+nr)>>1;
    if(l<=mid)addup(lson,l,r,s);
    if(r>mid)addup(rson,l,r,s);
    now->sum=(lson->sum+rson->sum)%P;
}
void mulup(node_t *now,ll_t l,ll_t r,ll_t s){
    ll_t nl=now->l,nr=now->r;
    if(l<=nl && r>=nr){
        now->mul=(now->mul*s)%P;
        now->add=(now->add*s)%P;
        now->sum=(now->sum*s)%P;
        return;
    }
    node_t *lson=now->lc,*rson=now->rc;
    if(now->add^0|now->mul^1)pushdown(now,lson,rson);
    ll_t mid=(nl+nr)>>1;
    if(l<=mid)mulup(lson,l,r,s);
    if(r>mid)mulup(rson,l,r,s);
    now->sum=(lson->sum+rson->sum)%P;
}
ll_t query(node_t *now,ll_t l,ll_t r){
    ll_t nl=now->l,nr=now->r;
    if(l<=nl && r>=nr)return now->sum;
    node_t *lson=now->lc,*rson=now->rc;
    if(now->add^0|now->mul^1)pushdown(now,lson,rson);
    ll_t ans=0,mid=(nl+nr)>>1;
    if(l<=mid)ans=(ans+query(lson,l,r));
    if(r>mid)ans=(ans+query(rson,l,r))%P;
    now->sum=(lson->sum+rson->sum)%P;
    return ans;
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    in(n),in(m),in(P);
    root=build(1,n);
    for(int i=1;i<=m;i++){
        in(tc),in(tl),in(tr);
        if(!(tc^3))out(query(root,tl,tr));
        else{
            in(ts);
            (!(tc^1))?(mulup(root,tl,tr,ts)):(addup(root,tl,tr,ts));
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}