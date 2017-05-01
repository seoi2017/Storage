#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#define N 1005
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> p_t;
int n,m,ans=INF,mp[N][N],viss[N][N],vise[N][N];
p_t st,et;
map<p_t,int> val;
vector<p_t> v;
inline bool judges(int x,int y){
    if(x>0 && y>0 && x<=n && y<=m && viss[x][y]==0 && mp[x][y]!=1 && mp[x][y]!=3)return true;
    else return false;
}
inline bool judgee(int x,int y){
    if(x>0 && y>0 && x<=n && y<=m && vise[x][y]==0 && mp[x][y]!=1 && mp[x][y]!=3)return true;
    else return false;
}
inline void bfss(){
    queue<p_t> q;
    q.push(st);
    viss[st.first][st.second]=1;
    while(!q.empty()){
        p_t now=q.front();
        q.pop();
        int x=now.first,y=now.second,vis=viss[x][y];
        if(mp[x][y]==4)val[now]+=vis-1;
        if(judges(x-1,y))viss[x-1][y]=vis+1,q.push(make_pair(x-1,y));
        if(judges(x+1,y))viss[x+1][y]=vis+1,q.push(make_pair(x+1,y));
        if(judges(x,y-1))viss[x][y-1]=vis+1,q.push(make_pair(x,y-1));
        if(judges(x,y+1))viss[x][y+1]=vis+1,q.push(make_pair(x,y+1));
    }
}
inline void bfse(){
    queue<p_t> q;
    q.push(et);
    vise[et.first][et.second]=1;
    while(!q.empty()){
        p_t now=q.front();
        q.pop();
        int x=now.first,y=now.second,vis=vise[x][y];
        if(mp[x][y]==4)val[now]+=vis-1;
        if(judgee(x-1,y))vise[x-1][y]=vis+1,q.push(make_pair(x-1,y));
        if(judgee(x+1,y))vise[x+1][y]=vis+1,q.push(make_pair(x+1,y));
        if(judgee(x,y-1))vise[x][y-1]=vis+1,q.push(make_pair(x,y-1));
        if(judgee(x,y+1))vise[x][y+1]=vis+1,q.push(make_pair(x,y+1));
    }
}
inline void solve(){
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&mp[i][j]);
            if(mp[i][j]==2)st=make_pair(i,j);
            else if(mp[i][j]==3)et=make_pair(i,j);
            else if(mp[i][j]==4)v.push_back(make_pair(i,j));
        }
    }
    bfss();
    bfse();
    for(int i=0;i<v.size();i++){
        if(viss[v[i].first][v[i].second]>0 && vise[v[i].first][v[i].second]>0)ans=min(ans,val[v[i]]);
    }
    printf("%d\n",ans);
}
int main(){
    //freopen("change.in","r",stdin);
    //freopen("change.out","w",stdout);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    solve();
    fclose(stdin);
    fclose(stdout);
    return 0;
}