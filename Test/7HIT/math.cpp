#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#define N 1000007
using namespace std;
int phi[N],n,tmp;
void init(){
    for(int i=1;i<N;i++)
        phi[i]=i;
    for(int i=2;i<N;i++)  
        if(i==phi[i])
            for(int j=i;j<N;j+=i)
                phi[j]=(phi[j]/i)*(i-1);
} 
int main(){
    freopen("math.in","r",stdin);
    freopen("math.out","w",stdout);
    init();
    scanf("%d",&n);
    for(int ca=1;ca<=n;ca++){
        int ans=0;
        scanf("%d",&tmp);
        for(int i=1;i<=tmp;i++){
            for(int j=1;j<=i;j++){
                if(i%j==0){
                    int res=0;
                    for(int k=1;k<=i/j;k++){
                        res+=phi[k]*(i/(j*k));
                    }
                    ans+=phi[j]*res;
                }
            }
        }
        printf("%d\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}