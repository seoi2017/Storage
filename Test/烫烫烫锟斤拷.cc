#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
int main(){
    char c[256];
    memset(c,0xcc,sizeof(c));
    for(int i=0;i<256;i++){
        printf("%c",c[i]);
    }
    system("pause");
    return 0;
}