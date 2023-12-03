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

#define int long long
const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<PII>> edges(n);

    for (int i = 0; i < n; i++) {
        int m;
        std::cin >> m;
        for (int j = 0; j < m; j++) {
            int x, a;
            std::cin >> x >> a;
            x -- ;
            edges[i].push_back({x, a});
        }
    }
    
    std::vector<std::array<int, 2>> dp(n);
    std::vector<int> ans(n);
    std::vector<bool> st(n);
    auto dfs = [&](auto self, int u) -> void {
        if (st[u]) {
            return ;
        }
        st[u] = true;
        for (auto [v, w] : edges[u]) {
            if (w == 0) {
                ans[u] = (ans[u] + dp[u][1] % mod) % mod;
            }
            dp[u][w] ++ ;
            self(self, v);
            int res = (dp[v][0] * dp[u][1] % mod + ans[v]) % mod;
            ans[u] = (ans[u] + res) % mod;
            dp[u][0] = (dp[u][0] + dp[v][0]) % mod;
            dp[u][1] = (dp[u][1] + dp[v][1]) % mod;
        }
    };

    dfs(dfs, 0);

    std::cout << ans[0] << "\n";

}

signed main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
