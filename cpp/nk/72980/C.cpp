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

const double eps = 1e-4;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    auto check = [&](double x) -> bool {
        double ans = 0;
        for (int i = 0; i < n; i++) {
            ans += x;
            LL z = ans;
            if (z < a[i]) {
                return true;
            } else if (z > a[i]) {
                return false;
            }
        }
        return true;
    };

    double l = 0, r = 1e9 + 10;
    while (r - l > eps) {
        double mid = (r + l) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    std::cout << std::fixed << std::setprecision(10) << l << "\n";

}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
