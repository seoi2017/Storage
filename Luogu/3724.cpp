#include<bits/stdc++.h>
#define M 100000003
#define P 100000009
#define N 103
#define r(x) scanf("%d",&(x));
#define rep(a,b,c) for(int i=(a);i<=(b);i+=(c));
using namespace std;
typedef long long ll;
int n,m,mc,w[N],a[N];
int g[N][N];
int c[N],maxc;
int Q[M],_l,_r;
int head[P],f[M],l[M],t[M],next[M],idx[M],inum;
inline void add(int F,int L,int T){//加边,F讽刺能力,L等级,T时间
    int h=((ll)(F<<7)+L)%P;//hash
    for(int p=head[h];p;p=next[p])
        if(f[p]==F && l[p]==L)//已存在给定状态
            return;
    int p=++inum;//可能的状态加一
    f[p]=F,l[p]=L,t[p]=T;
    next[p]=head[h],head[h]=Q[++_r]=p;
}
inline bool cmp(int a,int b){
    return f[a]<f[b];
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    r(n),r(m),r(mc);
    rep(1,n,1)r(a[i]);//每日嘲讽消减自信
    rep(1,n,1)r(w[i]);//每日水题自信回涨
    rep(1,m,1)r(c[i]);//每个大佬自信初始值
    //DP最多能有几天空出来不用补血,可以怼大佬(含准备工作)
    memset(g,-1,sizeof(g));
    g[0][mc]=0;//初始满自信值
    for(int i=0;i<n;i++){//对每一天而言
        for(int j=0;j<=mc;j++){//对于剩余自信值而言
            if(g[i][j]==-1)continue;
            if(j>=a[i+1]){//如果可以执行其他操作(不会被大佬怼死)
                g[i+1][j-a[i+1]]=max(g[i+1][j-a[i+1]],g[i][j]+1);//空余天数的状态转移
                g[i+1][min(mc,j-a[i+1]+w[i+1])]=max(g[i+1][min(mc,j-a[i+1]+w[i+1])],g[i][j]);//水题回血的状态转移
            }
        }
    }
    int D=0;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=mc;j++)
            D=max(D,g[i][j]);//最多的空余天数
    //BFS搜索状态
    _l=_r=-1;//手动队列初始化
    add(1,0,1);//添加初始状态
    while(_l<_r){//队列不为空
        int u=Q[++_l];//取队首元素
        if((ll)f[u]*l[u]>maxc || t[u]+1>D)continue;//如果怼过头了或者时间不够了就剪枝
        if(l[u])add(f[u]*l[u],l[u],t[u]+1);//如果还有等级,就添加状态
        add(f[u],l[u]+1,t[u]+1);//添加升级后的状态
    }
    int p=++inum;
    f[p]=0,t[p]=0;
    for(int i=1;i<=inum;i++)idx[i]=i,t[i]-=f[i];//对于每个状态建立索引,等级需要时间来提升
    sort(idx+1,idx+inum+1,cmp);//按讽刺能力排序
    for(int I=1;I<=m;I++){//对于每个大佬
        int j=1,minv=1<<30,C=c[I],flag=0;
        for(int i=inum;i;i--){
            while(j<inum && f[idx[i]]+f[idx[j]]<=C)//不能怼过头
                minv=min(minv,t[idx[j]]),j++;
            if(minv+t[idx[i]]<=D-C){
                flag=1;//可以击败
                break;
            }
        }
        printf("%d\n",flag);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}