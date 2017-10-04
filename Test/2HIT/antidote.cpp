#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
using namespace std;
int n,m,c,a[2007],b[2007],sol[2007],ans=0;
map<int,int> p,s;
inline bool cmp(int x){
    p.clear(),s.clear();
    for(int i=1;i<=m;i++){
        if(p.find(b[i])==p.end() && s.find(a[x+i-1])==s.end()){
            p[b[i]]=a[x+i-1],s[a[x+i-1]]=b[i];
            continue;
        }
        if(p[b[i]]!=a[x+i-1] || s[a[x+i-1]]!=b[i])
            return false;
    }
    return true;
}
int main(){
    freopen("antidote.in","r",stdin);
    freopen("antidote.out","w",stdout);
    scanf("%d%d%d",&n,&m,&c);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)
        scanf("%d",&b[i]);
    for(int i=1;i<=n-m+1;i++)
        if(cmp(i))sol[++ans]=i;
    printf("%d\n",ans);
    for(int i=1;i<ans;i++)
        printf("%d ",sol[i]);
    ans?printf("%d\n",sol[ans]):true;
    fclose(stdin);
    fclose(stdout);
    return 0;
}