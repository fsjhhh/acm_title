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
#include <bits/stdc++.h>
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
    int n, c;
    std::cin >> n >> c;
    std::vector<int> p(n);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
    }
    std::sort(p.begin(), p.end());
    std::deque<int> a;
    LL ans = INFL;
    LL sum = 0, idx = 0;
    for (int i = 0; i < n; i++) {
        a.push_back(p[i]);
        sum += a[i];
        while (a.size() && sum > c) {
            int z = *a.begin();a.pop_front();
            sum -= z;
        }
        if (a.size() && sum == c) {
            ans = std::min(ans, (LL)*a.rbegin() - *a.begin());
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
