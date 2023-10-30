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

const int N = 5e5 + 10;
LL p[N], dist[N];

LL find(int u)
{
    if (u != p[u])
    {
        LL t = p[u];
        p[u] = find(p[u]);
        dist[u] += dist[t];
    }
    return p[u];
}

void solve()
{
    memset(p, 0, sizeof p);
    memset(dist, 0, sizeof dist);
    LL n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i ++ )
        p[i] = i;
    bool pd = false;
    for (int i = 1; i <= m; i ++ )
    {
    	LL a, b, c;
        std::cin >> a >> b >> c;
        if (pd)
            continue;
        LL fa = find(a), fb = find(b);
        if (fa == fb)
        {
            if (dist[a] - dist[b] != c)
            {
                pd = true;
            }
        }
        else
        {
            p[fb] = a;
            dist[fb] = -c - dist[b];
        }
    }
    if (!pd)
        std::cout << "Yes" << "\n";
    else
        std::cout << "No" << "\n";
}

int main()
{
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}