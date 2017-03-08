#include<iostream>//Accepted!
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 200
using namespace std;
struct blocks{
    int a,b,h;
}a[N];
int top=0,n,f[N];
void addup(int x,int y,int z){
    a[++top].a=x,a[top].b=y,a[top].h=z;
}
inline bool cmp(blocks x,blocks y){
    if(x.a==y.a)return x.b<y.b;
    else return x.a<y.a;
}
void clear(){
    memset(f,0,sizeof(f));
    top=0;
}
int main(){
    int cnt=0;
    while(scanf("%d",&n) && n!=0){
        cnt++;
        int ans=0;
        clear();
        for(int i=1;i<=n;i++){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            addup(x,y,z);
            addup(x,z,y);
            addup(y,z,x);
            addup(y,x,z);
            addup(z,x,y);
            addup(z,y,x);
        }
        sort(a+1,a+1+top,cmp);
        for(int i=1;i<=n;i++){
            f[i]=a[i].h;
        }
        for(int i=2;i<=top;i++){
            for(int j=i-1;j>=1;j--){
                if(a[j].a<a[i].a && a[j].b<a[i].b)f[i]=max(f[i],f[j]+a[i].h);
            }
        }
        for(int i=1;i<=top;i++){
            ans=max(ans,f[i]);
        }
        printf("Case %d: maximum height = %d\n",cnt,ans);
    }
    system("pause");
    return 0;
}