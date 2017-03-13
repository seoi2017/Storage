#include<bits/stdc++.h>
#define N 100010
#define INF 0xEFFFFFFF
using namespace std;
typedef unsigned long long ulld_t;
int n;
struct node_t{
    int next;
    ulld_t num;
    vector<int> last;
}p[N];
ulld_t ans=0;
int vis[N];
int cuted[N];
queue<int> Q,T;
void find_circle(){
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            vis[i]=1;
            int x=p[i].next;
            while(vis[x]!=2){
                if(vis[x]==0)vis[x]=1;
                else if(vis[x]==1){
                    vis[x]=2;
                    if(p[x].last.size()>1)T.push(x);
                }
                x=p[x].next;
            }
        }
    }
}
void solve(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%llu",&p[i].next,&p[i].num);
        p[p[i].next].last.push_back(i);
    }
    for(int i=1;i<=n;i++){
        printf("%d[in:%d|next:%d]\n",i,p[i].last.size(),p[i].next);
    }
    find_circle();
    for(int i=1;i<=n;i++)if((p[i].last.size()>1)&&(vis[i]==1))Q.push(i);
    while(!Q.empty()){
        int x=Q.front(),s=-1;
        Q.pop();
        ulld_t rec=0;
        for(int i=0;i<p[x].last.size();i++){
            if(max(rec,p[p[x].last[i]].num)!=rec){
                s=p[x].last[i];
            }
        }
        for(int i=0;i<p[x].last.size();i++){
            if(p[x].last[i]!=s){
                rec+=p[p[x].last[i]].num;
            }
        }
        p[s].next=-1;
        ans+=rec;
        printf("1Cut:%d\n",s);
        cuted[s]=1;
    }
    while(!T.empty()){
        int x=T.front();
        T.pop();
        ulld_t rec=p[x].num;
        int s=-1;
        for(int i=0;i<p[x].last.size();i++){
            if(max(rec,p[p[x].last[i]].num)!=rec){
                s=p[x].last[i];
                rec=p[p[x].last[i]].num;
            }
        }
        if(s!=-1){
            for(int i=0;i<p[x].last.size();i++){
                if((p[x].last[i]!=s)&&(!cuted[p[x].last[i]]))ans+=p[p[x].last[i]].num,cuted[p[x].last[i]]=1,printf("2Cut:%d\n",p[x].last[i]);
            }
            if(!cuted[x])ans+=p[x].num,cuted[x]=1,printf("2Cut:%d\n",x);
        }
        else{
            for(int i=0;i<p[x].last.size();i++){
                if(!cuted[p[x].last[i]])ans+=p[p[x].last[i]].num,cuted[p[x].last[i]]=1,printf("2Cut:%d\n",p[x].last[i]);
            }
        }
    }
    printf("%llu",ans);
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    solve();
    fclose(stdin);
    fclose(stdout);
    return 0;
}