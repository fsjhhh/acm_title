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

const LL mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector dp(n + 1, std::vector<LL> (n + 1));
    dp[1][1] = 1;

    auto power = [&](LL x, LL y) -> LL {
        LL res = 1;
        while (y) {
            if (y & 1) {
                res = res * x % mod;
            }
            x = x * x % mod;
            y >>= 1;
        }
        return res;
    };

    auto inv = [&](LL x) -> LL {
        return power(x, mod - 2);
    };

    LL s = inv(2);
    for (int i = 2; i <= n; i++) {
        LL t = inv((power(2, i) - 1) % mod);
        dp[i][i] = s * power(2, i) % mod * t % mod;
        s = 0;
        for (int j = 1; j <= i; j++) {
            if (j == 1) {
                dp[i][j] = inv(2) * dp[i][i] % mod;
            } else {
                dp[i][j] = (inv(2) * dp[i - 1][j - 1] % mod + inv(2) * dp[i][j - 1] % mod) % mod;
            }
            s = (s + dp[i][j] * inv(power(2, i - j + 1))) % mod;
        }
    }

    for (int i = 1; i <= n; i++) {
        std::cout << dp[n][i] << " \n"[i == n];
    }

}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
