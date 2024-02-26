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
    int n, m;
    std::cin >> n >> m;
    std::vector<LL> a(n), b(m);
    LL mx1 = -INFL, sum1 = 0, mx2 = -INFL, sum2 = 0;
    LL mn1 = INFL, sum_1 = 0, mn2 = INFL, sum_2 = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        if (sum1 > 0) {
            sum1 += a[i];
        } else {
            sum1 = a[i];
        }
        if (sum1 > mx1) {
            mx1 = sum1;
        }
        if (sum_1 > 0) {
            sum_1 = a[i];
        } else {
            sum_1 += a[i];
        }
        if (sum_1 < mn1) {
            mn1 = sum_1;
        }
    }
    for (int i = 0; i < m; i++) {
        std::cin >> b[i];
        if (sum2 > 0) {
            sum2 += b[i];
        } else {
            sum2 = b[i];
        }
        if (sum2 > mx2) {
            mx2 = sum2;
        }
        if (sum_2 > 0) {
            sum_2 = b[i];
        } else {
            sum_2 += b[i];
        }
        if (sum_2 < mn2) {
            mn2 = sum_2;
        }
    }

    LL ans = std::max({mx1 * mx2, mx1 * mn2, mn1 * mx2, mn1 * mn2});
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
