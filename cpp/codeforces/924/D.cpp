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

// 贪心
// void solve() {
//     int n, a, b;
//     std::cin >> n >> a >> b;
//     std::vector<int> c(n);
//     for (int i = 0; i < n; i++) {
//         std::cin >> c[i];
//     }
//
//     std::sort(c.begin(), c.end());
//
//     LL ans = 0, q = 0;
//
//     for (int i = 2, j = 0; i < INF; i++) {
//         LL res = 0;
//         while (j < n && c[j] <= i) {
//             q += (1ll * c[j] * (c[j] - 1)) / 2ll * a;
//             j ++ ;
//         }
//         
//         for (int k = j; k < n; k++) {
//             LL x = c[k] / i, y = c[k] % i;
//             LL cnt_1 = y, cnt_2 = (i - y);
//             res += (cnt_1 * (cnt_1 - 1)) / 2 * (x + 1) * (x + 1) * a;
//             res += (cnt_2 * (cnt_2 - 1)) / 2 * x * x * a;
//             res += (cnt_1 * cnt_2) * x * (x + 1) * a;
//         }
//
//         res += q;
//         res -= 1ll * b * (i - 1);
//
//         ans = std::max(ans, res);
//
//         if (j == n) {
//             break;
//         }
//
//     }
//
//     std::cout << ans << "\n";
//
// }

// 三分
void solve() {
    int n, a, b;
    std::cin >> n >> a >> b;
    std::vector<int> c(n);
    for (int i = 0; i < n; i++) {
        std::cin >> c[i];
    }

    auto check = [&](int x) -> LL {
        LL res = 0;
        for (int i = 0; i < n; i++) {
            if (c[i] <= x) {
                res += (1ll * c[i] * (c[i] - 1)) / 2ll * a;
            } else {
                LL u = c[i] / x, v = c[i] % x;
                LL cnt_1 = v, cnt_2 = (x - v);
                res += (cnt_1 * (cnt_1 - 1) / 2) * (u + 1) * (u + 1) * a;
                res += (cnt_2 * (cnt_2 - 1) / 2) * u * u * a;
                res += (cnt_1 * cnt_2) * u * (u + 1) * a;
            }
        }
        res -= 1ll * (x - 1) * b;
        return res;
    };

    int l = 1, r = INF;
    while (l + 1 < r) {
        int mid = (r - l + 1) / 3;
        int mid_1 = l + mid, mid_2 = r - mid;
        if (check(mid_1) > check(mid_2)) {
            r = mid_2;
        } else {
            l = mid_1;
        }
    }

    std::cout << std::max(0ll, check(l)) << "\n";

}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
