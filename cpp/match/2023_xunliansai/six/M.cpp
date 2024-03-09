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
    int x, y, z, a, b, c;
    std::cin >> x >> y >> z >> a >> b >> c;

    auto calc = [&](int w) -> int {
        if (w < 5) {
            return a;
        } else if (w < 10) {
            return b;
        } else {
            return c;
        }
    };

    int ans1 = calc(x) + calc(y) + calc(z);
    int ans2 = calc(x + y) + calc(z);
    int ans3 = calc(x + z) + calc(y);
    int ans4 = calc(y + z) + calc(x);
    int ans5 = calc(x + y + z);

    std::cout << std::min({ans1, ans2, ans3, ans4, ans5}) << "\n";


}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
