//Luogu P1268
//Powered by Inv.
//2017/3/1 17:11
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define N 1100
using namespace std;
int n,m[N][N];
void solve(){
    int ans=m[1][2];
    for(int i=3;i<=n;i++){
        int rec=0x3f3f3f3f;
        for(int j=1;j<i;j++){
            rec=min(rec,(m[1][i]+m[j][i]-m[1][j])/2);
        }
        ans+=rec;
    }
    printf("%d\n",ans);
}
void init(){
    int minl=0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            scanf("%d",&m[i][j]);
            m[j][i]=m[i][j];
        }
    }
}
int main(){
    while(scanf("%d",&n)&&(n!=0)){
        init();
        solve();
    }
    system("pause");
    return 0;
}