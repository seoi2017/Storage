#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define mo 1000000007
#define N 10000000
using namespace std;
typedef long long ll_t;
ll_t gen,n,ans,divs[N+5];
int miu[N+5],prime[N/5],cur[N+5];
bool pd[N+5];
inline void solve(){
    for(int D=1;D<=gen;D++){
        int m=n/D/D,di=1,dtmp=0;
        while(di<=m){
            int x=m/di,dj=m/x;
            if(x<=N)dtmp=(dtmp+divs[x]*(dj-di+1)%mo)%mo;
            else{
                int i=1,itmp=0;
                while(i<x){
                    int y=x/i,j=x/y;
                    itmp=(itmp+(j-i+1)*y%mo)%mo;
                    i=j+1;
                }
                dtmp=(dtmp+itmp*(dj-di+1)%mo)%mo;
            }
            di=dj+1;
        }
        ans=((ll_t)ans+miu[D]*dtmp+mo)%mo;
    }
}
inline void init(){
    miu[1]=1;
    divs[1]=1;
    int i;
    for(i=2;i<=N;i++){
        if(!pd[i]){
            prime[++prime[0]]=i;
            miu[i]=-1;
            divs[i]=1;
            cur[i]=1;
        }
        for(int j=1;j<=prime[0];j++){
            if(i>N/prime[j])break;
            int t=i*prime[j];
            pd[t]=1;
            miu[t]=-miu[i];
            divs[t]=divs[i];
            if(i%prime[j]==0){
                cur[t]=cur[i]+1;
                miu[t]=0;
                break;
            }
            divs[t]=(ll_t)divs[t]*(cur[i]+1)%mo;
            cur[t]=1;
        }
    }
    for(int i=2;i<=N;i++){
        divs[i]=((ll_t)divs[i]*(cur[i]+1)%mo+divs[i-1])%mo;
    }
}
int main(){
    freopen("ra.in","r",stdin);
    freopen("ra.out","w",stdout);
    scanf("%lld",&n);
    gen=trunc(sqrt(n));
    init(),solve(),n%=mo;
    printf("%lld",(n*n%mo-ans+mo)%mo);
    fclose(stdin);
    fclose(stdout);
    return 0;
}