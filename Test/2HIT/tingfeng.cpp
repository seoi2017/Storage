#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int n,m,c,a[100007],deep[100007],tx,ty,tz;
struct edge_t{
    int dat;
    edge_t* nxt;
}e[200007];
int top,p[100007][21];
bool vis[100007];
unsigned long long ans;
inline void add_edge(int x,int y){
    e[++top].dat=y,e[top].nxt=e[x].nxt;
    e[x].nxt=&e[top];
    e[++top].dat=x,e[top].nxt=e[y].nxt;
    e[y].nxt=&e[top];
}
void dfs(int x,int d){
    vis[x]=true,deep[x]=d,ans+=(1-d);
    for(edge_t* k=e[x].nxt;k!=NULL;k=k->nxt){
        if(!vis[k->dat])p[k->dat][0]=x,dfs(k->dat,d+1);
    }
}
inline int lca(int x,int y){
    if(deep[x]>deep[y])swap(x,y);
    int f=deep[y]-deep[x];
    for(int i=0;(1<<i)<=f;i++)
        if((1<<i)&f)y=p[y][i];
    if(x!=y){
        for(int i=(int)log2(131072);i>=0;i--)
            if(p[x][i]!=p[y][i])
                x=p[x][i],y=p[y][i];
        x=p[x][0];
    }
    return x;
}
int main(){
    freopen("tingfeng.in","r",stdin);
    freopen("tingfeng.out","w",stdout);
    scanf("%d%d%d",&n,&m,&c);
    top=n;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<n;i++)
        scanf("%d%d",&tx,&ty),add_edge(tx,ty);
    dfs(1,0);
    for(int j=1;(1<<j)<=n;j++)
        for(int i=1;i<=n;i++)
            p[i][j]=p[p[i][j-1]][j-1];
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&tx,&ty,&tz);
        ans+=((deep[tx]+deep[ty]-(deep[lca(tx,ty)]*2))*1ULL*tz);
    }
    printf("%llu\n",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}