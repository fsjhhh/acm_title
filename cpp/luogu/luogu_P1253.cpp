#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <deque>
// priority_queue 优先队列
#define IOS                           \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(0);                  \
    std::cout.tie(0);

typedef long long LL;
typedef std::pair<int, int> PII;
typedef std::pair<LL, LL> PLL;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;

const int N = 2e6 + 10;
struct Node
{
    LL l, r;
    LL maxx, tags1, tags2;
} tr[N * 4];
LL n, m, abc[N];

void pushup(LL u)
{
    tr[u].maxx = std::max(tr[u << 1].maxx, tr[u << 1 | 1].maxx);
}

void build(LL u, LL l, LL r)
{
    if (l == r)
        tr[u] = {l, r, abc[l], INFL, 0};
    else
    {
        tr[u] = {l, r, 0, INFL, 0};
        LL mid = l + r >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        tr[u].tags2 = 0;
        tr[u].tags1 = INFL;
        pushup(u);
    }
}

void tag1(LL u)
{
    if (tr[u].tags1 == INFL)
        return;
    tr[u << 1].tags2 = tr[u << 1 | 1].tags2 = 0;
    tr[u << 1].tags1 = tr[u].tags1;
    tr[u << 1 | 1].tags1 = tr[u].tags1;
    tr[u << 1].maxx = tr[u].tags1;
    tr[u << 1 | 1].maxx = tr[u].tags1;
    tr[u].tags1 = INFL;
}

void tag2(LL u)
{
    if (tr[u].tags2 == 0)
        return;
    tag1(u);
    tr[u << 1].tags2 += tr[u].tags2;
    tr[u << 1 | 1].tags2 += tr[u].tags2;
    tr[u << 1].maxx += tr[u].tags2;
    tr[u << 1 | 1].maxx += tr[u].tags2;
    tr[u].tags2 = 0;
}

void modify1(LL u, LL a, LL b, LL x)
{
    if (tr[u].l >= a && tr[u].r <= b)
    {
        tr[u].tags2 = 0;
        tr[u].tags1 = x;
        tr[u].maxx = x;
        return;
    }
    tag1(u);
    tag2(u);
    LL mid = tr[u].l + tr[u].r >> 1;
    if (a <= mid)
        modify1(u << 1, a, b, x);
    if (b > mid)
        modify1(u << 1 | 1, a, b, x);
    pushup(u);
}

void modify2(LL u, LL a, LL b, LL x)
{
    if (tr[u].l >= a && tr[u].r <= b)
    {
        tag1(u);
        tr[u].tags2 += x;
        tr[u].maxx += x;
        return;
    }
    tag1(u);
    tag2(u);
    LL mid = tr[u].l + tr[u].r >> 1;
    if (a <= mid)
        modify2(u << 1, a, b, x);
    if (b > mid)
        modify2(u << 1 | 1, a, b, x);
    pushup(u);
}

LL query(LL u, LL a, LL b)
{
    LL maxx = -INFL;
    if (tr[u].l >= a && tr[u].r <= b)
        return tr[u].maxx;
    tag1(u);
    tag2(u);
    LL mid = tr[u].l + tr[u].r >> 1;
    if (a <= mid)
    {
        maxx = std::max(maxx, query(u << 1, a, b));
    }
    if (b > mid)
    {
        maxx = std::max(maxx, query(u << 1 | 1, a, b));
    }
    return maxx;
}

void solve()
{
    scanf("%lld%lld", &n, &m);
    for (LL i = 1; i <= n; i++)
        scanf("%lld", &abc[i]);
    build(1, 1, n);
    while (m--)
    {
        LL op;
        scanf("%lld", &op);
        if (op == 1)
        {
            LL a, b, x;
            scanf("%lld%lld%lld", &a, &b, &x);
            modify1(1, a, b, x);
        }
        if (op == 2)
        {
            LL a, b, x;
            scanf("%lld%lld%lld", &a, &b, &x);
            modify2(1, a, b, x);
        }
        if (op == 3)
        {
            LL a, b;
            scanf("%lld%lld", &a, &b);
            printf("%lld\n", query(1, a, b));
        }
    }
}

int main()
{
    IOS;
    int t = 1;
    while (t--)
        solve();
    return 0;
}