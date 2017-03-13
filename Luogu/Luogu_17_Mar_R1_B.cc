#include<bits/stdc++.h>
#define N 110
using namespace std;
int r,c,k,ans=0;
struct node_t{
    int h,s;
    node_t(){
        this->h=0;
        this->s=0;
    }
}n[N][N];
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d%d%d",&r,&c,&k);
    char temp;
    for(int i=1;i<=r;i++){
        scanf("\n");
        for(int j=1;j<=c;j++){
            scanf("%c",&temp);
            if(temp=='.'){
                n[i][j].h=n[i][j-1].h+1;
                n[i][j].s=n[i-1][j].s+1;
                if(k!=1){
                    if(n[i][j].h>=k)ans++;
                    if(n[i][j].s>=k)ans++;
                }
                else if(n[i][j].h>=k || n[i][j].s>=k)ans++;
            }
            else if(temp=='#'){
                n[i][j].h=0;
                n[i][j].s=0;
            }
        }
    }
    /*
    for(int i=1;i<=r;i++,printf("\n")){
        for(int j=1;j<=c;j++){
            printf("[%d|%d]",n[i][j].h,n[i][j].s);
        }
    }
    */
    printf("%d\n",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}