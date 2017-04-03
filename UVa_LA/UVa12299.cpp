#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#define root (&seg[1])
#define lson (now->lc)
#define rson (now->rc)
#define mid ((now->l+now->r)>>1)
#define father (now->fa)
using namespace std;
const int N=100010;
int n,m,top=0,com[N]={0},ind[N]={0},t=0;
struct segnode{
	int s,l,r;
	segnode *lc,*rc,*fa;
}seg[N<<2];
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
	int temp=++top; segnode *now=&seg[temp];
	now->l=l,now->r=r;
	if(l==r)in(now->s),ind[l]=temp,lson=NULL,rson=NULL;
	else lson=&seg[build(l,mid)],lson->fa=now,rson=&seg[build(mid+1,r)],rson->fa=now,now->s=min(lson->s,rson->s);
	return temp;
}
inline void update(segnode *now){
	if(lson!=NULL && rson!=NULL){
		int temp=now->s;
		now->s=min(lson->s,rson->s);
		if(temp==now->s)return;
	}
	if(father!=NULL)update(father);
}
inline int query(segnode *now,int l,int r){
	if(l==now->l && r==now->r)return now->s;
	int ans=0x3f3f3f3f;
	if(l<=mid)ans=min(ans,query(lson,l,min(r,lson->r)));
	if(r>mid)ans=min(ans,query(rson,max(l,rson->l),r));
	return ans;
}
void solve() {
	in(n),in(m),build(1,n);
	while(m--){
		t=0;char temp=getchar();
		if(temp=='s'){
			int s=0;
			do temp=getchar();
			while(!(temp>='0' && temp<='9'));
			tag1:
			do s=s*10+(temp-'0'),temp=getchar();
			while(temp>='0' && temp<='9');
			if(temp==','){
				com[++t]=s,s=0,temp='0';
				goto tag1;
			}
			com[++t]=s;
			for(int i=1;i<t;i++){
				swap(seg[ind[com[i]]].s,seg[ind[com[i+1]]].s);
				update(&seg[ind[com[i]]]);
				update(&seg[ind[com[i+1]]]);
			}
		}
		else if(temp=='q'){
			int s=0;
			do temp=getchar();
			while(!(temp>='0' && temp<='9'));
			tag2:
			do s=s*10+(temp-'0'),temp=getchar();
			while(temp>='0' && temp<='9');
			if(temp==','){
				com[++t]=s,s=0,temp='0';
				goto tag2;
			}
			com[++t]=s;
			out(query(root,com[1],com[2]));putchar('\n');
		}
		getchar();
	}
}
int main(){
	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	solve();
	fclose(stdin),fclose(stdout);
	return 0;
}