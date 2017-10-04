#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define MX 100007
using namespace std;
struct edge{
	int dat;
	edge* nxt;
}e[MX*10];
int n,m,s[MX],k[MX],tmp,tmp2,top;
bool tag[MX];
inline void add_edge(int st,int et){
	e[++top].nxt=e[st].nxt;
	e[st].nxt=&e[top];
	e[top].dat=et;
}
unsigned long long dfs(int now){
	unsigned long long tot=0LLU;
	for(edge* t=e[now].nxt;t!=NULL;t=t->nxt){
		tot+=dfs(t->dat);
	}
	if(tag[now])return k[now];
	return tot==0LLU?min(k[now],s[now]):min(k[now]*1LLU,tot+s[now]);
}
int main(){
	freopen("monster.in","r",stdin);
	freopen("monster.out","w",stdout);
	scanf("%d",&n),top=n;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&s[i],&k[i],&tmp);
		for(int j=1;j<=tmp;j++){
			scanf("%d",&tmp2);
			if(i!=tmp2)add_edge(i,tmp2);
			else tag[i]=true;
		}
	}
	printf("%llu\n",dfs(1));
	fclose(stdin);
	fclose(stdout);
	return 0;
}
