#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#define N 100005
typedef long long ll_t;
struct fs_t{
    ll_t a,b;
    fs_t(int a,int b){
        this->a=a;
        this->b=b;
    }
    int gcd(int x,int y){
        return y==0?x:gcd(y,x%y);
    }
    inline void yf(){
        int _gcd=gcd(this->a,this->b);
        if(_gcd==1)return;
        this->a/=_gcd;
        this->b/=_gcd;
    }
    inline void cl(fs_t x){
        this->a*=x.a;
        this->b*=x.b;
        this->yf();
    }
}
struct node_t{
    int s,a,l,r;
    fs_t q;
    node_t *lc,*rc;
}seg[N<<2],*root;
int top=0;
inline int length(ndoe_t *now){
    return (now->r-now->l)+1;
}
node_t *build(int l,int r){
    node_t *now=&seg[++top];
    now->l=l,now->r=r,now->q=fs_t(0,1);
    if(r==l)return now;
    int mid=(l+r)>>1;
    node_t *&lson=now->lc,*&rson=now->rc;
    lson=build(l,mid);
    rson=build(mid+1,r);
    return now;
}
inline void pushdown(node_t *now,node_t *lson,node_t *rson){
    int &fa=now->a;
    lson->a+=fa,rson->a+=fa;
    lson->s+=length(lson)*fa,rson->s=length(rson)*fa;
    fa=0;
}
inline void maintain(node_t *now,node_t *lson,node_t *rson){
    
}
void update(node_t *now,int l,int r,int a){
    int nl=now->l,nr=now->r;
    if(l<=nl && nr<=r){
        now->a+=a;
        now->s+=length(now)*a;
        return;
    }
    node_t *lson=now->lc,*rson=now->rc;
    if(now->a!=0)pushdown(now,lson,rson);
    int mid=(nl+nr)>>1;
    if(l<=mid)update(lson,l,r);
    if(r>mid)update(rson,l,r);
    maintain(now,lson,rson);
}
fs_t query(node_t *now,int l,int r){
    int nl=now->l,nr=now->r;
    if(l<=nl && nr<=r)return now->q;
    node_t *lson=now->lc,*rson=now->rc;
    if(now->a!=0)pushdown(now,lson,rson);
    fs_t ans(0,1);
    int mid=(nl+nr)>>1;
    if(l<=mid)ans.cl(query(lson,l,r));
    if(r>mid)ans.cl(query(rson,l,r));
    maintain(now,lson,rson);
    return ans;
}
//=========================================
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d%d\n",&n,&m);
    root=build(1,n);
    int tc,tl,tr,ta;
    for(int i=1;i<=m;i++){
        scanf("%c%d%d",&tc,&tl,&tr);
        if(tc=='C'){
            scanf("%d",&ta);
            update(root,tl,tr,ta);
        }
        else{
            fs_t ans=query(root,tl,tr);
            printf("%I64d/%I64d\n",ans.a,ans.b);
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}