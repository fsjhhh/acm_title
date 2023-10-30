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

const int N = 1e5 + 10, M = 2e5 + 10;
int h[N], e[M], ne[M], w[M], idx;
LL dist[N];
bool st[N];
LL n, m, s;

void add(LL a, LL b, LL x)
{
    e[idx] = b, w[idx] = x, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra()
{
    dist[s] = 0;
    std::priority_queue<PLL, std::vector<PLL>, std::greater<PLL>> q;
    q.push({0, s});
    while (q.size())
    {
        PLL t = q.top();
        q.pop();
        LL d = t.first, p = t.second;
        if (st[p])
            continue;
        st[p] = true;
        for (LL i = h[p]; i != -1; i = ne[i])
        {
            LL x = e[i];
            if (dist[x] > d + w[i])
            {
                dist[x] = d + w[i];
                if (!st[x])
                {
                    q.push({dist[x], x});
                }
            }
        }
    }
}

void solve()
{
    memset(h, -1, sizeof h);
    std::cin >> n >> m >> s;
    for (LL i = 0; i <= n; i++)
        dist[i] = INFL;
    while (m--)
    {
        LL a, b, x;
        std::cin >> a >> b >> x;
        add(a, b, x);
    }
    dijkstra();

    for (LL i = 1; i <= n; i++)
        std::cout << dist[i] << " ";
    std::cout << std::endl;
}

int main()
{
    IOS;
    int t = 1;
    while (t--)
        solve();
    return 0;
}