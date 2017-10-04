#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
unsigned long long a[1000007],ans;
int T,n,vis[512];
char str[1000007];
int main(){
    scanf("%d",&T);
    while(T--){
        memset(vis,0,sizeof(vis));
        scanf("%d%s",&n,str);
        for(int i=0;i<n;i++)
            vis[str[i]]++;
        a[1]=ans=1;
        for(int i=2;i<=n;i++)
            a[i]=a[i-1]*i,ans+=(a[i]*1ULL);
        for(int i=0;i<512;i++)
            if(vis[i]>1)ans=ans-a[vis[i]]+1ULL;
        (ans+n)%2ULL==0ULL?printf("Lose\n"):printf("Win\n");
    }
    system("pause");
    return 0;
}