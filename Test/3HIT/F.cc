#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define N 200007
using namespace std;
typedef long long ll_t;
ll_t aa[N],c[N],ans=0;
struct code_t{
   int v;
   int order;
}ins[N];
//SegTree
struct node_t{
    ll_t mx,l,r;
    node_t *lc,*rc;
}s[N<<2],*root;
ll_t n,m,tl,tr,top=0;
node_t *build(ll_t l,ll_t r){
    node_t *now=&s[++top];
    now->l=l,now->r=r;
    if(l!=r){
        node_t *&lson=now->lc,*&rson=now->rc;
        ll_t mid=(l+r)>>1;
        lson=build(l,mid);
        rson=build(mid+1,r);
        now->mx=max(lson->mx,rson->mx);
    }
    else scanf("%lld",&now->mx),ins[l].v=now->mx,ins[l].order=l;
    return now;
}
ll_t query(node_t *now,ll_t l,ll_t r){
    ll_t nl=now->l,nr=now->r;
    if(l<=nl && r>=nr)return now->mx;
    node_t *lson=now->lc,*rson=now->rc;
    ll_t ans=-2474836482147483648LL,mid=(nl+nr)>>1;
    if(l<=mid)ans=max(ans,query(lson,l,r));
    if(r>mid)ans=max(ans,query(rson,l,r));
    return ans;
}
//NiXuDui
inline int lowbit(int x){
    return x&(-x);
}
void update(int t,int value){
    int i;
    for(i=t;i<=n;i+=lowbit(i))
        c[i]+=(value*1LL);
}
ll_t getsum(int x){
    int i;
    ll_t temp=0LL;
    for(i=x;i>=1;i-=lowbit(i))
        temp+=c[i];
    return temp;
}
inline bool cmp(code_t a ,code_t b){
    return a.v<b.v;
}
int main(){
    scanf("%lld%lld",&n,&m);
    root=build(1,n);
    sort(ins+1,ins+1+n,cmp);
    for(int i=1;i<=n;i++)
        aa[ins[i].order]=i;
    long long ans=0;
    for(int i=1;i<=n;i++){
        update(aa[i],1);
        ans+=(i-getsum(aa[i]))*1LL;
    }
    printf("%lld\n",ans);
    for(int i=1;i<=m;i++){
        scanf("%lld%lld",&tl,&tr);
        if(tl>tr)swap(tl,tr);
        printf("%lld\n",query(root,tl,tr));
    }
    system("pause");
    return 0;
}