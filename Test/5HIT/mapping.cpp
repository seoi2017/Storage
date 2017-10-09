#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<map>
using namespace std;
int T,n,m;
bool can;
map<int,int> f,g,h,cnt,ind;
int main(){
    freopen("mapping.in","r",stdin);
    freopen("mapping.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        m=0,can=true;
        cnt.clear();
        f.clear();
        g.clear();
        h.clear();
        ind.clear();
        for(int i=1;i<=n;i++){
            scanf("%d",&f[i]);
            if(f[i]>n)can=false;
            if(cnt.find(f[i])==cnt.end())
                m++;
            cnt[f[i]]=1;
        }
        if(!can)goto end;
        for(int i=1;i<=n;i++){
            if(f.find(f[i])!=f.end() && f[f[i]]!=f[i]){
                can=false;
                break;
            }
        }
        if(!can)goto end;
        for(int i=1,j=1;i<=n,j<=m;i++)
            if(cnt.find(i)!=cnt.end())
                ind[i]=j,h[j++]=i;
        for(int i=1;i<=n;i++)
            g[i]=ind[f[i]];
        printf("%d\n",m);
        for(int i=1;i<=n;i++)
            printf("%d ",g[i]);
        printf("\n");
        for(int i=1;i<=m;i++)
            printf("%d ",h[i]);
        printf("\n");
        if(false){
            end:;
            printf("-1\n");
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*
6
5
1 2 1 2 1
6
4 4 4 4 4 4 
7
5 7 5 4 5 5 3 
9
1 9 4 4 1 6 6 8 9 
7
7 3 1 3 1 7 7 
10
1 9 10 2 4 9 6 6 10 10 
*/