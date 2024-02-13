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
    int d, g;
    std::cin >> d >> g;
    struct node {
        int t, f, h;
    };

    std::vector<node> a(g + 1);
    a[0] = {0, 0, 0};
    for (int i = 1; i <= g; i++) {
        std::cin >> a[i].t >> a[i].f >> a[i].h;
    }

    std::sort(a.begin(), a.end(), [&](node x, node y) -> bool {
        return x.t < y.t;
    });

    std::vector dp(g + 1, std::vector<int>(d + 26, -1));
    dp[0][0] = 10;
    
    int mx = 10;
    for (int i = 1; i <= g; i++) {
        for (int j = 0; j < d; j++) {
            if (dp[i - 1][j] >= a[i].t - a[i - 1].t) {
                dp[i][j + a[i].h] = std::max(dp[i][j + a[i].h], dp[i - 1][j] - (a[i].t - a[i - 1].t));
                dp[i][j] = std::max(dp[i][j], dp[i - 1][j] - (a[i].t - a[i - 1].t) + a[i].f);
            }
            if (dp[i][j + a[i].h] >= 0 && j + a[i].h >= d) {
                std::cout << a[i].t << "\n";
                return ;
            }
        }
        if (dp[i][0] != -1) {
            mx = std::max(mx, dp[i][0] + a[i].t);
        }
    }

    std::cout << mx << "\n";

}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
