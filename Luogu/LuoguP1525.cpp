#include<bits/stdc++.h>//Accepted!
using namespace std;
const int N=10010,M=110010;
struct edge_t{int u,v,l;}e[M];
int fa[N*5]={0},n,m,ans=0;//FA Array:1 to n for friend,n+1 to n*2 for enemy.
inline bool cmp(edge_t x,edge_t y){return x.l>y.l;}
inline int findfa(int x){return fa[x]==x?x:(fa[x]=findfa(fa[x]));}
inline void bing(int x,int y){fa[y]=x;}
int main(){
    freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].l);
    for(int i=1;i<=n*2;i++)fa[i]=i;
    sort(e+1,e+1+m,cmp);
    for(int i=1;i<=m;i++){
        int x=findfa(e[i].u),y=findfa(e[i].v);
        if(x==y){ans=e[i].l;break;}
        bing(findfa(e[i].u+n),y),bing(findfa(e[i].v+n),x);
    }
    printf("%d\n",ans);
    fclose(stdin),fclose(stdout);
    return 0;
}