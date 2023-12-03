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

const int N = 2e5 + 10;
LL ans[N], dp[N][3];

void init() {
    dp[0][0] = 1;
    for (int i = 1; i < N; i++) {
        ans[i] = (ans[i - 1] * 26ll + dp[i - 1][2]) % mod;
        dp[i][0] = ((dp[i - 1][0] + dp[i - 1][2]) * 25 + dp[i - 1][1] * 24) % mod;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
        dp[i][2] = dp[i - 1][1];
    }
}

void solve() {
    int n;
    std::cin >> n;
    std::cout << ans[n] << "\n";
}

int main() {
    IOS;
    int t = 1;
    init();
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
