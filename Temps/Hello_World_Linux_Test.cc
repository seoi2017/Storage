//Linux(Ubuntu) Test
//2017/3/8 21:08
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int a,b;
    cin>>a>>b;
    int c=a+b;
    cout<<c<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}