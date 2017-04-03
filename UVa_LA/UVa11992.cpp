#include<iostream>//Accepted!
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define INF 0x3f3f3f3f
#define input (in(x1),in(y1),in(x2),in(y2))
#define output (out(tots),putchar(' '),out(mins),putchar(' '),out(maxs),putchar('\n'))
#define root(x) (&seg[x])
#define lson (now->lc)
#define rson (now->rc)
#define mid ((now->l+now->r)>>1)
//#define father (now->fa)//This Problem Has No Father To Use.
using namespace std;
const int N=2000010,M=21;int n,m,c,top=0,start[M]={0};
struct segnode_t{int set,add,sum,min,max,l,r;segnode_t *lc,*rc;}seg[N<<2];
inline void in(int &s){
	char temp='0';s=0;
	do{
		s=s*10+temp-'0';
		temp=getchar();
	}while(temp>='0' && temp<='9');
}
inline void out(int s){
	if(s>9)out(s/10);
	putchar((s%10)+'0');
}
inline int build(int l,int r){
	int temp=++top;segnode_t *now=&seg[temp];
	now->l=l,now->r=r,now->set=-1,now->add=0,now->max=now->min=0,now->sum=0;
	if(l==r)now->sum=0,lson=NULL,rson=NULL;
	else lson=&seg[build(l,mid)],rson=&seg[build(mid+1,r)];
	return temp;
}
inline void pushdown(segnode_t *now){
	if(now->set!=-1){
		lson->set=rson->set=now->set,lson->add=rson->add=0;
		lson->sum=(lson->r-lson->l+1)*now->set,lson->max=lson->min=now->set;
		rson->sum=(rson->r-rson->l+1)*now->set,rson->max=rson->min=now->set;
		now->set=-1;
	}
	if(now->add!=0){
		lson->add+=now->add,rson->add+=now->add;
		lson->sum+=(lson->r-lson->l+1)*now->add,lson->max+=now->add,lson->min+=now->add;
		rson->sum+=(rson->r-rson->l+1)*now->add,rson->max+=now->add,rson->min+=now->add;
		now->add=0;
	}
}
inline void pushup(segnode_t *now){
	now->min=min(lson->min,rson->min);
	now->max=max(lson->max,rson->max);
	now->sum=lson->sum+rson->sum;
}
inline void add_update(segnode_t *now,int l,int r,int s){
	if(now->l==l && now->r==r){now->add+=s,now->sum+=(r-l+1)*s,now->min+=s,now->max+=s;return;}
	pushdown(now);
	if(l<=mid)add_update(lson,l,min(r,lson->r),s);
	if(r>mid)add_update(rson,max(l,rson->l),r,s);
	pushup(now);
}
inline void set_update(segnode_t *now,int l,int r,int s){
	if(now->l==l && now->r==r){now->set=s,now->add=0,now->sum=(r-l+1)*s,now->min=now->max=s;return;}
	pushdown(now);
	if(l<=mid)set_update(lson,l,min(r,lson->r),s);
	if(r>mid)set_update(rson,max(l,rson->l),r,s);
	pushup(now);
}
inline void query(segnode_t *now,int l,int r,int &mins,int &maxs,int &tots){
	if(now->l==l && now->r==r){tots+=now->sum,mins=min(mins,now->min),maxs=max(maxs,now->max);return;}
	pushdown(now);
	if(l<=mid)query(lson,l,min(r,lson->r),mins,maxs,tots);
	if(r>mid)query(rson,max(l,rson->l),r,mins,maxs,tots);
	pushup(now);
}
void solve(){
	top=0;for(int i=1;i<=n;i++)start[i]=top+1,build(1,m);
	while(c--){
		int temp,x1,x2,y1,y2,s,mins=INF,maxs=-1,tots=0;in(temp);
		if(temp==1){input,in(s);for(int i=x1;i<=x2;i++)add_update(root(start[i]),y1,y2,s);}
		else if(temp==2){input,in(s);for(int i=x1;i<=x2;i++)set_update(root(start[i]),y1,y2,s);}
		else if(temp==3){input;for(int i=x1;i<=x2;i++)query(root(start[i]),y1,y2,mins,maxs,tots);output;}
	}
}
int main(){
	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	in(n),in(m),in(c);while(n)solve(),in(n),in(m),in(c);
	fclose(stdin),fclose(stdout);
	return 0;
}