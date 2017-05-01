#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define N 305
using namespace std;
int n,L[N][N],S[N][N];
void sou(int x,int y){
    int ttt=sqrt();
    for(int )
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    //freopen("cholesky.in","r",stdin);
    //freopen("cholesky.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&L[i][j]);
        }
    }
    S[1][1]=sqrt(L[1][1]);
    for(int i=2;i<=n;i++){
        S[1][i]=L[1][i]/S[1][1];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++){
            sou(i,j);
        }
    }
    /*
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&L2[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("[");
            for(int k=1;k<n;k++){
                printf("%d+",L[i][k]*L2[k][j]);
            }
            printf("%d]",L[i][n]*L2[n][j]);
        }
        printf("\n");
    }
    */
    fclose(stdin);
    fclose(stdout);
    return 0;
}