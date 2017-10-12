#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#define P 1000000007
#define N 17
#define M 301
using namespace std;
typedef long long ll_t;
int n,m,tot,e[N][N];
int f[1<<N],d[1<<N],c[1<<N],s[1<<N],p[M];
int main(){
    freopen("obelisk.in","r",stdin);
    freopen("obelisk.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=0,x,y;i<m;i++){
        scanf("%d%d",&x,&y);
        e[x-1][y-1]=1;
    }
    /*
    HYS的盲目分析.jpg
    事实上，当点数和边数确定后，由于没有自环和重边，所以整个图的状态是已经确定的
    又因为不输出方案，故点的序号排列对最终的结果没有影响，由此可以考虑状态压缩DP的思想
    可以考虑对于可能的每一种点集i（二进制状态压缩），用f[i]表示其结果
    为了更新答案，我们需要枚举点集i在全集tot下的补集bu内的所有子集j
    然后统计从集合i连向集合j的边，假设共有g条，则这g条边我们可以以组合数形式任意选取
    得到状态转移方程f[i^j]=f[i]+2^g
    但是如果仔细思考便会发现这样计算了大量的重复情况，因为集合k=i^j可能有多种划分方式
    那怎么办呢？不妨考虑容斥一下！
    对于可能的k=i^j，按j大小进行分类，乘上一个容斥系数就好了
    最终状态转移方程f[i^j]=f[i]*2^g*(-1)^s[j]+1
    状态数2^N-1=131071，1e5级别
    */
    p[0]=1,c[0]=-1;
    for(int i=1;i<=m;i++)
        p[i]=(p[i-1]<<1)%P;//乘方系数
    for(int i=1;i<(1<<n);i++){
        c[i]=c[i>>1];
        if(i&1)c[i]*=-1;//容斥系数
    }
    tot=(1<<n)-1;//全集
    f[0]=1;//空集也为一种方案
    for(int i=0;i<tot;i++){//遍历所有方案，O(2^n-1)
        for(int j=0;j<n;j++)d[1<<j]=0;//清空入度信息
        for(int j=0;j<n;j++)//O(n)
            if(i&(1<<j))//如果该方案内包含此点
                for(int k=0;k<n;k++)//遍历统计入度
                    if(e[j][k])d[1<<k]++;
        int bu=tot^i;//当前方案的补集
        s[0]=0;
        for(int j=(bu-1)&bu;;j=(j-1)&bu){//枚举补集的子集，每次交补集一次以确保不超出补集范围
            int k=bu^j;//以补集作全集下，j的补集
            s[k]=s[k-(k&(-k))]+d[k&(-k)];//k&(-k)就是lowbit(k)，取k二进制下最后的一个1
            f[i^k]=(f[i^k]+(ll_t)(f[i]*p[s[k]]*c[k]))%P;
            if(!j)break;
        }
    }
    printf("%d\n",f[tot]);
    //样例是过了，听天由命吧，(long long)(RP+=INF)！
    fclose(stdin);
    fclose(stdout);
    return 0;
}