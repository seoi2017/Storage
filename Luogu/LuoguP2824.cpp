#include<bits/stdc++.h>//Not Completed...
#define N 100000
#define lson (x>>1)
#define rson ((x>>1)+1)
using namespace std;
struct node_t{
    int a,b,c;
};
node_t p[N];
int s[N],seg[N*4],lazy[N*4],n,m;
void build(int l,int r,int s){
    
}
int check(int ask){
    
}
void input(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&s[i]);
    for(int i=1;i<=n;i++)scanf("%d%d%d",&p[i].a,&p[i].b,&p[i].c);
    scanf("%d",&ans);
}
int solve(int l,int r){
    if(l>r)return r;
    int mid=(l+r)>>1;
    if(check(mid)==0)return solve(l,mid-1);
    else return solve(mid+1,r);
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    input();
    printf("%d\n",solve(1,n));
    fclose(stdin);
    fclose(stdout);
    return 0;
}