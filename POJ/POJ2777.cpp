#include<bits/stdc++.h>
#define N 131072
#define lson(x) (x<<1)
#define rson(x) ((x<<1)+1)
#define get(x) (1<<(x-1))
using namespace std;
struct segtree{
    int n,lc[N*4],rc[N*4];
    unsigned long long node[N*4],lazy[N*4];
    inline int get_bit(x){
        int M=1;
        while(M<n)M<<=1;
        return M+(x-1);
    }
    void build(){
        for(int i=get_bit(1);i<=get_bit(1)+n-1;i++)lc[i]=rc[i]=i,node[i]=1,lazy[i]=0;
        for(int i=get_bit(1)-1;i>=1;i--)lc[i]=lc[lson(i)],rc=rs[lson(i)],lazy[i]=0,node[i]=(node[lson(i)]|node[rson(i)]);
    }
    void pushdown(int x){
        lazy[lson(x)]=lazy[x];
        lazy[rson(x)]=lazy[x];
        node[x]=lazy[x];
    }
    void update(int x,int l,int r,int s){
        if(x>=get_bit(1)){
            if(lazy[x]!=0)node[x]=lazy[x],lazy[x]=0;
            return;
        }
        if(rc[x]==r && lc[x]==l){
            lazy[x]=s;
        }
        pushdown(x);
        int mid=(lc[x]+rc[x])>>1;
        if(l<=mid)update(lson(x),l,mid,s);
        if(r>mid)update(rson(x),mid+1,r,s);
    }
    int query(){

    }
}tree;
int main(){
    scanf("%d%d%d",&tree.n,&temp,&);
    system("pause");
    return 0;
}