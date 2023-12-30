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
    int n, m, t;
    std::cin >> n >> m >> t;
    std::vector<int> w(m + 1), z(t + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> w[i] >> z[i];
    }
    
    std::vector dp(m + 1, std::vector<int>(t + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= w[i]; j--) {
            for (int k = t; k >= z[i]; k--) {
                dp[j][k] = std::max(dp[j][k], dp[j - w[i]][k - z[i]] + 1);
            }
        }
    }

    std::cout << dp[m][t] << "\n";

}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
