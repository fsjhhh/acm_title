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
std::vector<PII> d[N];
std::vector<int> f(N);
int n;

void dfs(int u, int x, int y)
{
    for (auto i : d[u])
    {
        if (i.second != x)
        {
            if (i.first > y)
                f[i.second] = f[u];
            else
                f[i.second] = f[u] + 1;
            dfs(i.second, u, i.first);
        }
    }
}

void solve()
{
    std::cin >> n;
    for (int i = 1; i <= n; i ++ )
    {
        f.push_back(0);
        d[i].clear();
    }    
    for (int i = 1; i < n; i ++ )
    {
        int x, y;
        std::cin >> x >> y;
        d[x].push_back({i, y});
        d[y].push_back({i, x});
    }
    f[1] = 1;
    dfs(1, 0, 0);
    int ans = 0;
    for (int i = 1; i <= n; i ++ )
        ans = std::max(ans, f[i]);
    std::cout << ans << std::endl;
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