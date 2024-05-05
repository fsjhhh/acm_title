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
    int n, h, w;
    std::cin >> n >> h >> w;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i] >> b[i];
    }

    std::vector mp(h, std::vector<bool>(w, 0));
    std::vector<bool> st(n, 0);
    auto dfs = [&](auto self, int tx, int ty) -> bool {
        bool pd = false;
        if (tx >= h) {
            return true;
        }

        if (ty >= w) {
            if (self(self, tx + 1, 0)) {
                return true;
            }
        }

        auto chang = [&](int x, int y, int X, int Y) -> void {
            for (int i = x; i < x + X; i++) {
                for (int j = y; j < y + Y; j++) {
                    mp[i][j] = !mp[i][j];
                }
            }
        };

        auto calc = [&](int x, int y, int X, int Y) -> bool {
            if (x + X - 1 >= h || y + Y - 1 >= w) {
                return false;
            }

            for (int i = x; i < x + X; i++) {
                for (int j = y; j < y + Y; j++) {
                    if (mp[i][j]) {
                        return false;
                    }
                }
            }

            return true;

        };

        if (!mp[tx][ty]) {
            for (int i = 0; i < n; i++) {
                if (st[i]) {
                    continue;
                }
                if (calc(tx, ty, a[i], b[i])) {
                    chang(tx, ty, a[i], b[i]);
                    st[i] = true;
                    if (self(self, tx, ty + 1)) {
                        return true;
                    }
                    chang(tx, ty, a[i], b[i]);
                    st[i] = false;
                }
                if (calc(tx, ty, b[i], a[i])) {
                    chang(tx, ty, b[i], a[i]);
                    st[i] = true;
                    if (self(self, tx, ty + 1)) {
                        return true;
                    }
                    chang(tx, ty, b[i], a[i]);
                    st[i] = false;
                }
            }
        } else {
            if (self(self, tx, ty + 1)) {
                return true;
            }
        }

        return false;

    };

    if (dfs(dfs, 0, 0)) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
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

