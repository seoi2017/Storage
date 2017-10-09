#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int Mx=200010,Cz=200000;
int a[Mx],pos;
struct Seg{
    int sumx[Mx*4];
    void build(int l,int r,int rt){
        if(l==r){sumx[rt]=a[l];return;}
        int mid=l+r>>1;
        build(l,mid,rt<<1);
        build(mid+1,r,rt<<1|1);
        sumx[rt]=sumx[rt<<1]^sumx[rt<<1|1];
        return;        
    }
    void update(int l,int r,int rt,int p,int v){
        if(l==r){
            if(v==-1)
                sumx[rt]=0;
            else 
                sumx[rt]^=v;
            return;
            }
        int mid=l+r>>1;
        if(p<=mid) update(l,mid,rt<<1,p,v);
        else update(mid+1,r,rt<<1|1,p,v);
        sumx[rt]=sumx[rt<<1]^sumx[rt<<1|1];
    }
    int query(int l,int r,int rt,int L,int R){
        if(L<=l&&R>=r)return sumx[rt];
        int mid=l+r>>1,ans=0;
        if(L<=mid) ans^=query(l,mid,rt<<1,L,R);
        if(R>mid)  ans^=query(mid+1,r,rt<<1|1,L,R);
        return ans;
    }
}seg;
struct Bit{
    int c[Mx];
    int lowbit(int x){return x&-x;}
    void update(int x,int d){
        if(!x) return;
        while(x<=Cz)
            c[x]+=d,x+=lowbit(x);
        return;
    }
    int sum(int x){
        int ans=0;
        while(x)
            ans+=c[x],x-=lowbit(x);
        return ans;
    }
}bit;
inline void Fio(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
}
int main(){
    Fio();
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=0;i<Mx*4;i++)
        seg.sumx[i]=0;
    for(int i=0;i<Mx;i++)
        bit.c[i]=0;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=Cz;i++)
        bit.update(i,1);
    seg.build(1,Cz,1);
    pos=n+1;
    for(int i=1;i<=q;i++){
        int op,x,y;
        scanf("%d",&op);
        if(op==1){
            scanf("%d",&x);
            seg.update(1,Cz,1,pos,x);
            pos++;
        }
        if(op==2){
            scanf("%d",&x);
            seg.update(1,Cz,1,bit.sum(x),-1);
            bit.update(x,1);
        }
        if(op==3){
            scanf("%d%d",&x,&y);
            x=bit.sum(x);y=bit.sum(y);
            printf("%d\n",seg.query(1,Cz,1,x,y));
        }
    }
    return 0;
}