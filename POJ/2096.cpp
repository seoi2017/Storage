#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define MX 1007
using namespace std;
int n,s;
double dp[MX][MX];
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d%d",&n,&s);
    dp[n][s]=0.0;
    double sn=n*s;
    for(int i=n;i>=0;i--){
        for(int j=s;j>=0;j--){
            if(i!=n||j!=s){
                dp[i][j]=(sn+(n-i)*(s-j)*dp[i+1][j+1]+(n-i)*j*dp[i+1][j]+i*(s-j)*dp[i][j+1])/(sn-i*j);
            }
        }
    }
    printf("%.4f\n",dp[0][0]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}