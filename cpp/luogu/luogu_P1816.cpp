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
    int minn;
} tr[N * 4];
int n, m, a[N];

void pushup(int u)
{
    tr[u].minn = std::min(tr[u << 1].minn, tr[u << 1 | 1].minn);
}

void build(int u, int l, int r)
{
    if (l == r)
        tr[u] = {l, r, a[l]};
    else
    {
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

int query(int u, int a, int b)
{
    if (tr[u].l >= a && tr[u].r <= b)
        return tr[u].minn;
    int mid = tr[u].l + tr[u].r >> 1;
    int minn = INF;
    if (a <= mid)
        minn = std::min(minn, query(u << 1, a, b));
    if (b > mid)
        minn = std::min(minn, query(u << 1 | 1, a, b));
    return minn;
}

void solve()
{
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    build(1, 1, n);
    while (m--)
    {
        int a, b;
        std::cin >> a >> b;
        std::cout << query(1, a, b) << " ";
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