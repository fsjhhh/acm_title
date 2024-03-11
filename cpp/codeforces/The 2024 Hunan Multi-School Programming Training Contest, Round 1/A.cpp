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
    LL h, k, v, s;
    std::cin >> h >> k >> v >> s;
    LL x = 0;
    while (h > 0) {
        v += s;
        v -= std::max(1ll, (v / 10ll));
        if (v >= k) {
            h ++ ;
        } else if (v > 0 && v < k) {
            h -- ;
            if (h <= 0) {
                h = 0;
                v = 0;
            }
        } else {
            h = 0;
            v = 0;
        }
        x += v;
        if (s > 0) {
            s -- ;
        }
    }

    std::cout << x << '\n';

}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
