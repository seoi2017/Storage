#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll_t;
ll_t n, m, ans, t = 1;
map<int, int> pri;
int main()
{
    scanf("%lld%lld", &n, &m);
    
    #pragma region //Force
    /*
    for (int i = 1; i <= n; i++)
    {
        t *= i;
    }
    while(t % m == 0)
    {
        t /= m;
        ans++;
    }
    */
    #pragma endregion
    printf("%lld\n", ans);
    system("pause");
    return 0;
}