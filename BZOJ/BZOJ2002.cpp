#include<cstdlib>//Accepted!
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int belong[200100],st[500],f[200100],jump[200100],k[200100];
int n,m,ans,tot;
int total(int x){
    int ans=0;
    while(x<n){
        ans+=f[x];
        x=jump[x];
    }
    return ans;
}
void gai(int x,int s){
    k[x]=s;
    for(int i=x;i>=st[belong[x]];i--){
        if(i+k[i]>=st[belong[i]+1])f[i]=1,jump[i]=i+k[i];
        else f[i]=f[i+k[i]]+1,jump[i]=jump[i+k[i]];
    }
}
int main(){
    scanf("%d",&n);
    int r=sqrt(n);
    int cnt=0,tot=1;
    for(int i=0;i<=n-1;i++){
        cnt++;
        if(cnt==r+1)cnt=1,tot++,st[tot]=i;
        belong[i]=tot;
        scanf("%d",&m);
        k[i]=m;
    }
    belong[n]=tot+1;
    for(int i=n-1;i>=1;i--){
        if(i+k[i]>=st[belong[i]+1])f[i]=1,jump[i]=i+k[i];
        else f[i]=f[i+k[i]]+1,jump[i]=jump[i+k[i]];
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        int command,x,y;
        scanf("%d",&command);
        if(command==1){
            scanf("%d",&x);
            printf("%d\n",total(x));
        }
        else if(command==2){
            scanf("%d%d",&x,&y);
            gai(x,y);
        }
    }
    system("pause");
    return 0;
}