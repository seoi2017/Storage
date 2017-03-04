//洛谷P3375 【模板】KMP字符串匹配
//2017/2/27 18:53
//Powered by Inv.
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define MAX_STRING 1000010
using namespace std;
char a[MAX_STRING],b[MAX_STRING];
int next[MAX_STRING];
void find_next(char str[]){
    int len=strlen(str);
    next[0]=-1;
    for(int i=1,j;i<len;i++){
        j=next[i-1];
        while((j>=0)&&(str[j+1]!=str[i])){
            j=next[j];
        }
        if(str[i]==str[j+1]){
            next[i]=j+1;
        }
        else{
            next[i]=-1;
        }
    }
}
void KMP(char str[],char ptr[]){
    int slen=strlen(str);
    int plen=strlen(ptr);
    int s_tr=0,p_tr=0;
    while(s_tr<slen && p_tr<plen){
        if(str[s_tr]==ptr[p_tr]){
            s_tr++,p_tr++;
            if(p_tr==plen){
                printf("%d\n",s_tr-p_tr+1);
                s_tr--,p_tr=0;
            }
        }
        else{
            if(p_tr==0){
                s_tr++;
            }
            else{
                p_tr=next[p_tr-1]+1;
            }
        }
    }
}
int main(){
    memset(next,-1,sizeof(next));
    scanf("%s%s",a,b);
    find_next(b);
    KMP(a,b);
    for(int i=0;i<strlen(b);i++){
        printf("%d ",next[i]+1);
    }
    system("pause");
    return 0;
}