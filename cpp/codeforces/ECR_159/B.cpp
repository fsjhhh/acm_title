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
    LL n, p, l, t;
    std::cin >> n >> p >> l >> t;
    LL z = l + t * 7;
    LL k = n / 7, c = n % 7, k_;
    LL w1, w2, k1, k2;
    if (c != 0) {
        k_ = k + 1;
    } else {
        k_ = k;
    }

    if (k_ % 2) {
        w1 = l + 2 * t;
        k1 = k_ / 2;
        w2 = l + t;
        k2 = 1;
    } else {
        w1 = l + 2 * t;
        k1 = k_ / 2;
        w2 = l + t;
        k2 = 0;
    }
    
    LL ans;
    if (w1 * k1 >= p) {
        ans = (p + w1 - 1) / w1;
        std::cout << n - ans << "\n";
        return ;
    } else if (w1 * k1 + w2 * k2 >= p) {
        ans = k1 + k2;
        std::cout << n - ans << "\n";
        return ;
    } else {
        ans = k1 + k2;
        p -= (w1 * k1 + w2 * k2);
        ans += (p + l - 1) / l;
        std::cout << n - ans << "\n";
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
