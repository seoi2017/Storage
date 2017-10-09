#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#define MOD 1000000007
using namespace std;
char str[2048];
int T,n,k;
long long ans;
int dp[2007][2007][2];
int main(){
    freopen("words.in","r",stdin);
    freopen("words.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d%d\n",&n,&k);
        for(int i=1;i<=n;i++)
            scanf("%c",&str[i]);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                
        printf("%lld\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}