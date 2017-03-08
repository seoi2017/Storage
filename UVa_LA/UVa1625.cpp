#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int N=10010;
string a,b,c;
int f[N][N],s[N];
void clear(){
    a.clear();
    b.clear();
    c.clear();
    for(int i=0;i<N;i++){
        s[i]=0;
        for(int j=0;j<N;j++){
            f[i][j]=0;
        }
    }
}
int dp(){
    return ;
}
int main(){
    ios::sync_with_stdio(false);
    freopen("output.txt","w",stdout);
    int cases;
    cin>>cases;
    while(cases--){
        clear();
        char temp;
        while(cin>>temp && temp!='\n'){
            s[temp]++;
            a+=temp;
        }
        while(cin>>temp && temp!='\n'){
            s[temp]++;
            b+=temp;
        }
        cout<<dp()<<endl;
    }
    return 0;
}