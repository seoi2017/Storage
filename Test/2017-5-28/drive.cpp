#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;
const int N=3003,M=300003,P=100000000;
struct n_t{
    int data,tag,kon;
    n_t *next;
}p[M+N];
int n,m,top=0,kon[M]={0};
//unsigned long long tot[M]={0};
inline void ins(int x,int y,int tag){
    n_t *now=&p[++top];
    now->data=y;
    now->tag=tag;
    now->kon=0;
    now->next=p[x].next;
    p[x].next=now;
}
void input(){
    int a,b;
    scanf("%d%d",&n,&m);
    top=n;
    for(int i=1;i<=m;i++){
        scanf("%d%d",&a,&b);
        ins(min(a,b),max(a,b),i);
    }
}
int dfs(int x){
    if(x==n)return 1;
    int lnk=0,tmp;
    for(n_t *k=p[x].next;k!=NULL;k=k->next){
        tmp=dfs(k->data);
        lnk=(lnk+tmp)%P;
        kon[k->tag]=(kon[k->tag]+tmp)%P;
    }
    return lnk;
}
void solve(){
    int sum=dfs(1);
    printf("%d\n",sum);
    for(int i=1;i<=m;i++){
        printf("%d ",sum-kon[i]);
    }
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    input();
    solve();
    fclose(stdin);
    fclose(stdout);
    return 0;
}