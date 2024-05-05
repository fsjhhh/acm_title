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
    std::vector<PLL> po(n);
    for (int i = 0; i < n; i++) {
        std::cin >> po[i].first >> po[i].second;
    }

    LL ans = 0;
    
    std::set<std::pair<PLL, LL>> s;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            if (po[i].first == po[j].first && po[i].second == po[j].second) {
                std::cout << "inf\n";
                return ;
            }

            LL dx = po[i].first - po[j].first, dy = po[i].second - po[j].second;
            LL gcd = std::__gcd(dx, dy);
            dx /= gcd, dy /= gcd;
            if (dy < 0) {
                dx = -dx;
                dy = -dy;
            }
            if (dy == 0 && dx < 0) {
                dx = -dx;
            }

            LL c = dx * po[i].first - dy * po[i].second;
            if (!s.count({{dx, dy}, c})) {
                ans ++ ;
            }
            s.insert({{dx, dy}, c});

        }
    }

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


