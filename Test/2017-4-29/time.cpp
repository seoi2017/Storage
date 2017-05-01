#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#define N 1000005
#define M 1000000000
using namespace std;
int n,dp[N];
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    //freopen("time.in","r",stdin);
    //freopen("time.out","w",stdout);
    scanf("%d",&n);
    if(n==1){
        printf("1\n");
        return 0;
    }
    dp[1]=1;
    for(int i=2;i<=n;i++){
        if(i&1)dp[i]=dp[i-1];
        else dp[i]=(dp[i>>1]+dp[i-1])%M;
    }
    printf("%d\n",dp[n]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}