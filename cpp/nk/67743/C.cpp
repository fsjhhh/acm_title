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

typedef unsigned long long ULL;
const int N = 1e5 + 10, P = 133;
ULL p[N];
ULL ha_pre_s[N], ha_suf_s[N], ha_pre_t[N], ha_suf_t[N];

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::string s, t;
    std::cin >> s >> t;
    if (s[0] != t[m - 1] || s[n - 1] != t[0]) {
        std::cout << "-1\n";
        return ;
    }

    std::string pre_s = " " + s, pre_t = " " + t;
    std::string suf_s(s.rbegin(), s.rend()), suf_t(t.rbegin(), t.rend());
    suf_s = " " + suf_s, suf_t = " " + suf_t;

    p[0] = 1;
    for (int i = 1; i <= std::max(m, n); i++) {
        p[i] = p[i - 1] * P;
    }

    for (int i = 1; i <= n; i++) {
        ha_pre_s[i] = ha_pre_s[i - 1] * P + pre_s[i];
        ha_suf_s[i] = ha_suf_s[i - 1] * P + suf_s[i];
    }
    for (int i = 1; i <= m; i++) {
        ha_pre_t[i] = ha_pre_t[i - 1] * P + pre_t[i];
        ha_suf_t[i] = ha_suf_t[i - 1] * P + suf_t[i];
    }

    int x = 1, y = 1;
    for (int i = 1; i <= std::min(m, n); i++) {
        if (pre_s[i] == suf_t[i]) {
            x = i;
        } else {
            break;
        }
    }
    for (int i = 1; i <= std::min(m, n); i++) {
        if (suf_s[i] == pre_t[i]) {
            y = i;
        } else {
            break;
        }
    }

    std::vector<int> pre_hu, suf_hu;
    for (int i = 1; i <= x; i++) {
        ULL q = ha_pre_s[i], h = ha_suf_s[n] - ha_suf_s[n - i] * p[n - (n - i)];
        if (q == h) {
            pre_hu.push_back(i);
        }
    }
    pre_hu.push_back(INF);
    for (int i = 1; i <= y; i++) {
        ULL q = ha_pre_s[n] - ha_pre_s[n - i] * p[n - (n - i)], h = ha_suf_s[i];
        if (q == h) {
            suf_hu.push_back(i);
        }
    }
    suf_hu.push_back(INF);

    int ans = 2;
    for (auto it : pre_hu) {
        if (it == INF) {
            continue;
        }
        auto z = std::upper_bound(suf_hu.begin(), suf_hu.end(), std::min(n, m) - it);
        if (z == suf_hu.begin()) {
            continue;
        }
        z -- ;
        int w = it + (*z);
        ans = std::max(ans, w);
    }

    std::cout << 2 * ans << "\n";

}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
