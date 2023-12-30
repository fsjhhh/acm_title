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
    int n, m;
    std::cin >> n >> m;
    std::vector<int> z_w(m + 1), z_v(m + 1);
    std::vector<std::array<int, 3>> f_w(m + 1), f_v(m + 1);
    std::vector<int> num(m + 1);
    for (int i = 1; i <= m; i++) {
        int w, v, z;
        std::cin >> w >> v >> z;
        if (!z) {
            z_w[i] = w * v;
            z_v[i] = w;
        } else {
            num[z] ++ ;
            f_w[z][num[z]] = w * v;
            f_v[z][num[z]] = w;
        }
    }
    
    std::vector<int> dp(n + 1);
    for (int i = 1; i <= m; i++) {
        for (int j = n; j >= z_v[i]; j--) {
            dp[j] = std::max(dp[j], dp[j - z_v[i]] + z_w[i]);

            if (j >= z_v[i] + f_v[i][1]) {
                dp[j] = std::max(dp[j], dp[j - z_v[i] - f_v[i][1]] + z_w[i] + f_w[i][1]);
            }
            if (j >= z_v[i] + f_v[i][2]) {
                dp[j] = std::max(dp[j], dp[j - z_v[i] - f_v[i][2]] + z_w[i] + f_w[i][2]);
            }
            if (j >= z_v[i] + f_v[i][1] + f_v[i][2]) {
                dp[j] = std::max(dp[j], dp[j - z_v[i] - f_v[i][1] - f_v[i][2]] + z_w[i] + f_w[i][1] + f_w[i][2]);
            }
        }
    }

    std::cout << dp[n] << "\n";

}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
