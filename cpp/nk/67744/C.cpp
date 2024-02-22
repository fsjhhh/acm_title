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
    int n, m, x, y;
    std::cin >> n >> m >> x >> y;
    x -- ;
    y -- ;
    std::vector<std::string> mp(n);
    for (int i = 0; i < n; i++) {
        std::cin >> mp[i];
    }

    int p, q;
    std::cin >> p >> q;
    std::vector<PII> a(q);
    for (int i = 0; i < q; i++) {
        std::cin >> a[i].first >> a[i].second;
        a[i].second -- ;
    }

    for (int i = 0; i < p; i++) {
        for (auto [x, y] : a) {
            if (x == 1) {
                char z = mp[y][m - 1];
                for (int k = m - 1; k >= 1; k--) {
                    mp[y][k] = mp[y][k - 1];
                }
                mp[y][0] = z;
            } else {
                char z = mp[n - 1][y];
                for (int k = n - 1; k >= 1; k--) {
                    mp[k][y] = mp[k - 1][y];
                }
                mp[0][y] = z;
            }
        }
    }

    std::cout << mp[x][y] << "\n";

}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
