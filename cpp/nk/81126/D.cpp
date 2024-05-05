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
    std::vector<LL> a(n + 1), sum1(n + 1), sum2(n + 2), sum3(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        sum1[i] = sum1[i - 1] + a[i];
        sum2[i] = sum2[i - 1] + 2 * a[i] * i;
        sum3[i] = sum3[i - 1] + a[i] * i * i;
    }

    auto calc = [&](LL x) -> LL {
        return x * (sum1[n] * x - sum2[n]) + sum3[n];
    };

    int l = 1, r = n;
    while (l < r) {
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;
        if (calc(mid1) <= calc(mid2)) {
            r = mid2 - 1;
        } else {
            l = mid1 + 1;
        }
    }

    std::cout << calc(l) << "\n";

}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
