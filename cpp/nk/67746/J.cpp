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
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::vector<std::vector<int>> edges(n);
    for (int i = 1; i < n; i++) {
        int j;
        std::cin >> j;
        j -- ;
        edges[i].push_back(j);
        edges[j].push_back(i);
    }

    std::vector<int> siz(n), sum(n), ko(n);
    auto dfs = [&](auto self, int u, int fa) -> void {
        siz[u] = 1;
        for (auto v : edges[u]) {
            if (v == fa) {
                continue;
            }
            self(self, v, u);
            siz[u] += siz[v];
            if (s[v] == 'R') {
                sum[u] += siz[v];
            } else {
                sum[u] += sum[v];
            }
        }
    };

    dfs(dfs, 0, -1);

    for (int i = 0; i < n; i++) {
        if (siz[i] - sum[i] == 1 && s[i] == 'R') {
            std::cout << "-1\n";
            return ;
        }
    }

    std::vector<int> ans(n);

    std::vector<int> _1(n), _2(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') {
            int u = siz[i] - sum[i];
            if (u % 3 == 0) {
                _1[i] = u;
                _2[i] = 0;
            } else if (u % 3 == 1) {
                _1[i] = u - 2;
                _2[i] = 2;
            } else {
                _1[i] = u - 1;
                _2[i] = 1;
            }
        }
    }

    auto Dfs = [&](auto self, int u, int fa, int p) -> void {
        for (auto v : edges[u]) {
            if (v == fa) {
                continue;
            }
            if (s[v] == 'R') {
                self(self, v, u, v);
            } else {
                self(self, v, u, p);
            }
        }
        if (p != -1) {
            if (_1[p]) {
                _1[p] -- ;
                ans[u] = 1;
            } else {
                _2[p] -- ;
                ans[u] = 2;
            }
        }
    };

    Dfs(Dfs, 0, -1, (s[0] == 'R' ? 0 : -1));

    for (int i = 0; i < n; i++) {
        if (ans[i] == 0) {
            ans[i] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << ans[i];
    }
    std::cout << "\n";

}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
