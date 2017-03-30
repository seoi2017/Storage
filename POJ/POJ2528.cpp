//数据离散化+指针线段树
#include<iostream>//Accepted!
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
const int N=10010,M=20010;int n,top=0,ans[M]={0};
struct segtree_t{int post,l,r;segtree_t *lson,*rson;segtree_t(){this->post=this->l=this->r=0,this->lson=this->rson=NULL;}}seg[M*4];
struct cmp_t{int point,owner;}u[M];
struct len_t{int l,r;}a[M];
inline bool cmp(cmp_t x,cmp_t y){return x.point<y.point;}
int build_segtree(int l,int r){
    seg[++top].l=l,seg[top].r=r,seg[top].post=0,seg[top].lson=NULL,seg[top].rson=NULL;
    if(l==r)return top;
    int temp=top;
    seg[temp].lson=&seg[build_segtree(l,(l+r)>>1)];
    seg[temp].rson=&seg[build_segtree(((l+r)>>1)+1,r)];
    return temp;
}
void update(segtree_t* now,int l,int r,int p){
    if(now->l==now->r){
        now->post=p;
        return;
    }
    else if(l<=now->l && r>=now->r){
        now->post=p;
        return;
    }
    if(now->post!=0)now->lson->post=now->post,now->rson->post=now->post;
    if(r<=(now->l+now->r)>>1)update(now->lson,l,r,p);       
    else if(l>=((now->l+now->r)>>1)+1)update(now->rson,l,r,p);
    else update(now->lson,l,r,p),update(now->rson,l,r,p);
    now->post=0;
}
void query(segtree_t* now){
    if(now==NULL)return;
    if(now->post!=0){ans[now->post]++;return;}
    query(now->lson);
    query(now->rson);
}
void solve(){
    scanf("%d",&n);
    for(int i=1;i<=n*2;i+=2){
        a[i].l=a[i].r=a[i+1].l=a[i+1].r=0;
        scanf("%d%d",&u[i].point,&u[i+1].point);
        u[i].owner=u[i+1].owner=++top;
    }
    sort(u+1,u+1+n*2,cmp);
    int temp=0;
    for(int i=1;i<=n*2;i++){
        //printf("[%d|%d-%d]",i,u[i].point,u[i].owner);
        if(u[i].point==u[i-1].point)a[u[i].owner].l==0?a[u[i].owner].l=temp:a[u[i].owner].r=temp;
        else a[u[i].owner].l==0?a[u[i].owner].l=++temp:a[u[i].owner].r=++temp;
    }
    //for(int i=1;i<=n;i++){
    //    printf("[%d|%d:%d]\n",i,a[i].l,a[i].r);
    //}
    top=0;
    build_segtree(1,n*2);
    for(int i=1;i<=n;i++){
        update(&seg[1],a[i].l,a[i].r,i);
    }
    query(&seg[1]);
    int tot=0;
    for(int i=1;i<=n;i++)if(ans[i]!=0)tot++;
    printf("%d\n",tot);
}
int main(){
    freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
    int cases;
    scanf("%d",&cases);
    while(cases--)top=0,memset(ans,0,sizeof(ans)),solve();
    fclose(stdin),fclose(stdout);
    return 0;
}