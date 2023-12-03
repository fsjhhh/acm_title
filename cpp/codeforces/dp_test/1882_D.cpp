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
    int n;
    std::cin >> n;
    std::vector<LL> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<std::vector<int>> edges(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u -- ;
        v -- ;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    std::vector<LL> siz(n);
    std::vector<LL> ans(n);
    auto dfs_1 = [&](auto self, int u, int fa) -> void {
        siz[u] = 1;
        for (auto v : edges[u]) {
            if (v == fa) {
                continue;
            }
            self(self, v, u);
            siz[u] += siz[v];
            ans[0] += (a[u] ^ a[v]) * (siz[v]); 
        }
    };

    dfs_1(dfs_1, 0, -1);

    auto dfs_2 = [&](auto self, int u, int fa) -> void {
        for (auto v : edges[u]) {
            if (v == fa) {
                continue;
            }
            ans[v] = ans[u] - siz[v] * (a[u] ^ a[v]) + (n - siz[v]) * (a[u] ^ a[v]);
            self(self, v, u);
        }
    };

    dfs_2(dfs_2, 0, -1);

    for (int i = 0; i < n; i++) {
        std::cout << ans[i] << " \n"[i == n - 1];
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
