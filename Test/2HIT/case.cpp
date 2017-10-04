#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#define a first
#define t second
using namespace std;
int c,h,b;
long long ans;
pair<int,int> x[1007];
inline bool cmp(pair<int,int> ta,pair<int,int> tb){
    return ta.a==tb.a?ta.t<tb.t:ta.a<tb.a;
}
int main(){
    freopen("case.in","r",stdin);
    freopen("case.out","w",stdout);
    scanf("%d%d%d",&c,&h,&b);
    for(int i=1;i<=c;i++)
        scanf("%d%d",&x[i].a,&x[i].t);
    sort(x+1,x+1+c,cmp);
    for(int i=1;i<=c;i++)
        ans+=(max(1,x[i].t-x[i-1].t));
    ans+=h-b;
    printf("%lld\n",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}