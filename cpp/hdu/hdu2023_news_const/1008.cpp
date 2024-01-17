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
    std::vector<LL> v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }
    std::sort(v.begin(), v.end());
    LL k;
    std::cin >> k;

    int l = v[0] + v[1];
    int r = v[n - 1] + v[n - 2];

    while (l < r) {
        int mid = (l + r) / 2;
        int count = 0;

        for (int i = 0; i < n - 1; i++) {
            count += upper_bound(v.begin() + i + 1, v.end(), mid - v[i]) - (v.begin() + i + 1);
        }

        if (count < k) {
            l = mid + 1;
        } else {
            r = mid;
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
