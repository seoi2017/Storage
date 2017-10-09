#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<map>
#include<vector>
#define xt first
#define yt second
using namespace std;
int n,m,k,tx,ty,top,vis[100007];
struct edge_t{
    int dat;
    edge_t *nxt;
}p[200007];
map<int,vector<pair<int,int> > > ques;
map<int,int> ans;
map<int,map<int,int> >col;
inline void add_edge(int x,int y){
    p[++top].dat=y,p[top].nxt=p[x].nxt,p[x].nxt=&p[top];
}
void solve(int x){
    vis[x]=true;
    for(edge_t *k=p[x].nxt;k!=NULL;k=k->nxt){
        if(!vis[k->dat])solve(k->dat);
        for(map<int,int>::iterator i=col[k->dat].begin();i!=col[k->dat].end();i++)
            col[x][i->xt]+=col[k->dat][i->xt];
    }
    for(int i=0;i<ques[x].size();i++)
        ans[ques[x][i].xt]=col[x][ques[x][i].yt];
}
int main(){
    freopen("kind.in","r",stdin);
    freopen("kind.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    top=n;
    for(int i=1;i<=n;i++){
        scanf("%d",&tx);
        col[i][tx]++;
    }
    for(int i=1;i<n;i++){
        scanf("%d%d",&tx,&ty);
        add_edge(tx,ty);
    }
    for(int i=1;i<=m;i++){
        scanf("%d%d",&tx,&ty);
        ques[tx].push_back(make_pair(i,ty));
    }
    solve(1);
    for(int i=1;i<=m;i++)
        printf("%d\n",ans[i]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}