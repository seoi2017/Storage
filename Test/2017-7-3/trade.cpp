#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
#define MX 10007
int n,a[MX],f[MX][MX/2+1],cnt=0;
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    while(scanf("%d",&n)!=EOF){
        cnt++;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        //D1:第几天
        //D2:持有几股股票
        //f[D1][D2]:利润最大值
        //Goal:f[n][0]
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                f[i][j]=f[i][j]=-2147483640;
        f[0][0]=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=(i>=n/2+1?abs(n-i):i);j++){
                f[i][j]=max(f[i-1][j],max(f[i-1][j-1]-a[i],f[i-1][j+1]+a[i]));
                //printf("%d ",f[i][j]);
            }
            //printf("\n");
        }
        printf("Case #%d: %d\n",cnt,f[n][0]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}