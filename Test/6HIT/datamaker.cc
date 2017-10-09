#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int seed,n,m,tmp,a[200007];
int main(){
    freopen("seed.txt","r",stdin);
    freopen("xor.in","w",stdout);
    scanf("%d",&seed);
    fclose(stdin);
    srand(seed);
    printf("%d %d\n",n=rand()%10+1,m=rand()%20+1);
    for(int i=1;i<=n;i++)
        printf("%d ",a[i]=rand()%100+1);
    printf("\n");
    for(int i=1;i<=m;i++){
        tmp=rand()%3+1;
        if(tmp==1)printf("%d %d\n",tmp,rand()%100+1);
        else if(tmp==2 && n>0)printf("%d %d\n",tmp,rand()%n+1),n--;
        else if(tmp==3)printf("%d %d %d\n",tmp,rand()%n+1,rand()%n+1);
        else i--;
    }
    fclose(stdout);
    freopen("seed.txt","w",stdout);
    printf("%d\n",rand()<<16|rand());
    fclose(stdout);
    return 0;
}
