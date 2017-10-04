//Accepted!
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll_t;
ll_t k,n[33],f[33][33][33][33][33];
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    while(scanf("%lld",&k) && k!=0){
        f[0][0][0][0][0]=1;
        memset(n,0,sizeof(n));
        for(int i=1;i<=k;i++)scanf("%lld",&n[i]);
        for(int i=0;i<=n[1];i++)
            for(int j=0;j<=n[2];j++)
                for(int k=0;k<=n[3];k++)
                    for(int l=0;l<=n[4];l++)
                        for(int m=0;m<=n[5];m++){
                            ll_t &now=f[i][j][k][l][m];
                            if(i+j+k+l+m)now=0;
                            if(i>0)now+=f[i-1][j][k][l][m];
                            if(j>0 && i>=j)now+=f[i][j-1][k][l][m];
                            if(k>0 && j>=k)now+=f[i][j][k-1][l][m];
                            if(l>0 && k>=l)now+=f[i][j][k][l-1][m];
                            if(m>0 && l>=m)now+=f[i][j][k][l][m-1];
                        }
        printf("%lld\n",f[n[1]][n[2]][n[3]][n[4]][n[5]]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}