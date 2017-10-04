#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
void input(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&e[i]);
    }
    for(int i=1;i<=k;i++){
        scanf("%d%d",&c[i],&p[i]);
        for(int j=1;j<=c[i];j++){
            scanf("%d",&d[i][j]);
        }
    }
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