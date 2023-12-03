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
    int n, x, y;
    std::cin >> n >> x >> y;
    std::vector<double> p(n);
    std::vector<std::pair<double, int>> a(n), b(n);
    double sum = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
        a[i] = {(p[i] * (100 - x) * 0.01), i};
        b[i] = {(p[i] < y ? p[i] : y), i};
        sum += p[i];
    }

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    if (a.back().second != b.back().second) {
        sum -= (a.back().first + b.back().first);
        std::cout << std::fixed << std::setprecision(10) << sum << "\n";
    } else {
        int k1 = a.size() - 2, k2 = b.size() - 2;
        double maxx = std::max(a.back().first + b[k2].first, b.back().first + a[k1].first);
        sum -= maxx;
        std::cout << std::fixed << std::setprecision(10) << sum << "\n";
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
