#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#define A 0
#define B 1
using namespace std;
const int N=10010;
char c[2][N];
int len[2];
struct dp_t{
    int d[2][N],f[2][N];
};
dp_t s[30];
int dp[N][N];
void find(){
    for(int i=0;i<26;i++){
        for(int k=0;k<2;k++){
            int st=-1,et=-1;
            for(int j=0;j<len[i];j++){
                if(c[k][j]-'A'==i)st=j;
            }
            for(int j=len[i]-1;j>=0;j--){
                if(c[k][j]-'A'==i)et=j;
            }
            if(st!=-1){

            }
        }
    }
}
int main(){
    freopen("output.txt","w",stdout);
    int cases;
    scanf("%d",&cases);
    while(cases--){
        gets(c[A]),len[A]=strlen(c[A]);
        gets(c[B]),len[B]=strlen(c[B]);
        memset(s,0,sizeof(s));
        memset(dp[0],0,sizeof(dp[0]));
        dp[0][0]=0;
        find();
        for(int i=0;i<len[A];i++){
            memset(dp[i+1],0,sizeof(dp[i+1]));
            for(int j=0;j<len[B];j++){
                if(i<len[A])
            }
        }
    }
    return 0;
}