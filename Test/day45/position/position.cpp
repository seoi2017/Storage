#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	freopen("position.in","r",stdin);
	freopen("position.out","w",stdout);
	int T=1;
	scanf("%d",&T);
	while(T--){
		long long n,m;
		scanf("%lld%lld",&n,&m);
		if (m==0){
			if (n==1) puts("1");
			else puts("-1");
			continue;
		}
		long long a,b,l=1,r=1000000000000000000LL;
		while(m--){
			scanf("%lld%lld",&a,&b);
			--a;
			--b;
			if (a<b) l=r+1;
			else{
				if (b!=0) r=min(a/b,r);
				l=max(l,a/(b+1)+1);
			}
		}
		if (l<=r&&(n-1)/l==(n-1)/r) printf("%lld\n",(n-1)/l+1);
		else puts("-1");
	}
	return 0;
}
