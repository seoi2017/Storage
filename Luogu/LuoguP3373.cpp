#include<bits/stdc++.h>//Accepted!
#define mid(x,y) (x+y>>1)
#define root (&seg[1])
#define lson (now->lc)
#define rson (now->rc)
#define pushup (now->s=(now->lc->s+now->rc->s)%mod)
using namespace std;typedef long long int ull_t;
const int N=100010,M=100010;int n,m,top=0,ind[N];ull_t mod;
struct segnode_t{ull_t s,add,mul;int l,r;segnode_t *lc,*rc,*fa;}seg[N<<2];
inline int build(int l,int r){
    int temp=++top;segnode_t *now=&seg[temp];
    now->s=0,now->add=0,now->mul=1;now->l=l,now->r=r;now->fa=NULL;
    if(l!=r)lson=&seg[build(l,mid(l,r))],rson=&seg[build(mid(l,r)+1,r)],lson->fa=rson->fa=now;
    else lson=NULL,rson=NULL,ind[l]=temp;
    return temp;
}
inline void over_build(segnode_t *now){
    now->s=lson->s+rson->s;
    if(now->fa!=NULL)over_build(now->fa);
}
inline void pushdown(segnode_t *now){
    lson->mul=(lson->mul*now->mul)%mod,rson->mul=(rson->mul*now->mul)%mod;
    lson->add=(lson->add*now->mul+now->add)%mod,rson->add=(rson->add*now->mul+now->add)%mod;
    lson->s=(lson->s*now->mul+now->add*(lson->r-lson->l+1))%mod,rson->s=(rson->s*now->mul+now->add*(rson->r-rson->l+1))%mod;
    now->add=0,now->mul=1;return;
}
inline void add_update(segnode_t *now,int l,int r,ull_t add){
    if(now->l==l && now->r==r){
        now->add=(now->add+add)%mod;
        now->s=(((ull_t)(now->r-now->l+1)*add)%mod+now->s)%mod;
        return;
    }
    if(now->add!=0 || now->mul!=1)pushdown(now);
    if(l<=lson->r)add_update(lson,l,min(lson->r,r),add);
    if(r>=rson->l)add_update(rson,max(rson->l,l),r,add);
    pushup;return;
}
inline void mul_update(segnode_t *now,int l,int r,ull_t mul){
    if(now->l==l && now->r==r){
        now->mul=(now->mul*mul)%mod,now->add=(now->add*mul)%mod;
        now->s=(now->s*mul)%mod;
        return;
    }
    if(now->add!=0 || now->mul!=1)pushdown(now);
    if(l<=lson->r)mul_update(lson,l,min(lson->r,r),mul);
    if(r>=rson->l)mul_update(rson,max(rson->l,l),r,mul);
    pushup;return;
}
inline ull_t query(segnode_t *now,int l,int r){
    if(now->l==l && now->r==r)return now->s%mod;
    if(now->add!=0 || now->mul!=1)pushdown(now);
    ull_t ans=0;
    if(l<=lson->r)ans=(ans+query(lson,l,min(lson->r,r)))%mod;
    if(r>=rson->l)ans=(ans+query(rson,max(rson->l,l),r))%mod;
    pushup;return ans;
}
void solve(){
    ull_t temp;scanf("%d%d%lld",&n,&m,&mod),build(1,n);
    for(int i=1;i<=n;i++)scanf("%lld",&temp),seg[ind[i]].s=temp,over_build(seg[ind[i]].fa);
    for(int i=1;i<=m;i++){
        int x,y;ull_t z;scanf("%lld",&temp);
        if(temp==1)/*mul*/scanf("%d%d%lld",&x,&y,&z),mul_update(root,x,y,z);
        else if(temp==2)/*add*/scanf("%d%d%lld",&x,&y,&z),add_update(root,x,y,z);
        else if(temp==3)/*query%mod*/scanf("%d%d",&x,&y),printf("%lld\n",query(root,x,y)%mod);
    }
}
int main(){
    freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
    solve();
    fclose(stdin),fclose(stdout);
    return 0;
}