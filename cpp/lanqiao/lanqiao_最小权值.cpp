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

const int N = 3031;
const LL inf = 1e18;
LL f[N];

LL dfs(int u)
{
    if (f[u] != inf)
        return f[u];
    for (int i = 0; i <= u - 1; i++)
    {
        f[u] = std::min(f[u], 1 + 2 * dfs(i) + 3 * dfs(u - i - 1) + i * i * (u - i - 1));
    }
    return f[u];
}

void solve()
{
    for (int i = 0; i <= 2021; i++)
        f[i] = inf;
    LL ans = dfs(2021);
    std::cout << ans << std::endl;
}

int main()
{
    IOS;
    int t = 1;
    while (t--)
        solve();
    return 0;
}