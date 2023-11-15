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
    std::vector<int> a(m), b(m);
    std::vector<std::vector<int>> edges(n);
    for (int i = 0; i < m; i++) {
        std::cin >> a[i];
        a[i] -- ;
    }
    for (int i = 0; i < m; i++) {
        std::cin >> b[i];
        b[i] -- ;
    }
    for (int i = 0; i < m; i++) {
        edges[a[i]].push_back(b[i]);
        edges[b[i]].push_back(a[i]);
    }

    std::vector<int> st(n, -1);
    auto dfs = [&](auto self, int u) -> bool {
        std::cerr << u << "\n";
        for (auto v : edges[u]) {
            if (st[v] == -1) {
                st[v] = !st[u];
                if (!self(self, v)) {
                    return false;
                }
            } else {
                if (st[v] == st[u]) {
                    return false;
                }
            }
        }
        return true;
    };


    for (int i = 0; i < n; i++) {
        if (st[i] == -1) {
            st[i] = 0;
        } else {
            continue;
        }
        if (!dfs(dfs, i)) {
            std::cout << "No\n";
            return ;
        }
    }
    std::cout << "Yes\n";

}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
