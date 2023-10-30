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

const int N = 5e5 + 10;
struct Node
{
    int l, r;
    LL maxx, maxl, maxr, sum;
} tr[N * 4];

int n, m;
LL a[N];

void pushup(int u)
{
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
    tr[u].maxl = std::max(tr[u << 1].maxl, tr[u << 1].sum + tr[u << 1 | 1].maxl);
    tr[u].maxr = std::max(tr[u << 1 | 1].maxr, tr[u << 1 | 1].sum + tr[u << 1].maxr);
    tr[u].maxx = std::max(std::max(tr[u << 1].maxx, tr[u << 1 | 1].maxx), tr[u << 1].maxr + tr[u << 1 | 1].maxl);
}

void build(int u, int l, int r)
{
    if (l == r)
        tr[u] = {l, r, a[l], a[l], a[l], a[l]};
    else
    {
        int mid = (l + r) >> 1;
        tr[u] = {l, r};
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int p, int s)
{
    if (tr[u].l == tr[u].r)
        tr[u].sum = tr[u].maxl = tr[u].maxr = tr[u].maxx = s;
    else
    {
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (p <= mid)
            modify(u << 1, p, s);
        else
            modify(u << 1 | 1, p, s);
        pushup(u);
    }
}

Node query(int u, int a, int b)
{
    if (tr[u].l >= a && tr[u].r <= b)
        return tr[u];
    int mid = (tr[u].l + tr[u].r) >> 1;
    if (b <= mid)
        return query(u << 1, a, b);
    else
    {
        if (a > mid)
            return query(u << 1 | 1, a, b);
        else
        {
            Node ans, l, r;
            l = query(u << 1, a, b);
            r = query(u << 1 | 1, a, b);
            ans.maxl = std::max(l.maxl, l.sum + r.maxl);
            ans.maxr = std::max(r.maxr, r.sum + l.maxr);
            ans.maxx = std::max(std::max(l.maxx, r.maxx), l.maxr + r.maxl);
            ans.sum = l.sum + r.sum;
            return ans;
        }
    }
}

void solve()
{
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    build(1, 1, n);
    while (m--)
    {
        int op;
        std::cin >> op;
        if (op == 1)
        {
            int a, b;
            std::cin >> a >> b;
            if (a > b)
                std::swap(a, b);
            Node t = query(1, a, b);
            std::cout << t.maxx << std::endl;
        }
        else
        {
            int p, s;
            std::cin >> p >> s;
            modify(1, p, s);
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