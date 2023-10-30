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

const int N = 2e5 + 10;
struct Node
{
    LL l, r;
    LL sum, tags1, tags2;
} tr[N * 4];

LL n, m, p;
LL a[N];

void pushup(LL u)
{
    tr[u].sum = (tr[u << 1].sum + tr[u << 1 | 1].sum) % p;
}

void build(LL u, LL l, LL r)
{
    if (l == r)
        tr[u] = {l, r, a[l], 1, 0};
    else
    {
        tr[u] = {l, r};
        LL mid = l + r >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        tr[u].tags1 = 1;
        tr[u].tags2 = 0;
        pushup(u);
    }
}

void tag(LL u)
{
    LL mid = tr[u].l + tr[u].r >> 1;
    tr[u << 1].sum = (tr[u << 1].sum * tr[u].tags1 + tr[u].tags2 * (mid - tr[u].l + 1)) % p;
    tr[u << 1 | 1].sum = (tr[u << 1 | 1].sum * tr[u].tags1 + tr[u].tags2 * (tr[u].r - mid)) % p;
    tr[u << 1].tags1 = (tr[u << 1].tags1 * tr[u].tags1) % p;
    tr[u << 1 | 1].tags1 = (tr[u << 1 | 1].tags1 * tr[u].tags1) % p;
    tr[u << 1].tags2 = (tr[u << 1].tags2 * tr[u].tags1 + tr[u].tags2) % p;
    tr[u << 1 | 1].tags2 = (tr[u << 1 | 1].tags2 * tr[u].tags1 + tr[u].tags2) % p;
    tr[u].tags1 = 1;
    tr[u].tags2 = 0;
}

void modify1(LL u, LL a, LL b, LL x)
{
    if (tr[u].l >= a && tr[u].r <= b)
    {
        tr[u].tags1 = (tr[u].tags1 * x) % p;
        
        tr[u].tags2 = (tr[u].tags2 * x) % p;
        tr[u].sum = (tr[u].sum * x) % p;
        return;
    }
    tag(u);
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
        tr[u].tags2 = (tr[u].tags2 + x) % p;
        tr[u].sum = (tr[u].sum + x * (tr[u].r - tr[u].l + 1)) % p;
        return;
    }
    tag(u);
    LL mid = tr[u].l + tr[u].r >> 1;
    if (a <= mid)
        modify2(u << 1, a, b, x);
    if (b > mid)
        modify2(u << 1 | 1, a, b, x);
    pushup(u);
}

LL query(LL u, LL a, LL b)
{
    if (tr[u].l >= a && tr[u].r <= b)
        return tr[u].sum;
    tag(u);
    LL mid = tr[u].l + tr[u].r >> 1;
    LL sum = 0;
    if (a <= mid)
        sum = (sum + query(u << 1, a, b)) % p;
    if (b > mid)
        sum = (sum + query(u << 1 | 1, a, b)) % p;
    return sum;
}

void solve()
{
    std::cin >> n >> m >> p;
    for (LL i = 1; i <= n; i++)
        std::cin >> a[i];
    build(1, 1, n);
    while (m--)
    {
        LL op;
        std::cin >> op;
        if (op == 1)
        {
            LL a, b, x;
            std::cin >> a >> b >> x;
            modify1(1, a, b, x);
        }
        if (op == 2)
        {
            LL a, b, x;
            std::cin >> a >> b >> x;
            modify2(1, a, b, x);
        }
        if (op == 3)
        {
            LL a, b;
            std::cin >> a >> b;
            std::cout << query(1, a, b) << std::endl;
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