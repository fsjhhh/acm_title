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
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::vector<int>> a(n), b(m);
    for (int i = 0; i < k; i++) {
        int u, v;
        std::cin >> u >> v;
        u -- ;
        v -- ;
        a[u].push_back(v);
        b[v].push_back(u);
    }

    double ans_1 = 0, ans_2 = 0;
    for (int i = 0; i < n; i++) {
        double q = 1;
        if (!a[i].size()) {
            continue;
        }
        for (auto it : a[i]) {
            q = q * (1.0 - 1.0 / (b[it].size() * 1.0));
        }
        ans_1 += (1.0 - q);
    }

    for (int i = 0; i < m; i++) {
        double q = 1;
        if (!b[i].size()) {
            continue;
        }
        for (auto it : b[i]) {
            q = q * (1.0 - 1.0 / (a[it].size() * 1.0));
        }
        ans_2 += (1.0 - q);
    }
    

    std::cout << "float\n";
    std::cout << std::fixed << std::setprecision(10) << ans_1 << " " << ans_2 << "\n";
}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
