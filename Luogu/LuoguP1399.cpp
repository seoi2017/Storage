#include<bits/stdc++.h>//WA...
using namespace std;
const int N=10010;
struct segnode_t{}seg[N];
inline void in(int &s){
    char temp='0';s=0;do{s=s*10+temp-'0';temp=getchar();}while(temp>='0' && temp<='9');
}
inline void out(int s){
    if(s>9)out(s/10);putchar((s%10)+'0');
}
void input(){

}
void solve(){
    
}
int main(){
    freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
    int a;in(a),out(a);
    fclose(stdin),fclose(stdout);
    return 0;
}