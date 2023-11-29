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
    std::string s;
    std::cin >> s;
    s = " " + s;
    std::vector<int> l(n + 1), r(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> l[i] >> r[i];
    }

    std::vector<int> dp(n + 1);

    auto dfs = [&](auto self, int u, int fa) -> void {
        if (l[u] != 0) {
            if (s[u] == 'L') {
                dp[l[u]] = dp[u];
            } else if (s[u] == 'R') {
                dp[l[u]] = dp[u] + 1;
            } else {
                dp[l[u]] = dp[u] + 1;
            }
            self(self, l[u], u);
        } 
        if (r[u] != 0) {
            if (s[u] == 'R') {
                dp[r[u]] = dp[u];
            } else if (s[u] == 'L') {
                dp[r[u]] = dp[u] + 1;
            } else {
                dp[r[u]] = dp[u] + 1;
            }
            self(self, r[u], u);
        }
    };

    dfs(dfs, 1, 0);
    
    int ans = INF;
    for (int i = 1; i <= n; i++) {
        if (l[i] == 0 && r[i] == 0) {
            ans = std::min(ans, dp[i]);
        }
    }

    std::cout << ans << "\n";

}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
