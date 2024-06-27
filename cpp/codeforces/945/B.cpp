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
    std::vector<int> a(n + 1);
    std::vector sum(n + 1, std::vector<int>(21, 0));
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        for (int j = 0; j <= 20; j++) {
            sum[i][j] = sum[i - 1][j] + (a[i] >> j & 1);
        }
    }

    int l = 1, r = n;

    auto check = [&](int x) -> bool {
        bool ok = false;
        int w = 0;
        for (int i = 1, j = x; j <= n; i++, j++) {
            int res = 0;
            for (int k = 0; k <= 20; k++) {
                if (sum[j][k] - sum[i - 1][k]) {
                    res |= (1 << k);
                }
            }
            if (!ok) {
                ok = true;
                w = res;
            } else {
                if (w != res) {
                    return false;
                }
            }
        }
        return true;
    };

    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    std::cout << l << "\n";
}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
