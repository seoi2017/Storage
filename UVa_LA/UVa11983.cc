#include<cstdio>//Accepted!
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define root (&seg[1])
#define nl (now->l)
#define nr (now->r)
#define nw (now->w)
#define ncov (now->cov)
#define lson (now->lc)
#define rson (now->rc)
using namespace std;
const int N=60010,K=12;
typedef long long ull_t;
struct seg_t{int cov,l,r,w,sum[K];seg_t *lc,*rc,*fa;}seg[N<<2];
struct line_t{int l,r,h,t;}line[N];
ull_t ans=0;int n,k,top=0,pnt=0,map[N]={0},x1,y1,x2,y2,seglen=0;
inline bool cmp(const line_t x,const line_t y){return x.h<y.h;}
inline void clear(){n=k=0;ans=0;pnt=0,top=0,seglen=0;}
inline void in(int l,int r,int h,int t){line[++top].l=l,line[top].r=r,line[top].h=h,line[top].t=t;}
inline int build(int l,int r){
    int temp=++pnt,mid=(l+r)>>1;seg_t &now=seg[temp];
    memset(now.sum,0,sizeof(now.sum)),now.cov=0,now.l=l,now.r=r,now.w=map[r]-map[l],now.fa=NULL;
    if(r-l==1)now.lc=now.rc=NULL;
    else now.lc=&seg[build(l,mid)],now.rc=&seg[build(mid,r)],now.lc->fa=&now,now.rc->fa=&now;
    return temp;
}
inline void refresh(seg_t *now){
    for(int i=1;i<=k;i++){
        if(ncov>=i)now->sum[i]=nw;
        else{
            if(nr-nl==1)now->sum[i]=0;
            else now->sum[i]=lson->sum[i-ncov]+rson->sum[i-ncov];
        }
    }
}
inline void update(seg_t *now,int l,int r,int s){
    if(nl>=l && nr<=r){ncov+=s;refresh(now);return;}
    int mid=(nl+nr)>>1;
    if(l<mid)update(lson,l,r,s);
    if(r>mid)update(rson,l,r,s);
    refresh(now);
}
inline int gethash(int k,int len){//二分取映射值
    int l=1,r=len;
    while(l<=r){
        int m=(l+r)>>1;
        if(map[m]<k)l=m+1;
        else if(map[m]>k)r=m-1;
        else return m;
    }
    return -1;
}
void solve(){
    clear();
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        x2++,y2++;
        in(x1,x2,y1,1),map[top]=x1;
        in(x1,x2,y2,-1),map[top]=x2;
    }
    if(k>n)return;
    sort(map+1,map+1+top),sort(line+1,line+1+top,cmp);
    for(int i=2;i<=top+1;i++){if(map[i]!=map[i-1])map[++seglen]=map[i-1];}//去重
    build(1,seglen);
    for(int i=1;i<top;i++){//到倒数第二条边为止
        int tl=gethash(line[i].l,seglen),tr=gethash(line[i].r,seglen);//取离散化映射值
        update(root,tl,tr,line[i].t);
        ans+=root->sum[k]*1LL*(line[i+1].h-line[i].h);
    }
}
int main(){
    freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
    int cases;scanf("%d",&cases);int tot=0;
    while(cases--)solve(),printf("Case %d: %lld\n",++tot,ans);
    fclose(stdin),fclose(stdout);
    return 0;
}