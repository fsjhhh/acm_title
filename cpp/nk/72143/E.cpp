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
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    std::vector<int> dp(n + 100);
    std::vector<int> z(n + 1);
    dp[0] = -INF;
    int idx = 0;
    for (int i = 1; i <= n; i ++ ) {
        if (a[i] > dp[idx]) {
            dp[++ idx ] = a[i];
        }
        else {
            int l = 1, r = idx;
            while (l < r) {
                int mid = (l + r) >> 1;
                if (dp[mid] >= a[i]) {
                    r = mid;
                }
                else {
                    l = mid + 1;
                }
            }
            dp[l] = a[i];
        }
        z[i] = idx;
    }

    dp.resize(n + 100, 0);
    dp[0] = INF;
    idx = 0;
    std::vector<int> h(n + 2);
    for (int i = n; i >= 1; i--) {
        if (a[i] < dp[idx]) {
            dp[++ idx ] = a[i];
            h[i] = idx;
        } else {
            int l = 1, r = idx;
            while (l < r) {
                int mid = (l + r) >> 1;
                if (dp[mid] <= a[i]) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            dp[l] = a[i];
        }
        h[i] = idx;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = std::max(ans, z[i - 1] + h[i]);
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
