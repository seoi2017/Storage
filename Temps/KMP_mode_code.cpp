//KMP算法模板
//2017/2/27 18:31
//Powered by Inv.
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define MAX_STRING 256
using namespace std;
char a[MAX_STRING], b[MAX_STRING]; //a串为目标串，b串为模式串，要求在目标串中找到模式串。
int next[MAX_STRING];              //next数组。
void find_next(char str[])
{                          //写成"char* str"也可。
    int len = strlen(str); //取字符串长度。
    next[0] = -1;          //第0位不可能有公共前后缀，故值为-1。
    for (int i = 1, j; i < len; i++)
    {                    //从第1位开始寻找每位的next值。
        j = next[i - 1]; //得到前一位的next值
        while ((j >= 0) && (str[j + 1] != str[i]))
        {                //如果j>=0则说明前一位有公共前后缀，若从上一位公共前后缀的下一位开始失配，则通过已有的next值向前回溯。
            j = next[j]; //通过已有的next值向前回溯，直到找到公共前后缀(str[j+1]==str[i])或者完全不匹配(j==-1)。
        }
        //到这里，第i位的公共前后缀计算完成。
        if (str[i] == str[j + 1])
        {                    //若找到公共前后缀。
            next[i] = j + 1; //得到第i位的next为j+1。
        }
        else
        {                 //若没有找到。
            next[i] = -1; //就设next为-1。
        }
    }
}
bool KMP(char str[], char ptr[])
{                           //str为目标串，ptr为模板串。
    int slen = strlen(str); //取目标串长度。
    int plen = strlen(ptr); //取模板串长度。
    int s_tr = 0, p_tr = 0; //字符串位数下标指针。
    while (s_tr < slen && p_tr < plen)
    { //保证不越界。
        if (str[s_tr] == ptr[p_tr])
        {                   //若字符匹配。
            s_tr++, p_tr++; //指针前移一位。
        }
        else
        { //若失配。
            if (p_tr == 0)
            {           //若模式串指针指向第一位。
                s_tr++; //目标串指针前移一位。
            }
            else
            {
                p_tr = next[p_tr - 1] + 1; //模式串指针跳转到模式串失配前一位的next位。
            }
        }
    }
    return (p_tr == plen ? true : false); //若模式串指针指向模式串尾部，则匹配完成，反之则失败。
}
int main()
{
    memset(next, -1, sizeof(next)); //初始化为-1。
    scanf("%s%s", a, b);
    find_next(b);                                   //找到模式串每一位的next值。
    KMP(a, b) ? printf("YES!\n") : printf("NO!\n"); //函数KMP为KMP算法的主体，这里使用布尔类型，返回TRUE为找到匹配，返回FALSE为无匹配。
    system("pause");
    return 0;
}