#include<bits/stdc++.h>
#define lson(x) (x<<1)
#define rson(x) ((x<<1)+1)
#define N 131072
using namespace std;
typedef int integer;
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
    void build(){
        for(integer i=get_bit(1);i<=get_bit(1)*2-1;i++)lc[i]=i,rc[i]=i,mid[i]=i;
        for(integer i=get_bit(1)-1;i!=0;i--)lc[i]=lc[lson(i)],rc[i]=rc[rson(i)],mid[i]=(rc[i]+lc[i])/2,node[i]=node[lson(i)]+node[(lson(i))+1];
    }
    void pushdown(integer x){
        if(lazy[x]!=0){
            node[x]+=(min((integer)get_node(n),rc[x])-lc[x]+1)*lazy[x];
            lazy[lson(x)]+=lazy[x],lazy[(lson(x))+1]+=lazy[x];
            lazy[x]=0;
        }
        //===============
        if(lazy_mul[x]!=0){
            node[x]*=lazy_mul[x];
            lazy_mul[lson(x)]+=lazy_mul[x],lazy_mul[(lson(x))+1]+=lazy_mul[x];
            lazy_mul[x]=0;
        }
    }
    void update(integer x,integer l,integer r,integer s){
        if(x>=get_bit(1)){if(lazy[x]!=0){node[x]+=lazy[x],lazy[x]=0;}node[x]+=s;return;}
        if(l==lc[x] && r==rc[x]){lazy[x]+=s;return;}
        pushdown(x);
        node[x]+=((r-l+1)*s);
        if(r<=mid[x])update(lson(x),l,r,s);
        else if(l>mid[x])update((lson(x))+1,l,r,s);
        else update(lson(x),l,mid[x],s),update((lson(x))+1,mid[x]+1,r,s);
    }
    void update_mul(integer x,integer l,integer r,integer s){
        if(x>=get_bit(1)){if(lazy_mul[x]!=0){node[x]*=lazy_mul[x],lazy_mul[x]=0;}node[x]*=s;return;}
        if(l==lc[x] && r==rc[x]){lazy_mul[x]+=s;return;}
        pushdown(x);
        node[x]*=s;
        if(r<=mid[x])update_mul(lson(x),l,r,s);
        else if(l>mid[x])update_mul((lson(x))+1,l,r,s);
        else update_mul(lson(x),l,mid[x],s),update_mul((lson(x))+1,mid[x]+1,r,s);
    }
    integer query(integer x,integer l,integer r){
        integer ans=0;
        if(x>=get_bit(1)){if(lazy[x]!=0){node[x]+=lazy[x],lazy[x]=0;}if(lazy_mul[x]!=0){node[x]*=lazy_mul[x],lazy_mul[x]=0;}ans+=node[x];}
        else if(l==lc[x] && r==rc[x])ans+=(node[x]+(rc[x]-lc[x]+1)*lazy[x]);
        else{
            if(lazy[x]!=0 || lazy_mul[x]!=0)pushdown(x);
            if(r<=mid[x])ans+=query(lson(x),l,r);
            else if(l>mid[x])ans+=query((lson(x))+1,l,r);
            else ans+=query(lson(x),l,mid[x]),ans+=query((lson(x))+1,mid[x]+1,r);
        }
        return ans;
    }
    void debug_out(){
        for(int i=1;i<=get_bit(1)-1;i++){
            printf("%d:[node:%d|lazy:%d|lazy_mul:%d] ",i,node[i],lazy[i],lazy_mul[i]);
        }
    }
}tree;
int main(){
    integer ask;
    scanf("%d%d%d",&tree.n,&ask,&tree.mod);
    for(integer i=tree.get_bit(1);i<=tree.get_bit(1)+(tree.n-1);i++){
        scanf("%d",&tree.node[i]);
    }
    tree.build();
    while(ask--){
        integer command,x,y,o;
        scanf("%d",&command);
        if(command==1)scanf("%d%d%d",&x,&y,&o),tree.update_mul(1,tree.get_node(x),tree.get_node(y),o),tree.debug_out();
        else if(command==2)scanf("%d%d%d",&x,&y,&o),tree.update(1,tree.get_node(x),tree.get_node(y),o);
        else if(command==3)scanf("%d%d",&x,&y),printf("%d\n",tree.query(1,tree.get_node(x),tree.get_node(y))),tree.debug_out();
        //else tree.debug_out();
    }
    system("pause");
    return 0;
}