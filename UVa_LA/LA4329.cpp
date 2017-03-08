#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
#define N 131072
int a[N],c[N],d[N],t1[N],t2[N],n;
inline int lowbit(int x){
    return x&(-x);
}
void add(int x,int s,int l[]){
    for(int i=x;i<=N;i+=lowbit(i)){
        l[i]+=s;
    }
}
int tot(int x,int l[]){
    int ans=0;
    for(int i=x;i>0;i-=lowbit(i)){
        ans+=l[i];
    }
    return ans;
}
int main(){
    int cases;
    scanf("%d",&cases);
    while(cases--){
        memset(t1,0,sizeof(t1));
        memset(t2,0,sizeof(t2));
        memset(a,0,sizeof(a));
        memset(c,0,sizeof(c));
        memset(d,0,sizeof(d));
        unsigned long long rec=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            t1[i]=tot(a[i],c);
            add(a[i],1,c);
        }
        for(int i=n;i>=1;i--){
            t2[i]=tot(a[i],d);
            add(a[i],1,d);
        }
        for(int i=2;i<n;i++){
            rec+=(t1[i]*(n-t2[i]-i)+(i-t1[i]-1)*t2[i]);
        }
        printf("%lld\n",rec);
    }
    system("pause");
    return 0;
}