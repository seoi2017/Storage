#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define MAX_STRING 10000007
using namespace std;
char a[MAX_STRING], b[MAX_STRING];
int nxt[MAX_STRING];
void find_nxt(char str[])
{
    int len = strlen(str);
    nxt[0] = -1;
    for (int i = 1, j; i < len; i++)
    {
        j = nxt[i - 1];
        while ((j >= 0) && (str[j + 1] != str[i]))
        {
            j = nxt[j];
        }
        if (str[i] == str[j + 1])
        {
            nxt[i] = j + 1;
        }
        else
        {
            nxt[i] = -1;
        }
    }
}
int KMP(char str[], char ptr[])
{
    int slen = strlen(str);
    int plen = strlen(ptr);
    int s_tr = 0, p_tr = 0, tot = 0;
    while (s_tr < slen)
    {
        if(p_tr >= plen)
        {
            tot++;
            p_tr = 0;
        }
        if (str[s_tr] == ptr[p_tr])
        {
            s_tr++, p_tr++;
        }
        else
        {
            if (p_tr == 0)
            {
                s_tr++;
            }
            else
            {
                p_tr = nxt[p_tr - 1] + 1;
            }
        }
    }
    return tot;
}
int main()
{
    memset(nxt, -1, sizeof(nxt));
    scanf("%s%s", b, a);
    find_nxt(b);
    printf("%d\n", KMP(a, b));
    system("pause");
    return 0;
}