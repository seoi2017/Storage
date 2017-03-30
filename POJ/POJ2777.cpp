#include<iostream>//Accepted!
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=100010;int n,t,o,top=0,ans=0;
struct segtree_t{int color,cover,l,r;segtree_t *lc,*rc;}seg[N<<2];
int build(int l,int r){
    int temp=++top;segtree_t *now=&seg[temp];
    now->lc=NULL,now->rc=NULL,now->l=l,now->r=r,now->color=1,now->cover=1;
    if(now->l!=now->r)now->lc=&seg[build(l,l+r>>1)],now->rc=&seg[build((l+r>>1)+1,r)];
    return temp;
}
void update(segtree_t *now,int l,int r,int s){
    if((now->l==now->r)||(l<=now->l && now->r<=r)){now->color=1<<(s-1),now->cover=1;return;}
    if(now->color==1<<(s-1))return;//简单剪枝
    if(now->cover)now->lc->color=now->color,now->rc->color=now->color,now->lc->cover=1,now->rc->cover=1,now->cover=0;
    if(r<=now->lc->r)update(now->lc,l,r,s);
    else if(l>=now->rc->l)update(now->rc,l,r,s);
    else update(now->lc,l,now->lc->r,s),update(now->rc,now->rc->l,r,s);
    now->color=now->lc->color|now->rc->color;
}
void query(segtree_t *now,int l,int r){
    if((now->l==now->r)||(l<=now->l && now->r<=r)){ans|=now->color;return;}
    if(now->cover){ans|=now->color;return;}//简单剪枝
    if(r<=now->lc->r)query(now->lc,l,r);
    else if(l>=now->rc->l)query(now->rc,l,r);
    else query(now->lc,l,now->lc->r),query(now->rc,now->rc->l,r);
}
int check(int x){//看数内有多少个二进制1
    int ans=0;
    while(x){if(x&1)ans++;x>>=1;}
    return ans;
}
void swap_l(int &x,int &y){int temp=x;x=y,y=temp;}
void solve(){
    top=0,build(1,n);
    while(o--){
        char temp;int x,y,z;ans=0;
        scanf("\n%c",&temp);
        if(temp=='C'){scanf("%d%d%d",&x,&y,&z);if(x>y)swap_l(x,y);update(&seg[1],x,y,z);}
        else if(temp=='P'){scanf("%d%d",&x,&y);if(x>y)swap_l(x,y);query(&seg[1],x,y),printf("%d\n",check(ans));}
    }
}
int main(){
    freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
    while(~scanf("%d%d%d",&n,&t,&o))solve();
    fclose(stdin),fclose(stdout);
    return 0;
}