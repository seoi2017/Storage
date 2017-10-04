#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<queue>
#define N 1003
#define M 100003
#define INF 0x3f3f3f3f
using namespace std;
struct edge_t{
    int dat,lng;
    edge_t *nxt;
}e[N+M+1];
int top=0,ans[N],n,m;
bool inq[N]={0},vis[N]={0};
inline void ins(int a,int b,int l){
    e[++top].dat=b,e[top].lng=l;
    e[top].nxt=e[a].nxt;
    e[a].nxt=&e[top];
}
inline void input(){
    scanf("%d%d",&n,&m);
    int ta,tb,tl;
    top=n;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&ta,&tb,&tl);
        ins(ta,tb,tl),ins(tb,ta,tl);
        ans[i]=INF;
    }
    ans[1]=0;
}
inline void solve(){
    queue<int> Q;
    Q.push(1);
    inq[1]=true;
    while(!Q.empty()){
        int x=Q.front();
        Q.pop();
        vis[x]=true;
        for(edge_t *k=e[x].nxt;k!=NULL;k=k->nxt){
            if(!vis[k->dat]){
                ans[k->dat]=min(ans[x]+k->lng,ans[k->dat]);
                if(!inq[k->dat])Q.push(k->dat),inq[k->dat]=true;
            }
        }
    }
    printf("%d\n",ans[n]);
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    input();
    solve();
    fclose(stdin);
    fclose(stdout);
    return 0;
}