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
    int l, r;
    int sum, tags;
} tr[N * 10];

int n, m;

void pushup(int u)
{
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void build(int u, int l, int r)
{
    if (l == r)
        tr[u] = {l, r, 0, 0};
    else
    {
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void tag(int u)
{
    if (tr[u].tags == 0)
        return;
    tr[u << 1].sum = tr[u << 1].r - tr[u << 1].l + 1 - tr[u << 1].sum;
    tr[u << 1 | 1].sum = tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1 - tr[u << 1 | 1].sum;
    if (tr[u << 1].tags == 0)
        tr[u << 1].tags = 1;
    else
        tr[u << 1].tags = 0;

    if (tr[u << 1 | 1].tags == 0)
        tr[u << 1 | 1].tags = 1;
    else
        tr[u << 1 | 1].tags = 0;
    tr[u].tags = 0;
}

void modify(int a, int b, int u)
{
    if (tr[u].l >= a && tr[u].r <= b)
    {
        tr[u].sum = tr[u].r - tr[u].l + 1 - tr[u].sum;
        if (tr[u].tags == 0)
            tr[u].tags = 1;
        else
            tr[u].tags = 0;
        return;
    }
    tag(u);
    int mid = tr[u].l + tr[u].r >> 1;
    int sum = 0;
    if (a <= mid)
        modify(a, b, u << 1);
    if (b > mid)
        modify(a, b, u << 1 | 1);
    pushup(u);
}

int query(int a, int b, int u)
{
    if (tr[u].l >= a && tr[u].r <= b)
        return tr[u].sum;
    tag(u);
    int mid = tr[u].l + tr[u].r >> 1;
    int sum = 0;
    if (a <= mid)
        sum += query(a, b, u << 1);
    if (b > mid)
        sum += query(a, b, u << 1 | 1);
    return sum;
}

void solve()
{
    std::cin >> n >> m;
    build(1, 1, n);
    while (m--)
    {
        int c, a, b;
        std::cin >> c >> a >> b;
        if (c == 0)
            modify(a, b, 1);
        else
            std::cout << query(a, b, 1) << std::endl;
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