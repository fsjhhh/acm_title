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

const LL mod = 998244353;
LL dp[1010];

void init() {
    dp[1] = 1;
    for (int i = 2; i <= 1001; i++) {
        for (int j = 1; j <= i / 2; j++) {
            if (i % 2 == 1 || (i % 2 == 0 && j != i / 2)) {
                dp[i] = (dp[i] + dp[j] * dp[i - j] % mod) % mod;
            }
        }
        if (i % 2 == 0) {
            dp[i] = (dp[i] + dp[i / 2] * (dp[i / 2] + 1) / 2 % mod) % mod;
        }
    }
}

void solve() {
    int n;
    std::cin >> n;
    std::cout << dp[n + 1] << "\n";
}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    init();
    while (t -- )
        solve();
    return 0;
}
