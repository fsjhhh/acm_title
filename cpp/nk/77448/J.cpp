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

#define int long long

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector mp(n, std::vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> mp[i][j];
        }
    }
    
    std::vector<int> dx = {0, -1, 0, 1}, dy = {-1, 0, 1, 0};
    auto bfs = [&](int s) -> bool {
        std::vector st(n, std::vector<int>(m, 0));
        std::queue<std::array<int, 3>> q;
        q.push({0, 0, mp[0][0]});

        while (q.size()) {
            auto [x, y, a] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int tx = x + dx[i], ty = y + dy[i];
                if (tx < 0 || tx >= n || ty < 0 || ty >= m) {
                    continue;
                }
                if (st[tx][ty]) {
                    continue;
                }
                int w = (a & mp[tx][ty]);
                if ((w & s) != s) {
                    continue;
                }
                q.push({tx, ty, w});
                st[tx][ty] = 1;
            }
            if (st[n - 1][m - 1]) {
                break;
            }
        }

        return st[n - 1][m - 1];

    };

    LL ans = 0;
    for (int i = 30; i >= 0; i--) {
        if (bfs((ans + (1 << i)))) {
            ans += (1 << i);
        }
    }

    std::cout << ans << "\n";

}

signed main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
