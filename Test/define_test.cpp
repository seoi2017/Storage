#include<cstdio>
#define function(a,b) (a<b?a:b)
int main(){
	int x=100,y=1;
	printf("%d\n",function(x,++y));
	while(1);
	return 0;
}