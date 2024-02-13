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
    int n, k;
    std::cin >> n >> k;
    std::vector<LL> a(n + 1), sum(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    LL ans = -INFL;
    for (int i = 1; i <= n; i++) {
        LL res = -INFL;
        for (int j = 1; j <= i; j++) {
            res = sum[i] - sum[j - 1];
            if (k == 0) {
                ans = std::max(res, ans);
            } else {
                if (j != 1) {
                    res = std::max(res, res - a[j] + a[j - 1]);
                } else if (i != n) {
                    res = std::max(res, res - a[i] + a[i + 1]);
                }
                ans = std::max(ans, res);
            }
        }
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
