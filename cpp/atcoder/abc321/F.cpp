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
    LL q, k;
    std::cin >> q >> k;

    std::vector<LL> dp(k + 1, 0);
    dp[0] = 1;
    while (q--) {
        char op;
        LL a;
        std::cin >> op >> a;
        if (op == '+') {
            for (int i = k; i >= a; i--) {
                dp[i] += dp[i - a];
                if (dp[i] >= mod) {
                    dp[i] -= mod;
                }
            }
        } else {
            std::vector<LL> dp2(k + 1, 0);
            for (int i = 0; i <= k; i++) {
                if (i < a) {
                    dp2[i] = dp[i];
                } else {
                    dp2[i] = dp[i] - dp2[i - a];
                    if (dp2[i] < 0) {
                        dp2[i] += mod;
                    }
                }
            }
            dp.swap(dp2);
        }

        std::cout << dp[k] << "\n";

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
