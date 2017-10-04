#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
inline int read() 
{
    int x=0; char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x;
}
ll ans;
struct Node
{
    int u,v; int len;
    Node(int x1=0,int x2=0,int x3=0):u(x1),v(x2),len(x3){};
}Road[500005];
bool cmp(const Node& Road1,const Node& Road2)
{
    return Road1.len<Road2.len;
}
int f[100005];
int Find(int x)
{
    if(f[x]==x)return x;
    else return f[x]=Find(f[x]);
}
int n,m;
int rnk[100005];
void unite(int x,int y) 
{
    x=Find(x); y=Find(y);
    if(x==y) return;
    if(rnk[x]<rnk[y]) f[x]=y;
    else 
    {
        f[y]=x;
        if(rnk[x]==rnk[y]) rnk[x]++;
    }
}
int main()
{
     n=read();m=read();
     for(int i=1;i<=m;i++)
     {
         int u,v;int len;
         scanf("%d%d%d",&u,&v,&len);
         Road[i]=Node(u,v,len);
     }
     sort(Road+1,Road+m+1,cmp);
    int sum=0;
    for(int i=1;i<=n;i++)
        f[i]=i;
     for(int i=1;i<=m;i++)
     {
         int u=Road[i].u;
         int v=Road[i].v;
         int len=Road[i].len;
         if(Find(u)!=Find(v))
         {
             //sum++;
             //ans=max(ans,len);
             unite(u,v);
            ans+=(len*1LL);
            sum++;
         }
     }
     printf("%lld\n",ans);
     system("pause");
     return 0;    
 }