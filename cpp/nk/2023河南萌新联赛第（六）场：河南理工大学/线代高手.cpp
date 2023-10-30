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

void solve()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<LL> a(n + 1), b(m + 1);
    for (int i = 1; i <= n; i ++ ) {
        std::cin >> a[i];
    }
    for (int i = 1; i <= m; i ++ ) {
        std::cin >> b[i];
    }
    std::vector mp(n + 1, std::vector<LL>(m + 1));
    std::vector sum(n + 1, std::vector<LL>(m + 1));
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 1; j <= m; j ++ ) {
            mp[i][j] = a[i] * b[j];
            sum[i][j] = mp[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }

    LL x;
    std::cin >> x;
    LL ans = 0;
    for (LL i = 1; i <= n; i ++ ) {
        for (LL j = 1; j <= m ; j ++ ) {
            for (LL k = 1; k <= i; k ++ ) {
                for (LL v = 1; v <= j; v ++ ) {
                    LL z = sum[i][j] - sum[i][v - 1] - sum[k - 1][j] + sum[k - 1][v - 1];
                    if (z <= x) {
                        // std::cout << i << " " << j << " " << k << " " << v << "\n";
                        ans = std::max(ans, (i - k + 1) * (j - v + 1));
                    }
                }
            }
        }
    }
    std::cout << ans << "\n";

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