#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
const unsigned long long M1=131,M2=13131;
int n,m,x,y;
unsigned long long h[1010][1010],hl[110][110],l1[1010],l2[1010];
char c[1010];
void get_hash(int a,int b,char t){
    h[a][b]=h[a-1][b]*M1+h[a][b-1]*M2-h[a-1][b-1]*M1*M2+t;
}
void get_hash2(int a,int b,char t){
    hl[a][b]=hl[a-1][b]*M1+hl[a][b-1]*M2-hl[a-1][b-1]*M1*M2+t;
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    l1[0]=l2[0]=1;
    for(int i=1;i<1010;i++){
        l1[i]=l1[i-1]*M1;
        l2[i]=l2[i-1]*M2;
    }
    int cases;
    scanf("%d",&cases);
    while(cases--){
        memset(h,0,sizeof(h));
        memset(hl,0,sizeof(hl));
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            scanf("%s",c+1);
            for(int j=1;j<=m;j++){
                get_hash(i,j,c[j]);
            }
        }
        scanf("%d%d",&x,&y);
        for(int i=1;i<=x;i++){
            scanf("%s",c+1);
            for(int j=1;j<=y;j++){
                get_hash2(i,j,c[j]);
            }
        }
        int ans=0;
        unsigned long long temp;
        for(int i=1;i<=n-x+1;i++){
            for(int j=1;j<=m-y+1;j++){
                temp=h[i+x-1][j+y-1]-h[i-1][j+y-1]*l1[x]-h[i+x-1][j-1]*l2[y]+h[i-1][j-1]*l1[x]*l2[y];
                if(temp==hl[x][y])ans++;
            }
        }
        printf("%d\n",ans);
    }
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}