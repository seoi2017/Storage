#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#define MX 0x3F3F3F3F3F3F3F3F
using namespace std;
struct edge_t{
    int dat,len;
    edge_t* nxt;
}e[1260007];
int n,m,s,t,top=0,ts,te,tl;
long long dis[100007];
bool vis[100007];
inline void add_edge(int x,int y,int l){
    e[++top].dat=y,e[top].len=l;
    e[top].nxt=e[x].nxt;
    e[x].nxt=&e[top];
}
inline void spfa(int c){
    queue<int> Q;
    Q.push(c);
    vis[c]=true;
    dis[c]=0LL;
    while(!Q.empty()){
        int x=Q.front();
        Q.pop();
        vis[x]=false;
        for(edge_t* k=e[x].nxt;k!=NULL;k=k->nxt){
            if(dis[k->dat]>dis[x]+(k->len)*1LL){
                dis[k->dat]=dis[x]+(k->len)*1LL;
                if(!vis[k->dat]){
                    Q.push(k->dat);
                    vis[k->dat]=true;
                }
            }
        }
    }
}
int main(){
    scanf("%d%d%d%d",&n,&m,&s,&t);
    top=n;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&ts,&te,&tl);
        add_edge(ts,te,tl);
        add_edge(te,ts,tl);
    }
    for(int i=1;i<=n;i++)
        dis[i]=MX;
    spfa(s);
    //for(int i=1;i<=n;i++)
    //    printf("%lld ",dis[i]==MX?2147483647:dis[i]);
    printf("%lld\n",dis[t]==MX?-1:dis[t]);
    system("pause");
    return 0;
}