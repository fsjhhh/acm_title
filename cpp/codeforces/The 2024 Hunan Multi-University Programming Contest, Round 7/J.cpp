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
    LL C, D, R, x, y;
    std::cin >> C >> D >> R >> x >> y;
    LL ans = 0;
    if (x > y) {
        ans += (std::min(C, R) * x);
        if (R > C) {
            R -= C;
            ans += (std::min(D, R) * y);
        } 
    } else {
        ans += (std::min(D, R) * y);
        if (R > D) {
            R -= D;
            ans += (std::min(R, C) * x);
        }
    }
    std::cout << ans << "\n";
}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
