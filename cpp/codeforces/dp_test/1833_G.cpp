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
    std::vector<std::vector<PII>> edges(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u -- ;
        v -- ;
        edges[u].push_back({v, i});
        edges[v].push_back({u, i});
    }
    
    std::vector<int> siz(n);
    std::vector<bool> cnt(n, 0);
    
    auto dfs = [&](auto self, int u, int fa) -> bool {
        siz[u] = 1;
        for (auto [v, w] : edges[u]) {
            if (v == fa) {
                continue;
            }
            if (!self(self, v, u)) {
                return false;
            }
            if (siz[v] == 3) {
                cnt[w] = true;
            } else {
                siz[u] += siz[v];
            }
        }
        return siz[u] <= 3;
    };

    if (!dfs(dfs, 0, -1) || siz[0] != 3) {
        std::cout << -1 << "\n";
        return ;
    }

    std::vector<int> ans;
    for (int i = 0; i < n - 1; i++) {
        if (cnt[i]) {
            ans.push_back(i);
        }
    }

    std::cout << ans.size() << "\n";
    for (auto it : ans) {
        std::cout << it + 1 << " ";
    }
    std::cout << "\n";

}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
