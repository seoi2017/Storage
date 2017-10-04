#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
    }
    solve();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
inline void solve(int c){
    queue<int> Q;
    Q.push(c);
    vis[c]=1;
    while(!Q.empty()){
        int x=Q.front();
        Q.pop();
        vis[x]=0;
        for(node_t* k=p[x].nxt;k!=NULL;k=k->nxt){
            
        }
    }
}