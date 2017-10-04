#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=200003,MAX=500000003;
int n,m,t[N],ans=0;
void input(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&t[i]);
    }
    sort(t+1,t+1+n);
}
void output(){
    printf("%d\n",ans);
}
void solve(){
    if(n<=m){
        ans=t[n];
        return;
    }
    int tid=n-(m-(n>>1));
    int mid=tid>>1;
    for(int i=mid+1,j=mid;i<=tid,j>=1;i++,j--){
        ans=max(ans,t[i]+t[j]);
    }
    for(int i=tid+1;i<=n;i++){
        ans=max(ans,t[i]);
    }
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    //freopen("h.in","r",stdin);
    //freopen("h.out","w",stdout);
    input();
    solve();
    output();
    fclose(stdin);
    fclose(stdout);
    return 0;
}