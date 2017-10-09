#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#define MOD 1000000007
using namespace std;
struct edge_t{
    int dat;
    edge_t* nxt;
}e[51007];
int n,top,tx,ty,es[5107];
bool vis[5107];
inline void add_edge(int x,int y){
    e[++top].dat=y,e[top].nxt=e[x].nxt,e[x].nxt=&e[top];
    e[++top].dat=x,e[top].nxt=e[y].nxt,e[y].nxt=&e[top];
}
bool dfs(int c,int t){
    vis[c]=true;
    if(c==t)return true;
    for(edge_t* k=e[c].nxt;k!=NULL;k=k->nxt){
        if(dfs(k->dat))return true;
    }
    return false;
}
void get_size(int c){
    es[c]=1;
    for(edge_t* k=e[c].nxt;k!=NULL;k=k->nxt){
        get_size(k->dat);
        es[c]+=es[k->dat];
    }
}
int get_ans(int c){
    if(vis[c]==false)return es[c];
    for(edge_t* k=e[c].nxt;k!=NULL;k=k->nxt){
        get_ans(k->data);
    }
}
int main(){
    freopen("journey.in","r",stdin);
    freopen("journey.out","w",stdout);
    scanf("%d",&n);
    top=n;
    for(int i=1;i<=n;i++)
        scanf("%d%d",&tx,&ty),add_edge(tx,ty);
    get_size(1);
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++){
            memset(vis,false,sizeof(vis));
            dfs(1,i),dfs(1,j);
            ans=(ans+get_ans(1))%MOD;
        }
    printf("%d\n",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}