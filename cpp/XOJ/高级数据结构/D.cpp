#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
// #include <unordered_map>
#include <set>
// #include <unordered_set>
#include <queue>
#include <deque>
//priority_queue 优先队列
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
    int w, va;
}tr[N * 4];
int pos[N], val[N];
int n;

void push_up(int u)
{
    tr[u].w = tr[u << 1].w + tr[u << 1 | 1].w;
}

void build(int u, int l, int r)
{
    if (l == r)
    {
        tr[u].l = tr[u].r = l;
        tr[u].w = 1;
        tr[u].va = 0;
        return ;
    }
    tr[u].l = l, tr[u].r = r;
    tr[u].va = 0;
    int mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    push_up(u);
}

void modify(int u, int x, int y)
{
    if (tr[u].l == tr[u].r)
    {
        tr[u].w = 0;
        tr[u].va = y;
        return ;
    }
    if (x < tr[u << 1].w)
        modify(u << 1, x, y);
    else
        modify(u << 1 | 1, x - tr[u << 1].w, y);
    push_up(u);
}

void query(int u)
{
    if (tr[u].l == tr[u].r)
    {
        std::cout << val[tr[u].va] << " ";
        return ;
    }
    query(u << 1);
    query(u << 1 | 1);
}

void solve()
{
    while (std::cin >> n)
    {
        for (int i = 1; i <= n; i ++ )
            std::cin >> pos[i] >> val[i];
        build(1, 1, n);
        for (int i = n; i > 0; i -- )
        {
            modify(1, pos[i], i);
        }
        query(1);
        std::cout << "\n";
    }
    
}

int main()
{
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}

