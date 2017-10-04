#include<iostream>
//Force:30
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#define P 1000000007
#define NM 1000007
using namespace std;
int n,m,k,tmp1,tmp2,ans;
bool dis[1007][1007];
void dfs(int dep,int res){
	if(dep==n){
		ans=(ans+res)%P;
		return;
	}
	for(int i=1;i<=m;i++){
		if(dis[dep][i])continue;
		dfs(dep+1,res*i%P);
	}
}
int main(){
    freopen("mul.in","r",stdin);
    freopen("mul.out","w",stdout);
    scanf("%d%d%d",&m,&n,&k);
    for(int i=1;i<=k;i++){
    	scanf("%d%d",&tmp1,&tmp2);
    	dis[tmp1-1][tmp2]=true;
	}
	dfs(0,1);
	printf("%d\n",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
