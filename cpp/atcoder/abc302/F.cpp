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

const int N = 2e5 + 10;
std::vector<PII> edges[N * 2];
int dist[N * 2];
int n, m;

void bfs() 
{
    std::queue<PII> q;
    dist[1] = 0;
    q.push({dist[1], 1});
    while (q.size()) {
        auto t = q.front();
        q.pop();
        int u = t.second;
        for (auto [v, w] : edges[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                q.push({dist[v], v});
            }
        }
    }
}

void solve()
{
    memset(dist, 0x3f, sizeof dist);
    std::cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) {
        int x;
        std::cin >> x;
        for (int j = 1;  j <= x; j ++ ) {
            int y;
            std::cin >> y;
            edges[y].push_back({m + i, 1});
            edges[m + i].push_back({y, 0});
        }
    }

    bfs();

    if (dist[m] == INF)
        std::cout << -1 << "\n";
    else
        std::cout << dist[m] - 1 << "\n";

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