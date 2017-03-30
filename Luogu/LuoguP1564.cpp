#include<bits/stdc++.h>//Accepted!
#define INF 5000
#define N 3000
using namespace std;
int n,m,a,s[N],f[N];
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a);
        if(a==2)s[i]=s[i-1]-1;
        if(a==1)s[i]=s[i-1]+1;
    }
    for(int i=1;i<=n;i++){
        f[i]=INF;
        for(int j=0;j<i;j++){
            if(abs(s[i]-s[j])==i-j || abs(s[i]-s[j])<=m)f[i]=min(f[i],f[j]+1);
        }
    }
    printf("%d\n",f[n]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}