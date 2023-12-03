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
    int n, q;
    std::cin >> n >> q;
    std::vector mp(n + 1, std::vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char x;
            std::cin >> x;
            if (x == 'W') {
                mp[i][j] = 0;
            } else {
                mp[i][j] = 1;
            }
        }
    }

    std::vector sum(n + 1, std::vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + mp[i][j];
        }
    }
    
    auto calc = [&](int x1, int y1, int x2, int y2) -> LL {
        return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
    };

    while (q -- ) {
        int a, b, c, d;
        std::cin >> a >> b >> c >> d;
        int a_x = (a % n + 1), b_x = (b % n + 1), c_x = (c % n + 1), d_x = (d % n + 1);
        int x = ((c + 1 + n - 1) / n - (a + 1 + n - 1) / n - 1);
        int y = ((d + 1 + n - 1) / n - (b + 1 + n - 1) / n - 1);
        if (x < 0 && y < 0) {
            std::cout << calc(a_x, b_x, c_x, d_x) << "\n";
            continue;
        }
        if (x < 0) {
            LL ans = calc(a_x, 1, c_x, d_x) + calc(a_x, b_x, c_x, n);
            ans = ans + calc(a_x, 1, c_x, n) * y;
            std::cout << ans << "\n";
            continue;
        }
        if (y < 0) {
            LL ans = calc(1, b_x, c_x, d_x) + calc(a_x, b_x, n, d_x);
            ans = ans + calc(1, b_x, n, d_x) * x;
            std::cout << ans << "\n";
            continue;
        }
        LL ans = (1ll * sum[n][n] * x * y) + calc(1, 1, c_x, d_x) + calc(a_x, b_x, n, n) + calc(1, b_x, c_x, n) + calc(a_x, 1, n, d_x);
        ans = ans + (calc(1, b_x, n, n) + calc(1, 1, n, d_x)) * x;
        ans = ans + (calc(a_x, 1, n, n) + calc(1, 1, c_x, n)) * y;
        std::cout << ans << "\n";
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
