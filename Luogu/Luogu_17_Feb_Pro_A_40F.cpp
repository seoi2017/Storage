#include<cstdio>//ZKW SegTree 40/100 TLE
#include<cstdlib>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<queue>
#include<stack>
#define INF 1000000010
#define N4 800010
#define N 200010
using namespace std;
struct lren{
    int lec,rec;
    lren(){
        this->lec=this->rec=0;
    }
}ec[N4];
int ta[N4]={0},tb[N4]={0},n,m,r,l,e;//a for max,b for min,e for fs(n),r&l for tag
inline int fs(int x){
    int M=1;
    while(M<n+2){
        M<<=1;
    }
    return M;
}
inline void update(int x){
    while(x){
        x>>=1;
        ta[x]=max(ta[x<<1],ta[(x<<1)+1]);
        tb[x]=min(tb[x<<1],tb[(x<<1)+1]);
    }
}
void debug_out(){
    for(int i=1;i<=fs(n)*2-1;i++){
        printf("%d ",ta[i]);
    }
    printf("\n");
    for(int i=1;i<=fs(n)*2-1;i++){
        printf("%d ",tb[i]);
    }
    printf("\n");
}
int work(int x){
    int ans=0;
    stack<int> Q;
    Q.push(1);
    while(!Q.empty()){
        int s=Q.top();
        Q.pop();
        if(ta[s]<x)continue;
        else if(tb[s]>=x){
            int nlc=ec[s].lec,nrc=ec[s].rec;
            if(nlc>r+1){
                //printf("[%d,%d]->[%d,%d] ",l,r,nlc,nrc);
                l=nlc;
                r=nrc;
                ans++;
            }
            else if(nlc==r+1){
                r=nrc;
            }
            continue;
        }
        else{
            Q.push((s<<1)+1);
            Q.push(s<<1);
            continue;
        }
    }
    return ans;
}
int init(){
    scanf("%d%d",&n,&m);
    e=fs(n),r=-1,l=-1;
    for(int i=e+1;i<=e+n;i++){
        int temp;
        scanf("%d",&temp);
        ta[i]=tb[i]=temp;
        ec[i].lec=ec[i].rec=i;
    }
    for(int i=e-1;i!=0;i--){
        ta[i]=max(ta[i<<1],ta[(i<<1)+1]);
        tb[i]=min(tb[i<<1],tb[(i<<1)+1]);
        ec[i].lec=ec[i<<1].lec,ec[i].rec=ec[(i<<1)+1].rec;
    }
    for(int i=1;i<=m;i++){
        int command,x,y;
        scanf("%d",&command);
        if(command==1){
            scanf("%d",&x);
            printf("%d\n",work(x));
            r=-1,l=-1;
        }
        else if(command==2){
            scanf("%d%d",&x,&y);
            ta[e+x]=tb[e+x]=y;
            update(e+x);
            //debug_out();
        }
    }
}
int main(){
    init();
    system("pause");
    return 0;
}
/*
In:
7 3
6 5 4 7 2 3 4
1 4
2 3 3
1 4
Out:
2
3
==============
In:
12 5
3 2 7 9 3 6 5 2 1 7 1 3
1 5
2 8 4
1 3
2 7 1
1 4
Out:
3
4
4
*/