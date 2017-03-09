#include<iostream>//Accepted!
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#define INF 0x3f3f3f3f
#define N 110
#define M 5100
using namespace std;
struct edge{
    int st,et,ln;
    edge(){
        this->st=0;
        this->et=0;
        this->ln=0;
    }
    void init(int x=0,int y=0,int l=0){
        this->st=x;
        this->et=y;
        this->ln=l;
    }
}e[M];
int n,m,ans=INF,fa[N]={0},top=0,l;
inline bool cmp(edge x,edge y){
    return x.ln<y.ln;
}
void push_edge(int x,int y,int l){
    top++;
    e[top].init(x,y,l);
}
void clear_edge(){
    memset(fa,0,sizeof(fa));
    ans=INF;
    while(top){
        e[top].init();
        top--;
    }
}
inline int findfa(int x){
    if(fa[x]==x)return x;
    else return fa[x]=findfa(fa[x]);
}
inline bool bing(int a,int b){
    int x=findfa(a),y=findfa(b);
    if(x==y)return false;
    else{
        fa[y]=x;
        return true;
    }
}
int suan(){
    int minl=INF,maxl=-1,cnt=0;
    for(int i=l;i<=m;i++){
        if(cnt==n-1)break;
        if(bing(e[i].st,e[i].et)){
            minl=min(minl,e[i].ln);
            maxl=max(maxl,e[i].ln);
            cnt++;
        }
    }
    if(cnt!=n-1)return INF;
    return maxl-minl;
}
int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        if(n==0 && m==0)break;
        clear_edge();
        for(int i=1;i<=m;i++){
            int a,b,l;
            scanf("%d%d%d",&a,&b,&l);
            push_edge(a,b,l);
        }
        sort(e+1,e+1+m,cmp);
        for(l=1;l<=m;l++){
            for(int i=1;i<=n;i++){
                fa[i]=i;
            }
            ans=min(ans,suan());
        }
        ans==INF ? printf("-1\n") : printf("%d\n",ans);
    }
    system("pause");
    return 0;
}