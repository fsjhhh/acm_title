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
    int n, k;
    std::cin >> n >> k;
    std::vector<LL> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    if (k >= 3) {
        std::cout << 0 << "\n";
    } else if (k == 1) {
        LL ans = INFL;
        for (int i = 0; i < n; i++) {
            ans = std::min(ans, a[i]);
            for (int j = i + 1; j < n; j++) {
                ans = std::min(ans, std::abs(a[i] - a[j]));
            }
        }
        std::cout << ans << "\n";
    } else {
        LL ans = INFL;
        std::set<LL> s;
        for (int i = 0; i < n; i++) {
            s.insert(a[i]);
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                LL x = std::abs(a[i] - a[j]);
                ans = std::min(x, ans);
                auto x_1 = s.lower_bound(x);
                if (x_1 != s.end()) {
                    ans = std::min(ans, std::abs(*x_1 - x));
                }
                if (x_1 != s.begin()) {
                    x_1 -- ;
                    ans = std::min(ans, std::abs(*x_1 - x));
                }
            }
        }

        std::cout << ans << "\n";

    }

}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
