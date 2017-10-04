#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m,T,etc,top;
long long soc;
char c[20][20];
bool vis[20][20];
struct kuai{
	char t;
	int x,y,s;
};
kuai v[500];
inline bool cmp(kuai a,kuai b){
	if(a.s==b.s){
		if(a.y==b.y){
			return a.x>b.x;
		}
		else return a.y<b.y;
	}
	else return a.s>b.s;
}
inline kuai make_kuai(char c_,int x_,int y_,int s_){
	kuai b;
	b.t=c_,b.x=x_,b.y=y_,b.s=s_;
	return b;
}
inline void print(){
	for(int i=0;i<n;i++,printf("\n"))
		for(int j=0;j<m;j++)
			printf("%c",c[i][j]);
}
int dfs(int x,int y){
	int ans=1;
	vis[x][y]=true;
	if(x+1<n && !vis[x+1][y] && c[x+1][y]==c[x][y])ans+=dfs(x+1,y);
	if(x-1>=0 && !vis[x-1][y] && c[x-1][y]==c[x][y])ans+=dfs(x-1,y);
	if(y+1<m && !vis[x][y+1] && c[x][y+1]==c[x][y])ans+=dfs(x,y+1);
	if(y-1>=0 && !vis[x][y-1] && c[x][y-1]==c[x][y])ans+=dfs(x,y-1);
	return c[x][y]=='#'?0:ans;
}
void destory(int x,int y){
	vis[x][y]=true;
	if(x+1<n && !vis[x+1][y] && c[x+1][y]==c[x][y])destory(x+1,y);
	if(x-1>=0 && !vis[x-1][y] && c[x-1][y]==c[x][y])destory(x-1,y);
	if(y+1<m && !vis[x][y+1] && c[x][y+1]==c[x][y])destory(x,y+1);
	if(y-1>=0 && !vis[x][y-1] && c[x][y-1]==c[x][y])destory(x,y-1);
	c[x][y]='#';
}
inline bool judge(){
	top=0;
	memset(vis,0,sizeof(vis));
	for(int j=0;j<m;j++)
		for(int i=n-1;i>=0;i--)
			if(!vis[i][j])v[++top]=make_kuai(c[i][j],i,j,dfs(i,j));
	sort(v+1,v+1+top,cmp);
	memset(vis,0,sizeof(vis));
	if(v[1].s>1)return true;
	else return false;
}
void down(int x,int y){
	if(c[x][y]!='#' && x+1<n && c[x+1][y]=='#')swap(c[x+1][y],c[x][y]),down(x+1,y);
	if(x-1>=0)down(x-1,y);
}
void lf(int y){
	if(c[n-1][y]!='#' && y-1>=0 && c[n-1][y-1]=='#'){
		for(int i=0;i<n;i++)
			swap(c[i][y],c[i][y-1]);
		lf(y-1);
	}
	if(y+1<m)lf(y+1);
}
inline void upd(){
	for(int i=0;i<m;i++)
		down(n-1,i);
	lf(0);
}
inline void work(){
	int cnt=0;
	while(judge()){
		printf("Move %d at (%d,%d): removed %d balls of color %c, got %d points.\n",++cnt,n-v[1].x,v[1].y+1,v[1].s,c[v[1].x][v[1].y],(v[1].s-2)*(v[1].s-2));
		destory(v[1].x,v[1].y);
		upd();
		etc-=v[1].s;
		soc+=(v[1].s-2)*(v[1].s-2)*1LL;
		//print();
	}
	if(etc==0)soc+=1000LL;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d",&T);
	int cases=T;
	while(cases--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
			scanf("%s",c[i]);
		printf("Game %d:\n\n",T-cases);
		etc=n*m,soc=0LL,work();
		printf("Final score: %lld, with %d balls remaining.\n\n",soc,etc);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
