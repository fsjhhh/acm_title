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
    std::vector<int> a(n + 2), b(n + 2);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        b[i] = a[i] - i;
    }
    
    b[n + 1] = INF;
    std::vector<std::vector<int>> edges(n + 5);
    std::vector<int> d, lo(n + 10);
    int len = 0;
    d.push_back(0);
    for (int i = 1; i <= n + 1; i++) {
        int l = 0, r = d.size() - 1;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (d[mid] <= b[i]) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }

        if (l == (int)d.size() - 1) {
            d.push_back(b[i]);
        } else {
            d[l + 1] = b[i];
        }

        lo[i] = l + 1;
        edges[lo[i]].push_back(i);

    }

    edges[0].push_back(0);
    
    std::cout << n - (d.size() - 2) << "\n";

    std::vector<LL> dp(n + 3, INFL);
    std::vector<LL> sumL(n + 10, 0), sumR(n + 10, 0);
    b[0] = -INF, dp[0] = 0;
    for (int i = 1; i <= n + 1; i++) {
        for (auto j : edges[lo[i] - 1]) {
            if (j > i || b[j] > b[i]) {
                continue;
            }

            sumL[j] = 0;
            for (int k = j + 1; k <= i - 1; k++) {
                sumL[k] = sumL[k - 1] + abs(b[k] - b[j]);
            }

            sumR[i - 1] = 0;
            for (int k = i - 2; k >= j; k--) {
                sumR[k] = sumR[k + 1] + abs(b[k + 1] - b[i]);
            }

            for (int k = j; k <= i - 1; k++) {
                dp[i] = std::min(dp[i], dp[j] + sumL[k] + sumR[k]);
            }

        }
    }

    std::cout << dp[n + 1] << "\n";

}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
