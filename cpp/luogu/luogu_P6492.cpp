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
    int l, r;
    int maxx, maxl, maxr;
} tr[N * 4];

int n, m, a[N];

void pushup(int u)
{
    int mid = tr[u].l + tr[u].r >> 1;
    tr[u].maxl = tr[u << 1].maxl;
    tr[u].maxr = tr[u << 1 | 1].maxr;
    tr[u].maxx = std::max(tr[u << 1].maxx, tr[u << 1 | 1].maxx);
    if (a[mid] != a[mid + 1])
    {
        tr[u].maxx = std::max(tr[u].maxx, tr[u << 1].maxr + tr[u << 1 | 1].maxl);
        if (tr[u << 1].maxx == (mid - tr[u].l + 1))
            tr[u].maxl = (mid - tr[u].l + 1) + tr[u << 1 | 1].maxl;
        if (tr[u << 1 | 1].maxx == (tr[u].r - mid))
            tr[u].maxr = (tr[u].r - mid) + tr[u << 1].maxr;
    }
}

void build(int u, int l, int r)
{
    if (l == r)
        tr[u] = {l, l, 1, 1, 1};
    else
    {
        tr[u] = {l, r, 1, 1, 1};
        int mid = l + r >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int x)
{
    if (tr[u].l == tr[u].r)
    {
        if (tr[u].l == x)
        {

            if (a[x] == 0)
                a[x] = 1;
            else
                a[x] = 0;
            return;
        }
    }
    int mid = tr[u].l + tr[u].r >> 1;
    if (mid < x)
        modify(u << 1 | 1, x);
    else
        modify(u << 1, x);
    pushup(u);
}

void solve()
{
    std::cin >> n >> m;
    build(1, 1, n);
    while (m--)
    {
        int x;
        std::cin >> x;
        modify(1, x);
        std::cout << tr[1].maxx << std::endl;
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