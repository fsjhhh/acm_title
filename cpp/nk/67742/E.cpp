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
    std::vector<int> a(n), _1, _2;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        if (a[i] == 1) {
            _1.push_back(i);
        } else {
            _2.push_back(i);
        }
    }

    int ans = 0;
    while (_1.size() && _2.size()) {
        int l1 = _1.back(), l2 = _2.back();
        if (l1 < l2) {
            _1.pop_back();
            while (l1 < _2.back() && _2.size()) {
                _2.pop_back();
            }
        } else {
            _2.pop_back();
            while (l2 < _1.back() && _1.size()) {
                _1.pop_back();
            }
        }
        ans ++ ;
    }

    ans += _1.size();
    ans += _2.size();
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
