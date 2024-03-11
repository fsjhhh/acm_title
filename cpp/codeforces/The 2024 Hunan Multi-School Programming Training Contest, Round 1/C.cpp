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
    std::vector<std::string> mp(n);

    for (int i = 0; i < n; i++) {
        std::cin >> mp[i];
    }

    std::vector st(n, std::vector<bool>(m));

    std::vector dis(n, std::vector<int>(m));
    std::queue<PII> q;

    int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mp[i][j] == 'X') {
                for (int k = 0; k < 4; k++) {
                    int tx = i + dx[k], ty = j + dy[k];
                    if (tx < 0 || tx >= n || ty < 0 || ty >= m) {
                        q.push({i, j});
                        dis[i][j] = 1;
                        break;
                    }
                    if (mp[tx][ty] == '-') {
                        q.push({i, j});
                        dis[i][j] = 1;
                        break;
                    }
                }
            }
        }
    }

    while (q.size()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int tx = x + dx[i], ty = y + dy[i];
            if (tx < 0 || tx >= n || ty < 0 || ty >= m) {
                continue;
            }
            if (mp[tx][ty] == '-' || dis[tx][ty]) {
                continue;
            }
            q.push({tx, ty});
            dis[tx][ty] = dis[x][y] + 1;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans = std::max(ans, dis[i][j]);
        }
    }

    std::cout << ans << '\n';

}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
