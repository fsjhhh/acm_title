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
    std::vector<std::array<LL, 3>> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i][0] >> a[i][1];
        a[i][2] = i;
    }

    LL tot = n / 2;
    std::cout << tot << "\n";
    std::sort(a.begin(), a.end(), [&](std::array<LL, 3> x, std::array<LL, 3> y) -> bool {
        if (x[0] == y[0]) {
            return x[1] < y[1];
        }
        return x[0] < y[0];
    });

    for (int i = 0; i < n; i += 2) {
        if (i == n - 1) {
            break;
        }
        std::cout << a[i][2] + 1 << " " << a[i + 1][2] + 1 << "\n";
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
