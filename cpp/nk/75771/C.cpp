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
    std::vector<PII> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i].first >> a[i].second;
    }

    std::set<PII> s;

    auto calc = [&](int h, int m, int x) -> PII {
        PII res;
        res.first = h;
        res.second = m - x;
        if (res.second < 0) {
            res.first -- ;
            res.second = 60 + res.second;
        }
        return res;
    };

    for (int i = 0; i < n; i++) {
        auto [h, m] = a[i];
        s.insert(calc(h, m, 1));
        s.insert(calc(h, m, 3));
        s.insert(calc(h, m, 5));
    }
    
    std::cout << s.size() << "\n";
    for (auto [x, y] : s) {
        std::cout << x << " " << y << "\n";
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
