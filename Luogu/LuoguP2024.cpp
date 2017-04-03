#include<bits/stdc++.h>//Accepted!
using namespace std;
const int N=150010;
int fa[N]={0},ans=0,n,k;//FA:i for same,i+n for eat,i+2*n for be eaten;
inline int findfa(int x){
    return fa[x]==x?x:fa[x]=findfa(fa[x]);
}
inline void bing(int x,int y){
    fa[y]=x;
}
bool judge(int command,int x,int y){
    if(x>n || y>n)return false;
    if(command==1){
        if(findfa(x)==findfa(y+n) || findfa(x)==findfa(y+n+n))return false;
        bing(findfa(x),findfa(y)),bing(findfa(x+n),findfa(y+n)),bing(findfa(x+n+n),findfa(y+n+n));
    }
    else if(command==2){
        if(findfa(x)==findfa(y) || findfa(x+n+n)==findfa(y))return false;
        bing(findfa(x),findfa(y+n+n)),bing(findfa(x+n),findfa(y)),bing(findfa(x+n+n),findfa(y+n));
    }
    return true;
}
void solve(){
    int x,y,z;scanf("%d%d",&n,&k);
    for(int i=1;i<=n+n+n;i++)fa[i]=i;
    for(int i=1;i<=k;i++)scanf("%d%d%d",&x,&y,&z),judge(x,y,z)?ans=ans:ans++;
    printf("%d\n",ans);
}
int main(){
    freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
    solve();
    fclose(stdin),fclose(stdout);
    return 0;
}