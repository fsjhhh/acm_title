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
//#include <bits/stdc++.h>
//priority_queue 优先队列
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
    std::vector<std::string> mp(n);
    for (int i = 0; i < n; i++) {
        std::cin >> mp[i];
    }

    std::vector st(n, std::vector<bool>(m, 0));

    std::vector<int> dx = {0, -1, 0, 1}, dy = {-1, 0, 1, 0};
    std::vector<int> d = {-1, -1, n + 1, n + 1};
    auto dfs = [&](auto self, int x, int y) -> void {
        if (d[0] <= x) {
            d[0] = x;
        }
        if (d[1] <= y) {
            d[1] = y;
        }
        if (d[2] >= x) {
            d[2] = x;
        }
        if (d[3] >= y) {
            d[3] = y;
        }

        for (int i = 0; i < 4; i++) {
            int tx = x + dx[i], ty = y + dy[i];
            if (tx < 0 || ty < 0 || tx >= n || ty >= m || st[tx][ty] || mp[tx][ty] == '*') {
                continue;
            }
            st[tx][ty] = true;
            self(self, tx, ty);
        }

    };

    auto check = [&]() -> bool {
        for (int i = d[2]; i <= d[0]; i++) {
            for (int j = d[3]; j <= d[1]; j++) {
                if (mp[i][j] == '*') {
                    return false;
                }
            }
        }
        return true;
    };

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mp[i][j] == '.' && !st[i][j]) {
                d[0] = -1, d[1] = -1, d[2] = n + 1, d[3] = m + 1;
                st[i][j] = true;
                dfs(dfs, i, j);
                if (check()) {
                    ans ++ ;
                }
            }
        }
    }

    std::cout << ans << "\n";

}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
