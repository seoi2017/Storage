#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m;
double ans=0.0;
struct fen_t{
    int x,y;
}f[103],st;
fen_t c(fen_t x,fen_t y){
    fen_t z;
    z.x=x.x*y.x;
    z.y=x.y*y.y;
    return z;
}
double suan(fen_t x){
    return (double)x.x/(double)x.y;
}
void build(int tot,int dep,fen_t fw){
    for(int i=suan(f[0])==0?1:0;i<=n;i++){
        if(!((tot+i)>=m))build(tot+i,dep+1,c(fw,f[i]));
        else ans+=(double)(dep+1)*suan(c(fw,f[i]));
    }
}
void solve(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n;i++){
        scanf("%d%d",&f[i].x,&f[i].y);
    }
    st.x=1,st.y=1;
    build(0,0,st);
    printf("%.3lf\n",ans);
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    solve();
    fclose(stdin);
    fclose(stdout);
    return 0;
}