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

void solve() {
    int n;
    std::cin >> n;
    std::vector<LL> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        a.push_back(a[i]);
    }
    
    int m = n;
    n *= 2;
    std::vector<LL> sum(n + 1);
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i];
    }

    std::vector dp1(n + 1, std::vector<LL>(n + 1, INFL));
    std::vector dp2(n + 1, std::vector<LL>(n + 1, 0));

    for (int i = 0; i <= n; i++) {
        dp1[i][i] = dp2[i][i] = 0;
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            for (int k = i; k < j; k++) {
                dp1[i][j] = std::min(dp1[i][j], dp1[i][k] + dp1[k + 1][j] + sum[j] - sum[i - 1]);
                dp2[i][j] = std::max(dp2[i][j], dp2[i][k] + dp2[k + 1][j] + sum[j] - sum[i - 1]);
            }
        }
    }

    LL ans_mx = 0;
    LL ans_mn = INFL;
    for (int i = 1; i <= m; i++) {
        ans_mx = std::max(ans_mx, dp2[i][i + m - 1]);
        ans_mn = std::min(ans_mn, dp1[i][i + m - 1]);
    }

    std::cout << ans_mn << "\n" << ans_mx << "\n";

}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
