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
#include <iomanip> // std::fixed std::setprecision(x) 保留x位小数
#include <array>
#include <bitset>
#include <functional>
#include <ranges>
// #include <bits/stdc++.h>
// priority_queue 优先队列
// std::cout.flush(); 交互题
#define IOS                           \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(0);                  \
    std::cout.tie(0);

typedef long long LL;
typedef __int128 i128;
typedef std::pair<int, int> PII;
typedef std::pair<LL, LL> PLL;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector mp(n, std::vector<int>(m, 0));
    for (int i = 0; i < n; i++)  {
        for (int j = 0; j < m; j++) {
            std::cin >> mp[i][j];
        }
    }

    std::vector dp(n, std::vector<LL>(m, -1));
    std::vector<int> dx = {1, 2}, dy = {1, 0};
    auto dfs = [&](auto self, int x, int y) -> void {
        if (y == m - 1) {
            return ;
        }
        for (int i = 0; i < 2; i++) {
            int tx = (x + dx[i]) % n, ty = y + dy[i];
            if (ty < m && mp[tx][ty] != 1) {
                if (i == 1 && mp[(x + 1) % n][y] == 1) {
                    continue;
                }
                if (dp[tx][ty] == -1) {
                    dp[tx][ty] = dp[x][y] + 1;
                    self(self, tx, ty);
                }
            }
        }
    };

    dp[0][0] = 0;
    dfs(dfs, 0, 0);

    LL ans = INFL;
    for (int i = 0; i < n; i++) {
        if (dp[i][m - 1] != -1) {
            LL s = (i - (dp[i][m - 1] + n - 1) % n + n) % n;
            LL x = (n - s + n) % n;
            ans = std::min(ans, dp[i][m - 1] + std::min(s, x));
        }
    }

    if (ans == INFL) {
        std::cout << "-1\n";
    } else {
        std::cout << ans << "\n";
    }

}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
