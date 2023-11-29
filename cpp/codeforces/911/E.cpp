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

struct SCC {
    int n;
    std::vector<std::vector<int>> edges;
    std::vector<int> stk;
    std::vector<int> dfn, low, bel;
    int cur, cnt;

    SCC() {}
    SCC(int n) {
        init(n);
    }

    void init(int n) {
        this -> n = n;
        edges.assign(n, {});
        stk.clear();
        dfn.assign(n, -1);
        low.resize(n);
        bel.assign(n, -1);
        cur = cnt = 0;
    }

    void addEdge(int u, int v) {
        edges[u].push_back(v);
    }

    void dfs(int x) {
        dfn[x] = low[x] = cur ++ ;
        stk.push_back(x);

        for (auto y : edges[x]) {
            if (dfn[y] == -1) {
                dfs(y);
                low[x] = std::min(low[x], low[y]);
            } else if (bel[y] == -1) {
                low[x] = std::min(low[x], dfn[y]);
            }
        }

        if (dfn[x] == low[x]) {
            int y;
            do {
                y = stk.back();
                bel[y] = cnt;
                stk.pop_back();
            } while (y != x);
            cnt ++ ;
        }
    }

    std::vector<int> work() {
        for (int i = 0; i < n; i++) {
            if (dfn[i] == -1) {
                dfs(i);
            }
        }
        return bel;
    }

};

void solve() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    SCC g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        u -- ;
        v -- ;
        g.addEdge(u, v);
    }

    auto bel = g.work();
    int cnt = g.cnt;
    std::vector<std::vector<int>> edges(n);
    std::vector<PLL> z(cnt);
    for (int i = 0; i < n; i++) {
        z[bel[i]].first ++ ;
        z[bel[i]].second += -a[i];
        for (auto j : g.edges[i]) {
            if (bel[i] != bel[j]) {
                edges[bel[i]].push_back(bel[j]);
            }
        }
    }

    std::vector<PLL> dp(n);
    for (int i = cnt - 1; i >= 0; i--) {
        dp[i].first += z[i].first;
        dp[i].second += z[i].second;
        for (auto j : edges[i]) {
            dp[j] = std::max(dp[j], dp[i]);
        }
    }

    auto ans = *std::max_element(dp.begin(), dp.end());

    std::cout << ans.first << " " << -ans.second << "\n";

}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}

