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
    for (int i = 1; i < n; i++) {
        int x;
        std::cin >> x;
        x -- ;

        edges[i].push_back(x);
        edges[x].push_back(i);

    }
    
    std::vector<int> siz(n);
    auto dfs1 = [&](auto self, int u, int fa) -> void {
        siz[u] = 1;
        for (auto v : edges[u]) {
            if (v == fa) {
                continue;
            }
            self(self, v, u);
            siz[u] += siz[v];
        }
    };

    dfs1(dfs1, 0, -1);

    auto dfs2 = [&](auto self, int u, int fa) -> int {
        int mx = 0, node;
        for (auto v : edges[u]) {
            if (v == fa) {
                continue;
            }
            if (mx < siz[v]) {
                mx = siz[v];
                node = v;
            }
        }

        if (siz[u] - 1 - mx >= mx) {
            return (siz[u] - 1) / 2;
        } else {
            int z = self(self, node, u);
            return z + std::min((siz[u] - 1 - 2 * z) / 2, (siz[u] - 1 - mx));
        }

    };

    std::cout << dfs2(dfs2, 0, -1) << "\n";

}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
