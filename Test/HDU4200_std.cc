#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100;
const int inf=0x3fffffff;
int a[maxn][maxn+1],x[maxn],equ,var;
void Init()
{
    int d,tmp;
    scanf("%d%d",&equ,&d);
    var=equ;
    memset(a,0,sizeof(a));
    memset(x,0,sizeof(x));
    for(int i=0;i<var;i++)
      scanf("%d",&a[i][var]);
    for(int i=0;i<var;i++)
    {
        for(int j=0;j<=d;j++)
        {
            if(i-j>=0) a[i-j][i]=1;
            if(i+j<var) a[i+j][i]=1;
        }
    }
}
void Debug()
{
    for(int i=0;i<equ;i++)
    {
        for(int j=0;j<=var;j++)
          cout<<a[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}
int gcd(int a,int b)
{
    if(a<0) return gcd(-a,b);
    if(b<0) return gcd(a,-b);
    return b==0?a:gcd(b,a%b);
}
void Gauss()
{
    int k,col=0;
    for(k=0;k<equ&&col<var;k++,col++)
    {
        int mx=k;
        for(int i=k+1;i<equ;i++)
           if(a[i][col]>a[mx][col]) mx=i;
        if(mx!=k)
        {
            for(int i=k;i<var+1;i++)
               swap(a[k][i],a[mx][i]);
        }
        if(!a[k][col])
        {
            k--; continue;
        }
        for(int i=k+1;i<equ;i++)
        if(a[i][col])
        {
            int lcm=a[k][col]/gcd(a[k][col],a[i][col])*a[i][col];
            int ta=lcm/a[i][col],tb=lcm/a[k][col];
            for(int j=col;j<var+1;j++)
               a[i][j]=((a[i][j]*ta-a[k][j]*tb)%2+2)%2;
        }
    }
    //Debug();
    for(int i=k;i<equ;i++)
      if(a[i][col])
      {
          puts("impossible");
          return ;
      }
    for(int i=0,j;i<equ;i++)
       if(a[i][i]==0){
           for(j=i+1;j<var;j++)
              if(a[i][j]) break;
           if(j>=var) break;
           for(int r=0;r<equ;r++) swap(a[r][i],a[r][j]);
    }
   int Min=inf;
   for(int j=0;j<(1<<(equ-k));j++)
     {
        int tmp=j,p=equ-1;
        while(tmp) x[p--]=tmp%2,tmp>>=1;
        for(int i=k-1;i>=0;i--)
        {
          int tmp=a[i][var]%2;
          for(int j=i+1;j<var;j++)
             if(a[i][j]) tmp=(tmp-a[i][j]*x[j]%2+2)%2;
          x[i]=(tmp/a[i][i])%2;
        }
        tmp=0;
        for(int i=0;i<var;i++) tmp+=x[i];
        Min=min(Min,tmp);
     }
   printf("%d\n",Min);
}
int main()
{
    int t,q;
    scanf("%d",&t);
    while(t--)
    {
        Init();
        Gauss();
    }
    return 0;
}