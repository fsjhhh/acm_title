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

    std::vector<PLL> h(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> h[i].first;
    }
    for (int i = 1; i <= n; i++) {
        std::cin >> h[i].second;
    }

    std::sort(h.begin() + 1, h.end());
    std::vector<LL> a(n + 1, 0), sum(n + 1, 0), vis1(n + 1, 0), vis2(n + 1, 0);

    LL ans = 0;
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + h[i].second;
        a[i] = a[i - 1] + h[i].first;
    }

    for (int i = 1; i <= n; i++) {
        vis1[i] = sum[n] - sum[i - 1];
        vis2[i] = a[n] - a[i - 1];
    }

    for (int i = 1; i <= n; i++) {
        LL tmp = vis1[i] - vis2[i];
        LL k = h[i].first - 1;
        k *= (n - i + 1);
        tmp += k;
        ans = std::max(ans, tmp);
    }

    std::cout << ans << "\n";

}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
