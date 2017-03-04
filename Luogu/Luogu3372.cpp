#include"hfs/header.h"//#include<bits/stdc++.h>
#define N 131072
using namespace std;
typedef long long integer;
struct segtree{
    integer n,node[N*4],lc[N*4],rc[N*4],mid[N*4],lazy[N*4];
    segtree(){
        memset(node,0,sizeof(node));
        memset(lazy,0,sizeof(lazy));
    }
    inline integer get_bit(integer x){
        integer M=1;
        while(M<n)M<<=1;
        return M+(x-1);
    }
    inline integer get_node(integer x){
        return (get_bit(1)+x-1);
    }
    void build(){
        for(integer i=get_bit(1);i<=get_bit(1)*2-1;i++)lc[i]=i,rc[i]=i,mid[i]=i;
        for(integer i=get_bit(1)-1;i!=0;i--)lc[i]=lc[i<<1],rc[i]=rc[(i<<1)+1],mid[i]=(rc[i]+lc[i])/2,node[i]=node[i<<1]+node[(i<<1)+1];
    }
    void pushdown(integer x){
        node[x]+=(min((integer)get_node(n),rc[x])-lc[x]+1)*lazy[x];
        lazy[x<<1]+=lazy[x],lazy[(x<<1)+1]+=lazy[x];
        lazy[x]=0;
    }
    void update(integer x,integer l,integer r,integer s){
        if(x>=get_bit(1)){if(lazy[x]!=0){node[x]+=lazy[x],lazy[x]=0;}node[x]+=s;return;}
        if(l==lc[x] && r==rc[x]){lazy[x]+=s;return;}
        pushdown(x);
        node[x]+=((r-l+1)*s);
        if(r<=mid[x])update(x<<1,l,r,s);
        else if(l>mid[x])update((x<<1)+1,l,r,s);
        else update(x<<1,l,mid[x],s),update((x<<1)+1,mid[x]+1,r,s);
    }
    integer query(integer x,integer l,integer r){
        integer ans=0;
        if(x>=get_bit(1)){if(lazy[x]!=0){node[x]+=lazy[x],lazy[x]=0;}ans+=node[x];}
        else if(l==lc[x] && r==rc[x])ans+=(node[x]+(rc[x]-lc[x]+1)*lazy[x]);
        else{
            if(lazy[x]!=0)pushdown(x);
            if(r<=mid[x])ans+=query(x<<1,l,r);
            else if(l>mid[x])ans+=query((x<<1)+1,l,r);
            else ans+=query(x<<1,l,mid[x]),ans+=query((x<<1)+1,mid[x]+1,r);
        }
        return ans;
    }
}tree;
int main(){
    integer ask;
    scanf("%lld%lld",&tree.n,&ask);
    for(integer i=tree.get_bit(1);i<=tree.get_bit(1)+(tree.n-1);i++){
        scanf("%lld",&tree.node[i]);
    }
    tree.build();
    while(ask--){
        integer command,x,y,o;
        scanf("%lld",&command);
        if(command==1)scanf("%lld%lld%lld",&x,&y,&o),tree.update(1,tree.get_node(x),tree.get_node(y),o);
        else if(command==2)scanf("%lld%lld",&x,&y),printf("%lld\n",tree.query(1,tree.get_node(x),tree.get_node(y)));
        //else tree.debug_out();
    }
    system("pause");
    return 0;
}
/*
input:
8 6
1 2 3 4 5 6 7 8
2 2 7
1 2 5 2
2 1 6
1 1 4 1
1 4 6 1
2 4 5
output:
27
1+4+5+6+7+6 7 8 
29
2 5 6 7 7 6 7 8
2 5 6 8+8 7 7 8
16
*/