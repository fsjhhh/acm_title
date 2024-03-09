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
    std::vector<LL> sum(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        std::cin >> x;
        sum[i] = sum[i - 1] + x;
    }

    int q;
    std::cin >> q;
    while (q -- ) {
        LL l, u;
        std::cin >> l >> u;
        auto it = std::lower_bound(sum.begin() + l, sum.end(), u + sum[l - 1]);
        if (it == sum.end()) {
            std::cout << n << " ";
            continue;
        }
        if (*it == u + sum[l - 1] || (it - sum.begin()) == l) {
            std::cout << (it - sum.begin()) << " ";
        } else {
            LL r = (it - sum.begin());
            LL s1 = (sum[r] - sum[l - 1]), s2 = (sum[r - 1] - sum[l - 1]);
            if (s1 * (u + (u - s1 + 1)) / 2 <= s2 * (u + (u - s2 + 1)) / 2) {
                std::cout << r - 1 << " ";
            } else {
                std::cout << r << " ";
            }
        }
    }

    std::cout << "\n";

}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
