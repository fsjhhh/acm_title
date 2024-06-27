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

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    // if (n == 1) {
    //     std::cout << "0\n";
    //     return ;
    // }

    std::vector<int> pre1(n + 1), pre2(n + 1), suf1(n + 2), suf2(n + 2);
    for (int i = 1; i <= n; i++) {
        pre1[i] = pre1[i - 1] + (a[i] == 1 ? 1 : 0);
        pre2[i] = pre2[i - 1] + (a[i] == 2 ? 1 : 0);
    }
    for (int i = n; i > 0; i--) {
        suf1[i] = suf1[i + 1] + (a[i] == 1 ? 1 : 0);
        suf2[i] = suf2[i + 1] + (a[i] == 2 ? 1 : 0);
    }

    int ans = INF;
    for (int i = 0; i <= n; i++) {
        // std::cout << pre1[i] + suf2[i + 1] << " " << pre2[i] + suf1[i + 1] << "\n";
        ans = std::min({ans, pre1[i] + suf2[i + 1], pre2[i] + suf1[i + 1]});
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
