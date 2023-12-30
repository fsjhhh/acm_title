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

const LL mod = 1e9 + 7;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<LL> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    std::vector<std::array<int, 65>> dp(n + 1);
    for (int i = 1; i <= n; i++) {
        dp[i][a[i]] = 1;
        for (int j = 0; j < 65; j++) {
            dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
            dp[i][j & a[i]] = (dp[i][j & a[i]] + dp[i - 1][j]) % mod;
        }
    }
    
    auto check = [&](int x) -> bool {
        int cnt = 0;
        while (x) {
            if (x & 1) {
                cnt ++ ;
            }
            x >>= 1;
        }
        return cnt == k;
    };

    LL ans = 0;
    for (int j = 0; j < 65; j++) {
        if (check(j)) {
            ans = (ans + dp[n][j]) % mod;
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
