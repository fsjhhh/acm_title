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
    std::vector<LL> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    if (n % 2 == 0) {
        std::cout << "YES\n";
    } else {
        std::vector<LL> dp(n, 0);
        for (int i = 1; i < n; i++) {
            if (i % 2) {
                if (a[i] < a[i - 1]) {
                    LL x = (dp[i - 1] * i + a[i - 1] - a[i] + i) / (i + 1);
                    if (x > dp[i - 1]) {
                        x = a[i - 1] - a[i];
                    }
                    dp[i] = std::max(dp[i - 1], x);
                } else {
                    dp[i] = dp[i - 1];
                }
            } else {
                if (a[i] < a[i - 1]) {
                    LL x = (dp[i - 1] * i + a[i - 1] - a[i] + i) / (i + 1);
                    if (x > dp[i - 1]) {
                        x = a[i - 1] - a[i];
                    }
                    dp[i] = x;
                } else if (a[i] - a[i - 1] < dp[i - 1] * i) {
                    dp[i] = (dp[i - 1] * i - (a[i] - a[i - 1]) + i) / (i + 1);
                }
            }
        }
        if (!dp[n - 1]) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }

}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
