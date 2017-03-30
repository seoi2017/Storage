#include<bits/stdc++.h>
#define N 310
using namespace std;
int n,k,x,s[N][N],a[N],hang[N],lie[N],sum=0,tot=0;
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d%d%d",&n,&k,&x);
    for(int i=1;i<=n;i++){
        a[i]=i;
        for(int j=1;j<=n;j++){
            s[i][j]=-1*(i-j);
            printf("[%d]",s[i][j]);
        }
        printf("\n");
    }
    for(int i=1;i<n;i++){
        printf("%d ",i-a[i]);
    }
    printf("%d\n",n-a[n]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}