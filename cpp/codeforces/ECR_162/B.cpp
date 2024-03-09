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
    LL n, k;
    std::cin >> n >> k;
    std::vector<PLL> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i].second;
    }

    for (int i = 0; i < n; i++) {
        std::cin >> a[i].first;
        a[i].first = std::abs(a[i].first);
    }

    std::sort(a.begin(), a.end());

    bool ok = false;
    LL ls = 0, c = 0;
    for (int i = 0, j = 0; i < n; i++) {
        j = i;
        LL sum = 0;
        while (j < n && a[j].first == a[i].first) {
            sum += a[j ++ ].second;
        }

        if (k * (a[i].first - ls) + c < sum) {
            ok = true;
            break;
        }

        c = k * (a[i].first - ls) + c - sum;
        ls = a[i].first;

        i = j - 1;

    }

    if (ok) {
        std::cout << "NO\n";
    } else {
        std::cout << "YES\n";
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
