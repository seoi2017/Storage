//Luogu P1113
//Powered by Inv.
//2017/2/28 19:38
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<queue>
#define N 10010
using namespace std;
struct node{
    int data;
    node* next;
    node(int data=0,node* next=NULL){
        this->data=data;
        this->next=next;
    }
}p[N];
int n,vis[N],dis[N];
inline void insert(int x,int y){
    p[x].next=new node(y,p[x].next);
}
void du(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int temp1,temp2=0;
        scanf("%d",&temp1);
        scanf("%d",&p[temp1].data);
        while(scanf("%d",&temp2)&&temp2!=0){
            insert(temp2,temp1);
        }
    }
    //No.0 for the root
    for(int i=1;i<=n;i++){
        insert(0,i);
    }
    memset(vis,0,sizeof(vis));
    memset(dis,-1,sizeof(dis));
}
void suan(){
    int ans=0;
    queue<int> Q;
    Q.push(0);
    dis[0]=0;
    vis[0]=1;
    while(!Q.empty()){
        int x=Q.front();
        Q.pop();
        vis[x]=0;
        ans=max(ans,dis[x]);
        for(node* k=p[x].next;k!=NULL;k=k->next){
            if(dis[k->data]<dis[x]+p[k->data].data){
                dis[k->data]=dis[x]+p[k->data].data;
                if(vis[k->data]==0){
                    vis[k->data]=1;
                    Q.push(k->data);
                }
            }
        }
    }
    printf("%d\n",ans);
}
void debug_out(){
    for(int i=0;i<=n;i++,printf("\n")){
        printf("%d:",i);
        for(node* k=p[i].next;k!=NULL;k=k->next){
            printf("->%d",k->data);
        }
    }
    for(int i=1;i<=n;i++){
        printf("%d ",dis[i]);
    }
    printf("\n");
}
int main(){
    du();
    suan();
    debug_out();
    system("pause");
    return 0;
}
/*
5
1 200 0
2 300 1 0
3 200 1 0
4 200 2 3 0
5 100 3 0
*/