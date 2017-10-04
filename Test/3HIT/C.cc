#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int n=20000007;
int T,p[n],num,tmp;
bool a[n];
inline void prime(){
    memset(a,0,sizeof(a));
    int i,j;
    for(i=2;i<n;i++){
        if(!(a[i]))p[num++]=i;
        for(j=0;(j<num && i*p[j]<n);j++){
            a[i*p[j]]=1;
            if(!(i%p[j]))break;
        }
    }
}
int main(){
    scanf("%d",&T);
    prime();
    for(int i=1;i<=T;i++){
        scanf("%d",&tmp);
        if(tmp==1){
            printf("2\n");
            continue;
        }
        int l=1,r=num;
        while(l<r){
            int mid=(l+r)>>1;
            if(p[mid]>tmp)r=mid;
            if(p[mid]<=tmp)l=mid+1;
        }
        printf("%d\n",p[l]);
    }
    system("pause");
    return 0;
}
/*
3
2 3 5 7 11
2 3 5
5
*/