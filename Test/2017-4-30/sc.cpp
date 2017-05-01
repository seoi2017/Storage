#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define N 613
#define M 813
#define INF 0x3f3f3f3f
using namespace std;
char P3[32];
int n,m,C255,R[N][M],G[N][M],B[N][M],E[N][M],goal,icdel,icdelp=INF,ded[N][M],dp[N][M],_m;
inline void solve(){
    goal=m*2/3,_m=m;
    while(_m>goal){
        icdelp=INF;
        for(int i=_m;i>=1;i--){
            if(!ded[n][i] && dp[n][i]<=icdelp)icdel=i,icdelp=dp[n][i];
        }
        for(int j=icdel;j<=_m;j++){
            R[n][j]=R[n][j+1];
            G[n][j]=G[n][j+1];
            B[n][j]=B[n][j+1];
        }
        for(int i=n;i>1;i--){
            int tmp=icdel;
            icdelp=INF;
            if(tmp!=_m && dp[i-1][tmp+1]<=icdelp)icdel=tmp+1,icdelp=dp[i-1][tmp+1];
            if(dp[i-1][tmp]<=icdelp)icdel=tmp,icdelp=dp[i-1][tmp];
            if(tmp!=1 && dp[i-1][tmp-1]<=icdelp)icdel=tmp-1,icdelp=dp[i-1][tmp-1];
            for(int j=icdel;j<=_m;j++){
                R[i-1][j]=R[i-1][j+1];
                G[i-1][j]=G[i-1][j+1];
                B[i-1][j]=B[i-1][j+1];
            }
        }
        _m--;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=_m;j++){
                E[i][j]=(abs(R[i][j]-R[i][j-1])+abs(R[i][j]-R[i-1][j])+abs(G[i][j]-G[i-1][j])+abs(G[i][j]-G[i][j-1])+abs(B[i][j]-B[i-1][j])+abs(B[i][j]-B[i][j-1]))/3;
                if(j!=1 && j!=m)dp[i][j]=E[i][j]+min(min(dp[i-1][j-1],dp[i-1][j+1]),dp[i-1][j]);
                else if(j==1)dp[i][j]=E[i][j]+min(dp[i-1][j],dp[i-1][j+1]);
                else if(j==m)dp[i][j]=E[i][j]+min(dp[i-1][j-1],dp[i-1][j]);
            }
        }
    }
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    //freopen("input.ppm","r",stdin);
    //froepen("output.ppm","w",stdout);
    scanf("%s",P3);
    scanf("%d%d",&m,&n);
    scanf("%d",&C255);
    for(int i=1;i<=n;i++)R[i][0]=B[i][0]=G[i][0]=255;
    for(int i=1;i<=m;i++)R[0][i]=B[0][i]=G[0][i]=255;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d%d%d",&R[i][j],&G[i][j],&B[i][j]);
            E[i][j]=(abs(R[i][j]-R[i][j-1])+abs(R[i][j]-R[i-1][j])+abs(G[i][j]-G[i-1][j])+abs(G[i][j]-G[i][j-1])+abs(B[i][j]-B[i-1][j])+abs(B[i][j]-B[i][j-1]))/3;
            if(j!=1 && j!=m)dp[i][j]=E[i][j]+min(min(dp[i-1][j-1],dp[i-1][j+1]),dp[i-1][j]);
            else if(j==1)dp[i][j]=E[i][j]+min(dp[i-1][j],dp[i-1][j+1]);
            else if(j==m)dp[i][j]=E[i][j]+min(dp[i-1][j-1],dp[i-1][j]);
        }
    }
    solve();
    printf("%s\n",P3);
    printf("%d %d\n",goal,n);
    printf("%d\n",C255);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=_m;j++){
            if(!ded[i][j])printf("%d %d %d ",R[i][j],G[i][j],B[i][j]);
        }
        printf("\n");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
//O(n+m+nm+2/3m*(n+m))
//600+800+(600*800)+(800*2*(600+800)/3)