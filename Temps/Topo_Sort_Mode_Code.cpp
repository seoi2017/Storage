//拓扑排序模板代码
//Powered By Inv.
//2017/3/6 18:57
#include<bits/stdc++.h>
using namespace std;
const int N=32768,M=131072;
struct node_t{
    node_t* next;
    int data;
    node_t(int data=0,node_t* next=NULL){
        this->data=data,this->next=next;
    }
}p[M];
int n,m,indeg[N],ans[N],vis[N],cnt=0;//indeg[]:点的入度
inline void insert(int x,int y){
    p[x].next=new node_t(y,p[x].next);
}
void input(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        insert(a,b),indeg[b]++;
    }
}
bool DFS(int x){
    vis[x]=-1;//1:已访问过,0:尚未被访问,-1:正在被访问
    for(node_t* k=p[x].next;k!=NULL;k=k->next){
        if(vis[k->data]==-1)return false;
        else if(vis[k->data]==0)DFS(k->data);
    }
    ans[++cnt]=x;
    vis[x]=1;
    return true;
}
void TopoSort_DFS(){
    for(int i=n;i>=1;i--){
        if(!vis[i]){
            if(!DFS(i)){
                printf("Error!\n");
                return;
            }
        }
    }
}
void TopoSort_BFS(){
    queue<int> Q;
    for(int i=1;i<=n;i++){
        if(!indeg[i])Q.push(i);
    }
    if(Q.empty())printf("Error!\n");
    while(!Q.empty()){
        int x=Q.front();
        Q.pop();
        ans[++cnt]=x;
        for(node_t* k=p[x].next;k!=NULL;k=k->next){
            indeg[k->data]--;
            if(!indeg[k->data])Q.push(k->data);
        }
    }
    return;
}
void clear(){
    cnt=0;
    memset(vis,0,sizeof(vis));
    memset(ans,0,sizeof(ans));
}
void BFS_Output(){
    for(int i=1;i<cnt;i++){
        printf("%d ",ans[i]);
    }
    printf("%d\n",ans[cnt]);
}
void DFS_Output(){
    for(int i=cnt;i>1;i--){
        printf("%d ",ans[i]);
    }
    printf("%d\n",ans[1]);
}
int main(){
    input();
    printf("DFS Output:"),clear(),TopoSort_DFS(),DFS_Output();
    printf("BFS Output:"),clear(),TopoSort_BFS(),BFS_Output();
    system("pause");
    return 0;
}