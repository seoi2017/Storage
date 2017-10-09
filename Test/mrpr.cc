#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long ll_t;

ll_t factor[110], cnt;
ll_t Mul_Mod(ll_t a, ll_t b, ll_t c)
{
    if (b == 0)
        return 0;
    ll_t ans = Mul_Mod(a, b / 2, c);
    ans = (ans * 2) % c;
    if (b % 2)
        ans = (ans + a) % c;
    return ans;
}
ll_t Pow_Mod(ll_t a, ll_t b, ll_t c)
{
    if (b == 0)
        return 1;
    ll_t x = Pow_Mod(a, b / 2, c);
    if (x == 0)
        return 0;
    ll_t y = Mul_Mod(x, x, c);
    if (y == 1 && x != 1 && x != c - 1)
        return 0;
    if (b % 2)
        y = Mul_Mod(y, a, c);
    return y;
}
bool Miller_rabin(ll_t n, int timenum = 10)
{
    if (n < 2)
        return false;
    if (n == 2)
        return true;
    while (timenum--)
    {
        if (Pow_Mod(rand() % (n - 2) + 2, n - 1, n) != 1)
            return false;
    }
    return true;
}
ll_t Gcd(ll_t a, ll_t b)
{
    ll_t t;
    while (b)
    {
        t = a;
        a = b;
        b = t % b;
    }
    return a;
}
void Pollard(ll_t n);

void Factor(ll_t n)
{
    ll_t d = 2;
    while (true)
    {
        if (n % d == 0)
        {
            Pollard(d);
            Pollard(n / d);
            return;
        }
        d++;
    }
}
void Pollard(ll_t n)
{
    if (n <= 0)
        printf("error\n");
    if (n == 1)
        return;
    if (Miller_rabin(n))
    {
        factor[cnt++] = n;
        return;
    }
    ll_t i = 0, k = 2, x, y, d;
    x = y = rand() % (n - 1) + 1;
    while (i++ < 123456)
    {
        x = (Mul_Mod(x, x, n) + n - 1) % n;
        d = Gcd((y - x + n) % n, n);
        if (d != 1)
        {
            Pollard(d);
            Pollard(n / d);
            return;
        }
        if (i == k)
        {
            y = x;
            k *= 2;
        }
    }
    Factor(n);
}

int main()
{
    ll_t n, m, ans = 0LL, ans_force = 0LL, t = 1LL;
    while (~scanf("%lld%lld", &n, &m))
    {
        ans = 0LL, ans_force = 0LL, t = 1LL;
#pragma region //Force
        for (int i = 1; i <= n; i++)
        {
            t *= i;
        }
        while (t % m == 0)
        {
            t /= m;
            ans_force++;
        }
#pragma endregion
        if (!Miller_rabin(m))
        {
            cnt = 0;
            Pollard(m);
            sort(factor, factor + cnt);
            for (int i = 0; i < cnt; i++)
                printf("[%d]\n", factor[i]);
        }
        else
        {
            factor[0] = m;
            cnt = 1;
        }
        while (n % factor[cnt - 1] == 0)
        {
            ans += n / factor[cnt - 1];
            n /= factor[cnt - 1];
        }
        printf("%lld\n%lld\n", ans, ans_force);
    }
    return 0;
}