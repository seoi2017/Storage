#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

char s[1000100];
int cnt[100];
int n;

inline int calc(int a){
	int ret=0;
	while(a){
		ret+=a/2;
		a>>=1;
	}
	return ret;
}

int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int T=0;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		scanf("%s",s);
		memset(cnt,0,sizeof(cnt));
		for (int i=0;i<n;++i) if (s[i]>='a'&&s[i]<='z') ++cnt[s[i]-'a'];
		else ++cnt[s[i]-'A'+26];
		int ans=0;
		ans+=calc(n);
		for (int i=0;i<52;++i) if (cnt[i]) ans-=calc(cnt[i]);
		// printf("n=%d, ans=%d\n",n,ans);
		if (n&1) puts("Win");
		else if (ans) puts("Win");
		else puts("Lose");
	}
	return 0;
}
