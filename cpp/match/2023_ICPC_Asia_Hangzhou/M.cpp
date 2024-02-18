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

#define int long long

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }

    int mx = INFL, id = 0;
    for (int i = 0; i < n; i++) {
        if (mx > a[i]) {
            mx = a[i];
            id = i;
        }
    }


    int sum_1 = 0, sum_2 = 0;
    for (int i = 0; i <= id + 1; i++) {
        sum_1 += a[i];
    }
    for (int i = id - 1; i < n; i++) {
        sum_2 += a[i];
    }
    double ans_1 = (sum_1 * 1.0) / ((id + 2) * 1.0);
    double ans_2 = (sum_2 * 1.0) / ((n - id + 1) * 1.0);

    double ans = (sum * 1.0) / (n * 1.0);
    ans = std::max({ans, ans_1, ans_2});
    std::cout << std::fixed << std::setprecision(10) << ans << "\n";


}

signed main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
