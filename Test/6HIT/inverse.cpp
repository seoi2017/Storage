#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll_t;
ll_t p;
void ExGCD(ll_t a,ll_t b,ll_t d,ll_t &x,ll_t &y){//扩展欧几里德
    if(!b)d=a,x=1,y=0;
    else ExGCD(b,a%b,d,y,x),y-=x*(a/b);
}
inline ll_t inv(ll_t a,ll_t b){//求模b意义下逆元
    ll_t x,y,d;
    ExGCD(a,b,d,x,y);
    return (x%b+b)%b;
}
int main()
{
    freopen("inverse.in", "r", stdin);
    freopen("inverse.out", "w", stdout);
    scanf("%lld", &p);
    printf();
    fclose(stdin);
    fclose(stdout);
    return 0;
}