#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
#define N 200050
using namespace std;
long long _N,Q,S,T,ans=0,a[N],c[N];
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%lld%lld%lld%lld",&_N,&Q,&S,&T);
    for(long long i=0;i<=_N;i++){
        scanf("%lld",&a[i]);
        if(i!=0){
            c[i]=a[i-1]-a[i];
            if(c[i]>0){
                ans+=T*abs(c[i]);
            }
            else ans-=S*abs(c[i]);
        }
    }
    for(long long i=1;i<=Q;i++){
        long long x,y,z;
        scanf("%lld%lld%lld",&x,&y,&z);
        if(c[x]>0){
            ans-=T*abs(c[x]);
        }
        else ans+=S*abs(c[x]);
        if(y!=_N){
            if(c[y+1]>0)ans-=T*abs(c[y+1]);
            else ans+=S*abs(c[y+1]);
        }
        c[x]-=z;
        if(y!=_N){
            c[y+1]+=z;
        }
        if(c[x]>0)ans+=T*abs(c[x]);
        else ans-=S*abs(c[x]);
        if(y!=_N){
            if(c[y+1]>0)ans+=T*abs(c[y+1]);
            else ans-=S*abs(c[y+1]);
        }
        printf("%lld\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}