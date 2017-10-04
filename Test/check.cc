#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,tot;
char str[5000][32];
inline bool judge(int x){
    for(int i=1;i<x;i++)
        if(strcmp(str[i],str[x])==0)
            return true;
    return false;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%s",str[i]);
        if(judge(i))i--,n--;
    }
    printf("%d\n",n);
    system("pause");
    return 0;
}
int SPFA(int t){
    queue<int> Q;
    Q.push(t);
    vis[t]=true;
    while(!Q.empty()){
        int x=Q.front();
        Q.pop();
        vis[x]=false;
        for(node_t* k=p[x].nxt;k!=NULL;k=k->nxt){
            dis[k->dat]=min(dis[k->dat],dis[x]+k->len);
            if(!vis[k->dat]){
                vis[k->dat]=true;
                Q.push(k->dat);
        }
    }
}