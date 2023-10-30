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

const int N = 1e5 + 10;

struct Node
{
    LL l, r;
    LL sum, tags;
} tr[N * 4];
LL n, m, a[N];

void pushup(LL u)
{
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void build(LL u, LL l, LL r)
{
    if (l == r)
        tr[u] = {l, r, a[l], 0};
    else
    {
        tr[u] = {l, r};
        LL mid = l + r >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        tr[u].tags = 0;
        pushup(u);
    }
}

void tag(LL u)
{
    LL mid = tr[u].l + tr[u].r >> 1;
    tr[u << 1].tags += tr[u].tags;
    tr[u << 1 | 1].tags += tr[u].tags;
    tr[u << 1].sum += tr[u].tags * (mid - tr[u].l + 1);
    tr[u << 1 | 1].sum += tr[u].tags * (tr[u].r - mid);
    tr[u].tags = 0;
}

void modify(LL u, LL a, LL b, LL x)
{
    if (tr[u].l >= a && tr[u].r <= b)
    {
        tr[u].tags += x;
        tr[u].sum += (tr[u].r - tr[u].l + 1) * x;
        return;
    }
    tag(u);
    LL mid = tr[u].l + tr[u].r >> 1;
    if (a <= mid)
        modify(u << 1, a, b, x);
    if (b > mid)
        modify(u << 1 | 1, a, b, x);
    pushup(u);
}

LL query(LL u, LL a, LL b)
{
    if (tr[u].l >= a && tr[u].r <= b)
        return tr[u].sum;
    LL mid = tr[u].l + tr[u].r >> 1;
    tag(u);
    LL sum = 0;
    if (a <= mid)
        sum += query(u << 1, a, b);
    if (b > mid)
        sum += query(u << 1 | 1, a, b);
    return sum;
}

void solve()
{
    std::cin >> n >> m;
    for (LL i = 1; i <= n; i++)
        std::cin >> a[i];
    for (LL i = n - 1; i >= 1; i--)
        a[i + 1] = a[i + 1] - a[i];
    build(1, 1, n);
    while (m--)
    {
        LL opt;
        std::cin >> opt;
        if (opt == 1)
        {
            LL a, b, k, d;
            std::cin >> a >> b >> k >> d;
            modify(1, a, a, k);
            if (a + 1 <= b)
                modify(1, a + 1, b, d);
            if (b < n)
                modify(1, b + 1, b + 1, -(k + d * (b - a)));
        }
        else
        {
            LL p;
            std::cin >> p;
            std::cout << query(1, 1, p) << std::endl;
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