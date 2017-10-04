#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=503;
int n,m,ans=0;
int map[N][N]={0};
void input(){
    cin>>n>>m;
    char x;
    int y;
    for(int i=1;i<=m;i++){
        cin>>x>>y;
        map[x-'A'+1][y]=1;
        cout<<y<<x<<endl;
    }
}
int dfs(int x,int y,char to){
    map[x][y]=2;
    switch (to){
        case 'D':down();
        case 'U':up();
        case 'L':left();
        case 'R':right();
    }
}
void solve(){
    //to right
    int ans1=dfs(1,1,'R');
    //to down
    int ans2=dfs(1,1,'D');
    //ans
    ans=max(ans1.ans2);
}
void output(){
    cout<<ans<<endl;
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios::sync_with_stdio(false);
    input();
    solve();
    output();
    fclose(stdin);
    fclose(stdout);
    return 0;
}