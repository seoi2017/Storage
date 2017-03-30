#include<iostream>//Accepted!
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int N=200010,M=800010;int top=0,n,pos[N],val[N],ans[N]={0};
struct segtree_t{int s,l,r;segtree_t *lc,*rc;}seg[M];
inline int build(int l,int r){
    int temp=++top;segtree_t &now=seg[temp];
    now.lc=NULL,now.rc=NULL,now.l=l,now.r=r,now.s=r-l+1;
    if(l!=r)now.lc=&seg[build(l,l+r>>1)],now.rc=&seg[build((l+r>>1)+1,r)];
    return temp;
}
inline void update(segtree_t *now,int w,int s){
    if(now->l==now->r){ans[now->l]=s,now->s--;return;}
    now->s--;
    if(now->lc->s>=w)update(now->lc,w,s);else update(now->rc,w-now->lc->s,s);
}
void solve(){
    top=0;build(1,n);memset(ans,0,sizeof(ans));
    for(int i=1;i<=n;i++)scanf("%d%d",&pos[i],&val[i]),ans[i]=0;
    for(int i=n;i>=1;i--)update(&seg[1],pos[i]+1,val[i]);
    for(int i=1;i<n;i++)printf("%d ",ans[i]);printf("%d\n",ans[n]);
}
int main(){
    freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
    while(scanf("%d",&n)!=EOF)solve();
    fclose(stdin),fclose(stdout);
    return 0;
}