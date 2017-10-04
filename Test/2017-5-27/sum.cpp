#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef unsigned long long ull_t;
const ull_t p=1000000007;
ull_t n;
int expow(ull_t x,ull_t y){
    ull_t z=1;
    while(y>0){
        if(y&1)z=(z*x)%p;
        y>>=1;
        x=(x*x)%p;
    }
    return z;
} 
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%llu",&n);
    printf("%llu\n",expow(2,n+1)-n-2);
    fclose(stdin);
    fclose(stdout);
    return 0;
}