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
    int n, k;
    std::cin >> n >> k;

    std::vector mp(n, std::vector<int>(n));
    std::vector dis(n, std::vector<LL>(n));
    
    std::vector<std::vector<PII>> di(k + 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> mp[i][j];
            di[mp[i][j]].push_back({i, j});
            if (mp[i][j] == 1) {
                dis[i][j] = 0;
            } else {
                dis[i][j] = INFL;
            }
        }
    }

    LL ans = INFL;
    for (int i = 2; i <= k; i++) {
        int len1 = di[i - 1].size(), len2 = di[i].size();
        if (len1 == 0 || len2 == 0) {
            std::cout << "-1\n";
            return ;
        }

        if (len1 >= n) {
            std::vector<LL> c(n, INFL), r(n, INFL);
            for (int j = 0; j < len1; j++) {
                int x = di[i - 1][j].first, y = di[i - 1][j].second;
                c[x] = std::min(c[x], dis[x][y]);
                r[y] = std::min(r[y], dis[x][y]);
            }
            for (int j = 0; j < len2; j++) {
                int x = di[i][j].first, y = di[i][j].second;
                for (int u = 0; u < n; u++) {
                    dis[x][y] = std::min(dis[x][y], c[u] + (u - x) * (u - x));
                    dis[x][y] = std::min(dis[x][y], r[u] + (u - y) * (u - y));
                }
            }
        } else {
            for (int u = 0; u < len1; u++) {
                int x1 = di[i - 1][u].first, y1 = di[i - 1][u].second;
                for (int v = 0; v < len2; v++) {
                    int x2 = di[i][v].first, y2 = di[i][v].second;
                    dis[x2][y2] = std::min(dis[x2][y2], dis[x1][y1] + (x1 - x2) * (x1 - x2));
                    dis[x2][y2] = std::min(dis[x2][y2], dis[x1][y1] + (y1 - y2) * (y1 - y2));
                }
            }
        }
    }

    for (int i = 0; i < (int)di[k].size(); i++) {
        int x = di[k][i].first, y = di[k][i].second;
        ans = std::min(ans, dis[x][y]);
    }

    if (k == 1) {
        ans = 0;
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
