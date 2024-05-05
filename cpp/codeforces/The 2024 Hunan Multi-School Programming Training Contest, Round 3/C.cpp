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

// void solve() {
//     LL n, k;
//     std::cin >> n >> k;
//     std::priority_queue<LL> q;
//     for (int i = 0; i < n; i++) {
//         int x;
//         std::cin >> x;
//         q.push(x);
//     }
//
//     while (q.size() >= k) {
//         std::vector<LL> a(k);
//         for (int i = 0; i < k; i++) {
//             a[i] = q.top();
//             q.pop();
//         }
//
//         for (int i = 0; i < k; i++) {
//             if (a[i] - (a.back() + 1) / 2 > 0) {
//                 q.push(a[i] - (a.back() + 1) / 2);
//             }
//         }
//     }
//
//     int w = q.size();
//     if (w == 0) {
//         std::cout << 0 << "\n";
//         return ;
//     }
//     std::vector<LL> a(w);
//     for (int i = 0; i < w; i++) {
//         a[i] = q.top();
//         q.pop();
//     }
//
//     LL ans = 0;
//     for (int i = 1; i < k; i++) {
//         if (i >= a.size()) {
//             ans += a[0];
//         } else {
//             ans += (a[0] - a[i]);
//         }
//     }
//
//     std::cout << ans << "\n";
//
// }

void solve() {
    LL n, k;
    std::cin >> n >> k;
    std::vector<LL> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end(), std::greater());
    LL sum1 = 0;
    for (int i = 0; i < k; i++) {
        sum1 += (a[0] - a[i]);
    }
    LL sum2 = 0;
    for (int i = k; i < n; i++) {
        sum2 += a[i];
    }

    if (sum1 >= sum2) {
        std::cout << (sum1 - sum2) << "\n";
    } else {
        std::cout << (k - (sum2 - sum1) % k == k ? 0 : k - (sum2 - sum1) % k) << "\n";
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
