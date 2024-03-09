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

const LL mod = 1e9 + 7;

void solve() {
    LL n;
    std::cin >> n;

    if (n == 1) {
        std::cout << 1 << "\n";
        return ;
    }

    std::vector dp(n + 1, std::vector<LL>(n + 1, 0));

    for (int i = 0; i <= n; i++) {
        dp[0][i] = 1;
        dp[1][i] = i;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = ((dp[i][j - 1] + dp[i - 1][j - 1]) % mod + dp[i - 2][j - 1]) % mod;
        }
    }

    LL ans = 1;
    for (int i = 2; i <= n; i++) {
        ans = (ans * dp[i][i - 1]) % mod;
    }

    std::cout << ans << "\n";

}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
