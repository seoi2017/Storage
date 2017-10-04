#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxl=5000000;
int te,p[2*maxl+5];
char s[maxl+5],now[2*maxl+5];
bool Eoln(char ch) {return ch==10||ch==13||ch==EOF;}
int reads(char *x)
{
    int len=0;char ch=getchar();if (ch==EOF) return EOF;
    s[++len]=ch;while (!Eoln(s[len])) s[++len]=getchar();s[len--]=0;
    return len;
}
int Manacher(char *s)
{
    int len=strlen(s+1);
    for (int i=1;i<=len;i++) now[2*i-1]='%',now[2*i]=s[i];
    now[len=len*2+1]='%';
    int pos=0,R=0;
    for (int i=1;i<=len;i++)
    {
        if (i<R) p[i]=min(p[2*pos-i],R-i); else p[i]=1;
        while (1<=i-p[i]&&i+p[i]<=len&&now[i-p[i]]==now[i+p[i]]) p[i]++;
        if (i+p[i]>R) {pos=i;R=i+p[i];}
    }
    int MAX=0;
    for (int i=1;i<=len;i++) MAX=max(MAX,p[i]-1);
    return MAX;
}
int main()
{
    reads(s),printf("%d\n",Manacher(s));
    system("pause");
    return 0;
}