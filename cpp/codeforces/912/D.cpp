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
//#include <bits/stdc++.h>
//priority_queue 优先队列
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
    LL n, q;
    std::cin >> n >> q;
    std::vector<LL> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    while (q -- ) {
        LL k;
        std::cin >> k;
        std::vector<LL> b(n), ans(61, 0);
        for (int i = 0; i < n; i++) {
            b[i] = a[i];
        }
        
        auto calc = [&](int x) -> LL {
            LL cost = 0;
            for (int j = 0; j < n; j++) {
                if (!(b[j] & (1ll << x))) {
                    cost += (1ll << x) - ((1ll << (x + 1)) - 1ll & b[j]);
                }
                if (cost > k) {
                    return cost;
                }
            }
            return cost;
        };

        for (int i = 60; i >= 0; i--) {
            LL cost = calc(i);
            if (cost <= k) {
                ans[i] = 1;
                k -= cost;
                for (int j = 0; j < n; j++) {
                    if ((b[j] & (1ll << i)) == 0) {
                        b[j] = ((b[j] | (1ll << i)) & (1ll << i));
                    }
                }
            }
        }

        LL res = 0;
        for (int i = 0; i <= 60; i++) {
            res |= (ans[i] << i);
        }
        std::cout << res << "\n";

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
