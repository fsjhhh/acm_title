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
    std::vector<std::vector<int>> edges(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        u -- ;
        v -- ;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    std::vector<int> siz(n);
    auto dfs = [&](auto self, int u, int fa) -> void {
        siz[u] = 1;
        for (auto v : edges[u]) {
            if (v == fa) {
                continue;
            }
            self(self, v, u);
            siz[u] += siz[v];
        }
    };

    dfs(dfs, 0, -1);

    auto check = [&](int x) -> bool {
        std::vector<int> c(n);
        int cnt = 0, sum = 0;
        auto dfs_1 = [&](auto self, int u, int fa) -> bool {
            if (siz[u] == x) {
                c[u] = siz[u];
                sum += c[u];
                cnt ++ ;
                return (cnt == k && (siz[0] - sum >= x));
            }
            if (siz[u] < x) {
                return false;
            }

            for (auto v : edges[u]) {
                if (v == fa) {
                    continue;
                }
                if (self(self, v, u)) {
                    return true;
                }
                c[u] += c[v];
            }

            if (siz[u] - c[u] >= x) {
                cnt ++ ;
                sum += siz[u] - c[u];
                c[u] = siz[u];
                return (cnt == k && (siz[0] - sum >= x));
            } else {
                return false;
            }

        };

        if (dfs_1(dfs_1, 0, -1)) {
            return true;
        } else {
            return false;
        }

    };

    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    std::cout << l << "\n";

}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
