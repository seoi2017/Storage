#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#define eps 1e-18
using namespace std;
int n;
double mt[315][315];
inline void print(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            printf("%.6lf ",mt[i][j]);
        printf("| %.6lf\n",mt[i][n+1]);
    }
    printf("\n");
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n+1;j++)
            scanf("%lf",&mt[i][j]);
    int i=1;
    for(int j=1;i<=n,j<=n;i++,j++){
        int index=i;
        for(int k=i;k<=n;k++)
            if(fabs(mt[k][j]-mt[index][j])>eps)
                index=k;
        if(fabs(mt[index][j])<eps){
            i--;
            continue;
        }
        if(index!=i)
            for(int k=j;k<=n+1;k++)
                swap(mt[index][k],mt[i][k]);
        for(int k=1;k<=n;k++)
            if(fabs(mt[k][j])>eps && k!=j){
                double t=mt[k][j];
                for(int l=j;l<=n+1;l++)
                    mt[k][l]=mt[k][l]-t/mt[i][j]*mt[i][l];
            }
        print();
    }
    for(int j=i;j<=n;j++)
        if(fabs(mt[j][n+1])>eps)
            goto many;
    if(i<n+1)
        goto none;
    for(int j=1;j<n;j++)
        printf("%.6lf\n",mt[j][n+1]/mt[j][j]==-0.0?0.0:mt[j][n+1]/mt[j][j]);
    printf("%.6lf",mt[n][n+1]/mt[n][n]==-0.0?0.0:mt[n][n+1]/mt[n][n]);
    if(false){
        many:;
        printf("Many Solutions");
    }
    if(false){
        none:;
        printf("No Solution");
    }
    system("pause");
    return 0;
}
/*
6
1 4 2 3 5 6 2
2 3 4 1 8 6 2
2 0 6 0 2 1 4
4 5 0 5 2 1 5
7 8 3 0 2 6 8
-12 435 2 -213 123 44 202
*/