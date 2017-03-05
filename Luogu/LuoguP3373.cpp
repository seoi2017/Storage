#include<bits/stdc++.h>//万能头文件
#define lazy(x) (lazy[x])
#define mlaz(x) (lazy_mul[x])
#define sum(x) (node[x])
#define lson(x) (x<<1)
#define rson(x) ((x<<1)+1)
#define nls(x) (node[lson(x)])
#define nrs(x) (node[rson(x)])
#define lazyls(x) (lazy[lson(x)])
#define lazyrs(x) (lazy[rson(x)])
#define mlazls(x) (lazy_mul[lson(x)])
#define mlazrs(x) (lazy_mul[rson(x)])
#define N 131072
using namespace std;
typedef long long integer;
struct segtree{
    integer n,mod,node[N*4],lc[N*4],rc[N*4],mid[N*4],lazy[N*4],lazy_mul[N*4];
    segtree(){
        memset(node,0,sizeof(node));
        memset(lazy,0,sizeof(lazy));
        memset(lazy_mul,0,sizeof(lazy_mul));
    }
    inline integer get_bit(integer x){
        integer M=1;
        while(M<n)M<<=1;
        return M+(x-1);
    }
    inline integer get_node(integer x){
        return (get_bit(1)+x-1);
    }
    inline integer range(integer x){
        return (min((integer)get_node(n),rc[x])-lc[x]+1);
    }
    inline bool end(integer x){
        return (x>=get_bit(1));
    }
    void build(){
        for(integer i=get_bit(1);i<=get_bit(1)*2-1;i++)lc[i]=i,rc[i]=i,mid[i]=i,lazy_mul[i]=1;
        for(integer i=get_bit(1)-1;i!=0;i--)lc[i]=lc[lson(i)],rc[i]=rc[rson(i)],mid[i]=(rc[i]+lc[i])/2,node[i]=node[lson(i)]+node[rson(i)],lazy_mul[i]=1;
    }
    void pushdown(integer x){
        if(lazy[x]==0 && lazy_mul[x]==1)return;
        if(end(x)){lazy_mul[x]=1,lazy[x]=0;return;}
        nls(x)=(nls(x)*mlaz(x)+lazy(x)*range(lson(x)))%mod;
        nrs(x)=(nrs(x)*mlaz(x)+lazy(x)*range(rson(x)))%mod;
        mlazls(x)=(mlazls(x)*mlaz(x))%mod;
        lazyls(x)=(lazyls(x)*mlaz(x)+lazy(x))%mod;
        mlazrs(x)=(mlazrs(x)*mlaz(x))%mod;
        lazyrs(x)=(lazyrs(x)*mlaz(x)+lazy(x))%mod;
        mlaz(x)=1,lazy(x)=0;
    }
    void update(integer x,integer l,integer r,integer s){
        pushdown(x);
        if(l<=lc[x] && rc[x]<=r){
            sum(x)=(sum(x)+s*(range(x)))%mod;
            lazy(x)=s%mod;
            return;
        }
        if(l<=mid[x])update(lson(x),l,r,s);
        if(mid[x]<r)update(rson(x),l,r,s);
        sum(x)=(nls(x)+nrs(x))%mod;
    }
    void update_mul(integer x,integer l,integer r,integer s){
        pushdown(x);
        if(l<=lc[x] && rc[x]<=r){
            sum(x)=(sum(x)*s)%mod;
            mlaz(x)=s%mod;
            return;
        }
        if(l<=mid[x])update_mul(lson(x),l,r,s);
        if(mid[x]<r)update_mul(rson(x),l,r,s);
        sum(x)=(nls(x)+nrs(x))%mod;
    }
    integer query(integer x,integer l,integer r){
        int ans=0;
        pushdown(x);
        if(l<=lc[x] && rc[x]<=r)return sum(x);
        if(l<=mid[x])ans+=query(lson(x),l,r);
        if(mid[x]<r)ans+=query(rson(x),l,r);
        return ans%mod;
    }
}tree;
int main(){
    integer ask;
    scanf("%lld%lld%lld",&tree.n,&ask,&tree.mod);
    for(integer i=tree.get_bit(1);i<=tree.get_bit(1)+(tree.n-1);i++){
        scanf("%lld",&tree.node[i]);
    }
    tree.build();
    while(ask--){
        integer command,x,y,o;
        scanf("%lld",&command);
        if(command==1)scanf("%lld%lld%lld",&x,&y,&o),tree.update_mul(1,tree.get_node(x),tree.get_node(y),o);
        else if(command==2)scanf("%lld%lld%lld",&x,&y,&o),tree.update(1,tree.get_node(x),tree.get_node(y),o);
        else if(command==3)scanf("%lld%lld",&x,&y),printf("%lld\n",tree.query(1,tree.get_node(x),tree.get_node(y)));
    }
    system("pause");
    return 0;
}