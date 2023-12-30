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
    std::string s;
    std::cin >> s;
    s = " " + s;
    std::vector<std::array<int, 26>> f(n + 1), g(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 26; j++) {
            if (j == s[i] - 'a') {
                if (j == s[i - 1] - 'a') {
                    f[i][j] = std::max(f[i - 1][j], g[i][j] + 1);
                    g[i][j] = g[i - 1][j] + 1;
                } else {
                    g[i][j] = 1;
                }
            } else {
                f[i][j] = f[i - 1][j];
                g[i][j] = 0;
            }
        }
    }

    int q;
    std::cin >> q;
    while (q -- ) {
        int l, r;
        std::cin >> l >> r;
        int ans = INF;
        for (int i = 0; i < 26; i++) {
            int x = f[r][i] - f[l - 1][i];
            ans = std::min(ans, x + 1);
        }
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
