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

#define int long long

void solve() {
    int n;
    std::cin >> n;
    std::vector<PLL> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i].first >> a[i].second;
    }
    
    auto check = [&](int x) -> bool {
        PLL ls;
        if (x < a[0].first) {
            return false;
        } else {
            ls.first = a[0].first;
            ls.second = std::min(a[0].second, x);
        }
        for (int i = 1; i < n; i++) {
            if (a[i].first >= ls.first && a[i].second <= ls.second) {
                ls = a[i];
                continue;
            }
            if (a[i].first < ls.first && a[i].second > ls.second) {
                ls.first = std::max(a[i].first, ls.first - x);
                ls.second = std::min(a[i].second, ls.second + x);
                continue;
            }
            if (a[i].second <= ls.second) {
                if (ls.first - x <= a[i].first) {
                    ls = a[i];
                } else if (ls.first - x > a[i].first && ls.first - x <= a[i].second) {
                    ls.second = a[i].second;
                    ls.first = std::max(a[i].first, ls.first - x);
                } else {
                    return false;
                }
                continue;
            }
            if (a[i].first >= ls.first) {
                if (ls.second + x >= a[i].second) {
                    ls = a[i];
                } else if (ls.second + x < a[i].second && ls.second + x >= a[i].first) {
                    ls.first = a[i].first;
                    ls.second = std::min(a[i].second, ls.second + x);
                } else {
                    return false;
                }
                continue;
            }

        }
        return true;
    };

    int l = 0, r = 1e18;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    std::cout << l << "\n";

}

signed main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
