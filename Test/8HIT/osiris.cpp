#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int n,a,b,c,x,y,z,can;
inline int pd(int t){
    return t>0?t/2:t;
}
int main(){
    freopen("osiris.in","r",stdin);
    freopen("osiris.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d%d%d%d",&a,&b,&c,&x,&y,&z);
        can=pd(a-x)+pd(b-y)+pd(c-z);
        can>=0?printf("YES\n"):printf("NO\n");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}