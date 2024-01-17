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

LL calc(LL x) {
    auto s = std::to_string(x);
    int n = s.size();
    
    LL ans = 0;
    for (int m = 1; m <= 9 * n; m++) {
        std::vector dp(n, std::vector(9 * n + 1, std::vector<LL>(9 * n + 1, -1)));
        
        auto dfs = [&](auto self, int pos, int sum, int mod, bool is_limit) -> LL {
            if (sum > m) {
                return 0;
            }
            if (pos == n) {
                return (sum == m && mod == 0);
            }
            if (!is_limit && dp[pos][sum][mod] != -1) {
                return dp[pos][sum][mod];
            }

            LL ans = 0;
            for (int i = 0; i <= (is_limit ? s[pos] - '0' : 9); i++) {
                ans += self(self, pos + 1, sum + i, (mod * 10 + i) % m, (is_limit && i == s[pos] - '0'));
            }

            dp[pos][sum][mod] = ans;
            return ans;
            
        };

        ans += dfs(dfs, 0, 0, 0, true);
    }

    return ans;

}

void solve() {
    LL n;
    std::cin >> n;
    std::cout << calc(n) << "\n";
}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
