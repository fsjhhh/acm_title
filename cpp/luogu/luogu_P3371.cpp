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

const int inf = 2147483647, N = 1e4 + 10, M = 5e5 + 10;
int h[N], e[M], ne[M], w[M], idx;
int dist[N];
int n, m, s;

void add(int a, int b, int x)
{
    e[idx] = b, w[idx] = x, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra()
{
    dist[s] = 0;
    std::priority_queue<PII, std::vector<PII>, std::greater<PII>> q;
    q.push({0, s});
    while (q.size())
    {
        PII t = q.top();
        q.pop();
        int d = t.first, p = t.second;
        for (int i = h[p]; i != -1; i = ne[i])
        {
            int x = e[i];
            if (dist[x] > d + w[i])
            {
                dist[x] = d + w[i];
                q.push({dist[x], x});
            }
        }
    }
}

void solve()
{
    memset(h, -1, sizeof h);
    std::cin >> n >> m >> s;
    for (int i = 0; i <= n; i++)
        dist[i] = inf;
    while (m--)
    {
        int a, b, x;
        std::cin >> a >> b >> x;
        add(a, b, x);
    }
    dijkstra();

    for (int i = 1; i <= n; i++)
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