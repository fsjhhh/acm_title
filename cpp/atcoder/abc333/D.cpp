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
    std::vector<std::vector<int>> edges(n);
    for (int i = 0; i < n - 1; i++) {
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
    int ans = INF;
    
    for (auto v : edges[0]) {
        ans = std::min(n - siz[v], ans);
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
