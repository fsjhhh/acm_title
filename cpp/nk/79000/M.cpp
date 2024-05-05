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
#include <bits/stdc++.h>
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

    std::vector<std::set<int>> edges(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u -- ;
        v -- ;
        edges[u].insert(v);
        edges[v].insert(u);
    }

    std::vector<int> st(n);

    std::queue<int> q;
    q.push(0);
    st[0] = 1;
    LL sum = 1;

    std::vector<PII> adj;
    while (q.size()) {
        if (sum == n) {
            break;
        }
        int u = q.front();
        q.pop();

        for (int i = 0; i < n; i++) {
            if (st[i] || edges[u].count(i)) {
                continue;
            }

            adj.push_back({u, i});
            st[i] = 1;
            sum ++ ;
            q.push(i);

        }

    }

    if (sum < n) {
        std::cout << "NO\n";
        return ;
    }

    std::cout << "YES\n";
    std::cout << adj.size() << "\n";
    for (auto [u, v] : adj) {
        std::cout << u + 1 << " " << v + 1 << "\n";
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
