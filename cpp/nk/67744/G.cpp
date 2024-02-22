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
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> mp(n);
    for (int i = 0; i < n; i++) {
        std::cin >> mp[i];
    }

    LL ans = 0;
    std::vector zx(n, std::vector<int>(m)), fx(n, std::vector<int>(m));
    for (int i = 0; i < n; i++) {
        std::vector<int> stk(m, 0);
        int cnt = 0, l = 0, r = 0;
        for (int j = 0; j < m; j++) {
            if (mp[i][j] == '*') {
                if (i > 0 && j > 0) {
                    zx[i][j] = zx[i - 1][j - 1];
                }
                if (i > 0 && j < m - 1) {
                    fx[i][j] = fx[i - 1][j + 1];
                }
                zx[i][j] ++ ;
                fx[i][j] ++ ;
                cnt ++ ;
            } else {
                cnt = 0;
            }
            if (cnt >= 3) {
                int x = (cnt + 1) / 2;
                for (int k = 2; k <= cnt; k += 2) {
                    if (fx[i][j - k] >= k / 2 + 1 && zx[i][j] >= k / 2 + 1) {
                        ans ++ ;
                    }
                }
            }
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
