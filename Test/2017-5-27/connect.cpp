#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cmath>
#define N 1000003
using namespace std;
int fa[N];
int findfa(int x){
    return fa[x]==x?x:fa[x]=findfa(fa[x]);
}
bool bing(int x,int y){
    int fx=findfa(x),fy=findfa(y);
    if(fx==fy)return false;
    fa[fy]=fx;
    return true;
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++){
        scanf("%d%d",&a,&b);
        bing(a,b);
    }
    scanf("%d",&q);
    for(int i=1;i<=q;i++){
        scanf("%d%d",&a,&b);
        if(!bing(a,b))printf("-1\n");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}