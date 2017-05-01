#pra\
gma G++ optimize("O3")
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#define N 100005
int P;//模数
typedef long long ll_t;
struct node_t{
    ll_t sum,mul,add;
    int l,r;
    node_t *lc,*rc;
};
/*
乘法原理:(a*x+b)*c+d=a*x*c+b*c+d
*/
inline int in(){
    char a=getchar();
    int x=0; 
    while(a<'0' || a>'9')a=getchar();
    while(a>='0' && a<='9'){
        x=x*10+(a-'0');
        a=getchar();
    }
    return x;
}
inline ll_t inl(){
    char a=getchar();
    ll_t x=0;
    while(a<'0' || a>'9')a=getchar();
    while(a>='0' && a<='9'){
        x=x*10+(a-'0');
        a=getchar();
    }
    return x;
}
inline void out(ll_t x){
    int num=0;
    char c[20];
    while(x)c[++num]=(x%10)+48,x/=10;
    while(num)putchar(c[num--]);
    putchar('\n'); 
}
//=================================
struct Segment_Tree_t{
    node_t seg[N<<2];
    node_t *root;
    int top;
    node_t *build_in(int l,int r){//inside
        node_t *now=&seg[++top];
        now->l=l,now->r=r;
        now->mul=1,now->add=0;
        if(l==r){
            //scanf("%lld",&now->sum);
            now->sum=inl();
            now->lc=now->rc=NULL;
        }
        else{
            int mid=(l+r)>>1;
            node_t *&lson=now->lc,*&rson=now->rc;
            lson=build_in(l,mid);
            rson=build_in(mid+1,r);
            now->sum=(lson->sum+rson->sum)%P;
        }
        return now;
    }
    inline void build(int l,int r){//outside
        top=0;
        root=build_in(l,r);
    }
    inline int length(node_t *now){
        return (now->r-now->l)+1;
    }
    inline void pushdown(node_t *now,node_t *lson,node_t *rson){
        ll_t fmul=now->mul,fadd=now->add;
        lson->mul=(lson->mul*fmul)%P;
        rson->mul=(rson->mul*fmul)%P;
        lson->add=(lson->add*fmul+fadd)%P;
        rson->add=(rson->add*fmul+fadd)%P;
        lson->sum=(lson->sum*fmul+length(lson)*fadd)%P;
        rson->sum=(rson->sum*fmul+length(rson)*fadd)%P;
        now->mul=1;
        now->add=0;
    }
    void mul_update(node_t *now,int l,int r,ll_t s){
        int nl=now->l,nr=now->r;
        if(l<=nl && r>=nr){
            now->mul=(now->mul*s)%P;
            now->sum=(now->sum*s)%P;
            now->add=(now->add*s)%P;
            return;
        }
        node_t *lson=now->lc,*rson=now->rc;
        if(now->add!=0||now->mul!=1)pushdown(now,lson,rson);
        int mid=(nl+nr)>>1;
        if(l<=mid)mul_update(lson,l,r,s);
        if(r>mid)mul_update(rson,l,r,s);
        now->sum=(lson->sum+rson->sum)%P;
    }
    void add_update(node_t *now,int l,int r,ll_t s){
        int nl=now->l,nr=now->r;
        if(l<=nl && r>=nr){
            now->add=(now->add+s)%P;
            now->sum=(now->sum+((length(now)*s)%P))%P;
            return;
        }
        node_t *lson=now->lc,*rson=now->rc;
        if(now->add!=0||now->mul!=1)pushdown(now,lson,rson);
        int mid=(nl+nr)>>1;
        if(l<=mid)add_update(lson,l,r,s);
        if(r>mid)add_update(rson,l,r,s);
        now->sum=(lson->sum+rson->sum)%P;
    }
    ll_t query(node_t *now,int l,int r){
        int nl=now->l,nr=now->r;
        if(l<=nl && r>=nr)return now->sum;
        node_t *lson=now->lc,*rson=now->rc;
        if(now->add!=0||now->mul!=1)pushdown(now,lson,rson);
        ll_t ans=0;
        int mid=(nl+nr)>>1;
        if(l<=mid)ans=(ans+query(lson,l,r));
        if(r>mid)ans=(ans+query(rson,l,r))%P;
        now->sum=(lson->sum+rson->sum)%P;
        return ans;
    }
}seg;
//=========================================
int n,m,c,a,b;
ll_t s;
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    //scanf("%d%d%d",&n,&m,&P);
    n=in(),m=in(),P=in();
    seg.build(1,n);
    for(int i=1;i<=m;i++){
        //scanf("%d%d%d",&c,&a,&b);
        c=in(),a=in(),b=in();
        if(c==3)out(seg.query(seg.root,a,b));/*printf("%lld\n",seg.query(seg.root,a,b)%P);*///Query.
        else{
            //scanf("%lld",&s);
            s=inl();
            if(c==1)seg.mul_update(seg.root,a,b,s);//Mul.
            else seg.add_update(seg.root,a,b,s);//Add.
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}