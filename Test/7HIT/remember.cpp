#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<map>
using namespace std;
int n,m,c[32][32],v[32][32],cv[32][32],cnt[32],top=0,px[512],mn=0x3f3f3f3f;
char tmp;
map<int,int> ind[32];
long long ans=0LL;
int main(){
    freopen("remember.in","r",stdin);
    freopen("remember.out","w",stdout);
    scanf("%d%d\n",&n,&m);
    for(int i=1;i<=n;i++,scanf("\n"))
        for(int j=1;j<=m;j++){
            scanf("%c",&tmp),c[i][j]=tmp-'a'+1;
            if(ind[j].find(c[i][j])==ind[j].end())
                ind[j][c[i][j]]=1;
            else ind[j][c[i][j]]++;
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&v[i][j]),cv[j][i]=v[i][j];
    for(int j=1;j<=m;j++){
        for(map<int,int>::iterator it=ind[j].begin();it!=ind[j].end();it++){
            cnt[j]+=it->second-1;
            mn=min(mn,it->second);
        }
    }
    for(int j=1;j<=m;j++){
        sort(cv[j]+1,cv[j]+1+n);
    }
    for(int j=1;j<=m;j++){
        for(int i=1;i<=cnt[j];i++){
            px[++top]=cv[j][i];
        }
    }
    sort(px+1,px+1+top);
    for(int i=1;i<=min(mn,n-1);i++)
        ans+=px[i]*1LL;
    printf("%lld\n",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}