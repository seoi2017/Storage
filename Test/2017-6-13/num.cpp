#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#define MX 100003
using namespace std;
int n,m,ul,ur,top=0,tot=0;
struct s_t{
    int a,b,c;
}e[MX];
struct n_t{
    int maxs,l,r;
    n_t *lc,*rc;
}seg[MX<<2],nxs[MX<<2],*root,*roox;
void insert(n_t *now,int s){
    now->maxs++;
    int nl=now->l,nr=now->r,mid=(nl+nr)>>1;
    if(nl==nr && nl==s)return;
    if(s<=mid)insert(now->lc,s);
    if(s>mid)insert(now->rc,s);
}
int querx(n_t *now,int l,int r){
    int nl=now->l,nr=now->r;
    if(l<=nl && nr<=r)return now->maxs;
    int ans=0,mid=(nl+nr)>>1;
    if(l<=mid)ans+=querx(now->lc,l,r);
    if(r>mid)ans+=querx(now->rc,l,r);
    return ans;
}
n_t *build(int l,int r){
    n_t *now=&seg[++top];
    now->l=l,now->r=r;
    if(l^r){
        n_t *&lson=now->lc,*&rson=now->rc;
        int mid=(l+r)>>1;
        lson=build(l,mid);
        rson=build(mid+1,r);
        now->maxs=max(lson->maxs,rson->maxs);
    }
    else now->maxs=e[l].a;
    return now;
}
n_t *builx(int l,int r){
    n_t *now=&nxs[++top];
    now->l=l,now->r=r;
    if(l^r){
        int mid=(l+r)>>1;
        now->lc=builx(l,mid);
        now->rc=builx(mid+1,r);
    }
    return now;
}
int query(n_t *now,int l,int r){
    int nl=now->l,nr=now->r;
    if(l<=nl && nr<=r)return now->maxs;
    int ans=0,mid=(nl+nr)>>1;
    if(l<=mid)ans=max(ans,query(now->lc,l,r));
    if(r>mid)ans=max(ans,query(now->rc,l,r));
    return ans;
}
inline bool cmp1(s_t x,s_t y){
    return x.a<y.a;
}
inline bool cmp2(s_t x,s_t y){
    return x.b<y.b;
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d%d",&n,&m);
    roox=builx(1,n);
    for(int i=1;i<=n;i++){
        scanf("%d",&e[i].a);
        e[i].b=i;
    }
    root=build(1,n);
    sort(e+1,e+1+n,cmp1);
    for(int i=1;i<=n;i++){
        e[i].c=i;
    }
    sort(e+1,e+1+n,cmp2);
    for(int i=1;i<=n;i++){
        tot+=querx(roox,e[i].c+1,n);
        insert(roox,e[i].c);
    }
    printf("%d\n",tot);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&ul,&ur);
        printf("%d\n",query(root,ul,ur));
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}