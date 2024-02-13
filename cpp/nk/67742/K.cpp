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

#define int long long
const int mod = 1e9 + 7;

void solve() {
    int n, y;
    std::string s;
    std::cin >> n >> s >> y;
    
    int ans = 0;
    
    std::vector<int> a(5, -1);
    std::vector<bool> st(10, 0);

    auto calc = [&](std::string z) -> int {
        int res = 0;
        for (int i = 0; i < n; i++) {
            res = res * 10 + (z[i] - '0');
        }
        return res;
    };

    auto dfs = [&](auto self, int u, std::string z) -> void {
        if (u >= n) {
            if (z[0] != '0') {
                int res = calc(z);
                if (res <= y && res % 8 == 0) {
                    ans = (ans + 1) % mod;
                }
            }
            if (z.size() == 1 && z[0] == '0') {
                ans = (ans + 1) % mod;
            }
            return ;
        }
        if (s[u] >= 'a' && s[u] <= 'd') {
            if (a[s[u] - 'a'] != -1) {
                z[u] = a[s[u] - 'a'] + '0';
                self(self, u + 1, z);
                z[u] = s[u];
                return ;
            }
            for (int i = 0; i <= 9; i++) {
                if (st[i]) {
                    continue;
                }
                a[s[u] - 'a'] = i;
                z[u] = i + '0';
                st[i] = true;
                self(self, u + 1, z);
                a[s[u] - 'a'] = -1;
                z[u] = s[u];
                st[i] = false;
            }
        } else if (s[u] == '_') {
            for (int i = 0; i <= 9; i++) {
                z[u] = i + '0';
                self(self, u + 1, z);
                z[u] = s[u];
            }
        } else {
            self(self, u + 1, z);
        }
    };

    dfs(dfs, 0, s);

    std::cout << ans << "\n";

}

signed main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
