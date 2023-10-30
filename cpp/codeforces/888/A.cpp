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

const int N = 55;
LL a[N];

void solve()
{
    LL n, m, k, h;
    std::cin >> n >> m >> k >> h;
    for (int i = 1; i <= n; i ++ )
        std::cin >> a[i];

    std::set<LL> s;
    for (int i = 1; i < m; i ++ )
    {
        s.insert(i * k);
    }

    LL ans = 0;
    for (int i = 1; i <= n; i ++ )
    {
        if (s.find(abs(h - a[i])) != s.end())
        {
            ans ++ ;
        }
    }
    std::cout << ans << "\n";

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