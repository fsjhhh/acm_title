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
    int n;
    std::cin >> n;
    std::vector<LL> v(n), w(n);
    std::vector<LL> dp(n * 100 + 1, INFL);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> w[i] >> v[i];
        for (int j = 100 * n; j >= v[i]; j--) {
            dp[j] = std::min(dp[j], dp[j - v[i]] + w[i]);
        }
    }

    for (int i = 100 * n - 1; i >= 1; i--) {
        dp[i] = std::min(dp[i], dp[i + 1]);
    }

    int q;
    std::cin >> q;
    while (q -- ) {
        LL w;
        std::cin >> w;
        LL l = 0, r = 100 * n;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (dp[mid] <= w) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        std::cout << l << "\n";
    }

}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
