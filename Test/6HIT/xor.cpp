#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll_t;
const int N = 200007;
struct node_t
{
    node_t *lc, *rc;
    int l, r, s;
    inline void pushup()
    {
        this->s = this->lc->s ^ this->rc->s;
    }
};
node_t seg[N << 2], *root;
int n, q, top, ind[N];
node_t *build(int l, int r)
{
    node_t *now = &seg[++top];
    now->l = l, now->r = r;
    if (l == r)
    {
        if (l <= n)
            scanf("%d", &now->s);
    }
    else
    {
        node_t *&lson = now->lc, *&rson = now->rc;
        int mid = (l + r) >> 1;
        lson = build(l, mid);
        rson = build(mid + 1, r);
        now->s = lson->s ^ rson->s;
    }
    return now;
}
void update(node_t *now, int x, int c)
{
    if (now->l == now->r && now->l == c)
    {
        now->s = x;
        return;
    }
    int mid = (now->l + now->r) >> 1;
    if (c <= mid)
        update(now->lc, x, c);
    else
        update(now->rc, x, c);
    now->pushup();
}
int query(node_t *now, int l, int r)
{
    if (l <= now->l && now->r <= r)
        return now->s;
    int res = 0, mid = (now->l + now->r) >> 1;
    if (l <= mid)
        res ^= query(now->lc, l, r);
    if (r > mid)
        res ^= query(now->rc, l, r);
    return res;
}
//======================
inline int lowbit(int x)
{
    return x & (-x);
}
inline void change(int t, int value)
{
    int i;
    for (i = t; i <= 200000; i += lowbit(i))
        ind[i] += value;
}
int getsum(int x)
{
    int i, temp = 0;
    for (i = x; i >= 1; i -= lowbit(i))
        temp += ind[i];
    return temp;
}
int command, tx, ty;
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    scanf("%d%d", &n, &q);
    root = build(1, 200000);
    for (int i = 1; i <= 200000; i++)
        change(i, 1);
    int pos = n + 1;
    for (int i = 1; i <= q; i++)
    {
        scanf("%d", &command);
        if (command == 1)
        {
            scanf("%d", &tx);
            update(root, tx, pos++);
        }
        else if (command == 2)
        {
            scanf("%d", &tx);
            update(root, 0, tx);
            change(tx, 1);
        }
        else
        {
            scanf("%d%d", &tx, &ty);
            //printf("[%d,%d]", getsum(tx), getsum(ty));
            printf("%d\n", query(root, getsum(tx), getsum(ty)));
        }
    }
    //system("pause");
    fclose(stdin);
    fclose(stdout);
    return 0;
}