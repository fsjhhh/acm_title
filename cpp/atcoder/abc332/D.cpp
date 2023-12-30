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
    int h, w;
    std::cin >> h >> w;
    std::vector a(h, std::vector<int>(w));
    std::vector b(h, std::vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            std::cin >> a[i][j];
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            std::cin >> b[i][j];
        }
    }
    
    std::vector<int> w_h(h);
    std::vector<std::vector<int>> d_h;
    std::vector<bool> st(h);
    auto dfs_h = [&](auto self, int u) -> void {
        if (u == h) {
            d_h.push_back(w_h);
            return ;
        }
        for (int i = 0; i < h; i++) {
            if (st[i]) {
                continue;
            }
            w_h[u] = i;
            st[i] = true;
            self(self, u + 1);
            st[i] = false;
        }
    };

    st.resize(w, 0);
    std::vector<int> w_w(w);
    std::vector<std::vector<int>> d_w;
    auto dfs_w = [&](auto self, int u) -> void {
        if (u == w) {
            d_w.push_back(w_w);
            return ;
        }
        for (int i = 0; i < w; i++) {
            if (st[i]) {
                continue;
            }
            w_w[u] = i;
            st[i] = true;
            self(self, u + 1);
            st[i] = false;
        }
    };
    
    dfs_h(dfs_h, 0);
    dfs_w(dfs_w, 0);
    
    int ans = INF;
    auto check = [&](int x, int y) -> bool {
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (a[d_h[x][i]][d_w[y][j]] != b[i][j]) {
                    return false;
                }
            }
        }
    
        int res = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < i; j++) {
                if (d_h[x][i] < d_h[x][j]) {
                    res ++ ;
                }
            }
        }

        for (int i = 0; i < w; i++) {
            for (int j = 0; j < i; j++) {
                if (d_w[y][i] < d_w[y][j]) {
                    res ++ ;
                }
            }
        }

        ans = std::min(ans, res);
        return true;

    };

    bool pd = false;
    for (int i = 0; i < (int)d_h.size(); i++) {
        for (int j = 0; j < (int)d_w.size(); j++) {
            if (check(i, j)) {
                pd = true;
            }
        }
    }

    if (!pd) {
        std::cout << "-1\n";
    } else {
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
