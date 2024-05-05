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
    std::string s;
    std::cin >> s;
    std::vector<LL> c(n);

    std::array<std::string, 2> a;
    for (int i = 0; i < n; i++) {
        std::cin >> c[i];
        a[0] += (i % 2 + '0');
        a[1] += ((i + 1) % 2 + '0');
    }

    std::vector<std::array<LL, 2>> pre(n, {0, 0}), suf(n, {0, 0});

    for (int i = 0; i < n; i++) {
        if (s[i] == a[0][i]) {
            pre[i][1] = c[i];
        } else {
            pre[i][0] = c[i];
        }

        if (i != 0) {
            pre[i][0] += pre[i - 1][0];
            pre[i][1] += pre[i - 1][1];
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == a[0][i]) {
            suf[i][1] = c[i];
        } else {
            suf[i][0] = c[i];
        }

        if (i != n - 1) {
            suf[i][0] += suf[i + 1][0];
            suf[i][1] += suf[i + 1][1];
        }
    }

    LL ans = INFL;
    for (int i = 0; i < n - 1; i++) {
        ans = std::min({ans, pre[i][0] + suf[i + 1][1], pre[i][1] + suf[i + 1][0]});
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
