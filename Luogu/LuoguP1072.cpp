#include<bits/stdc++.h>//Accepted!
using namespace std;
typedef long long ull_t;
int n,a0,a1,b0,b1;
inline void in(int &s){
	char temp='0';s=0;
	do{
		s=s*10+temp-'0';
		temp=getchar();
	}while(temp>='0' && temp<='9');
}
inline void out(ull_t s){
	if(s>9)out(s/10);
	putchar((s%10)+'0');
}
inline int gcd(int x,int y){
    return y==0?x:gcd(y,x%y);
}
inline int check(int x){
    if(x%a1!=0)return 0;
    else return ((gcd(x/a1,a0/a1)==1)&&(gcd(b1/b0,b1/x)==1));
}
void solve(){
    //in(n);
    scanf("%d",&n);
    while(n--){
        //in(a0),in(a1),in(b0),in(b1);
        scanf("%d%d%d%d",&a0,&a1,&b0,&b1);
        ull_t ans=0;
        for(int i=1;i*i<=b1/*i<=sqrt(b1)*/;i++){
            if(b1%i==0){
                ans+=check(i);
                if(b1/i!=i)ans+=check(b1/i);
            }
        }
        //out(ans),putchar('\n');
        printf("%lld\n",ans);
    }
}
int main(){
    freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
    solve();
    fclose(stdin),fclose(stdout);
    return 0;
}