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

void solve()
{
    int n;
    std::cin >> n;
    std::vector<int> cnt(n + 1);
    std::vector<PII> a(n);
    for (int i = 0; i < n; i ++ )
        std::cin >> a[i].first;
    for (int i = 0; i < n; i ++ )
        std::cin >> a[i].second;
    std::sort(a.begin(), a.end());
    LL ans = 0;
    for (int i = 1; i * i <= 2 * n; i ++ )
    {
        cnt.assign(n + 1, 0);
        for (auto [x, y] : a)
        {
            // int x = it.first, y = it.second;
            int j = i * x - y;
            if (j >= 1 && j <= n)
                ans += cnt[j];
            if (x == i)
                cnt[y] ++ ;
        }
    }
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