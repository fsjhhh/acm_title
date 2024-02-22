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
    std::vector<int> L(n), R(n);
    for (int i = 0; i < n; i++) {
        std::cin >> L[i] >> R[i];
    }

    LL ans = 0;
    int l = L[0], r = R[0];
    for (int i = 1; i < n; i++) {
        if (L[i] >= l && R[i] <= r) {
            l = L[i];
            r = R[i];
        }
        if (L[i] < l && R[i] > r) {
            l = l;
            r = r;
        }
        if (R[i] < l) {
            ans += (l - R[i]);
            l = R[i];
            r = R[i];
        }
        if (L[i] > r) {
            ans += (L[i] - r);
            l = L[i];
            r = L[i];
        }
        if (R[i] <= r) {
            r = R[i];
        }
        if (L[i] >= l) {
            l = L[i];
        }
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
