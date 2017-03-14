#include<bits/stdc++.h>
#define N 100100
using namespace std;
typedef unsigned long long ulld_t;
int a[N],b[N],n;
ulld_t c[N],ans=0;
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&n);
    memset(b,-1,sizeof(b));
    for(int i=1;i<=n;i++){
        scanf("%d%llu",&a[i],&c[i]);
    }
    for(int i=1;i<=n;i++){
        if(b[i]!=-1)continue;//if has been visited,continue.
        int j=i;
        while(b[j]==-1){//find a path.
            b[j]=i;//push this point into path.
            j=a[j];//next point.
        }
        if(b[j]==i){//the path is a circle.
            int tot=0;//the number of points in this circle.
            while(b[j]!=-1){
                b[j]=-1;//push this point into this circle.
                j=a[j];//next point.
                tot++;
            }
            if(tot==n){
                ans=-1;//totally a circle.
            }
        }
    }
    if(ans!=-1){
        ans=0;
        for(int i=1;i<=n;i++){//get all points.
            ans+=c[i];
        }
        static ulld_t m1[N]={0},m2[N]={0};//m1 for
        for(int i=1;i<=n;i++){
            m1[a[i]]=max(m1[a[i]],c[i]);
            if(b[i]!=-1){
                m2[a[i]]=max(m2[a[i]],c[i]);
            }
        }
        for(int i=1;i<=n;i++){
            ans-=m1[i];
        }
        for(int i=1;i<=n;i++){
            if(b[i]!=-1)continue;
            ulld_t rec=0xEFFFFFFFFF;
            int j=i;
            while(b[j]==-1){
                rec=min(rec,m1[j]-m2[j]);
                b[j]=-2;
                j=a[j];
            }
            ans+=rec;
        }
        printf("%llu\n",ans);
    }
    else printf("0\n");
    fclose(stdin);
    fclose(stdout);
    return 0;
}