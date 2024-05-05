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

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char s;
            std::cin >> s;
            if (s == 'H') {
                a[i] |= ((1 << (m - j - 1)));
            }
        
        }
    }

    std::vector<int> s;
    for (int i = 0; i < (1 << m); i++) {
        if (i & (i >> 2)) {
            continue;
        }
        if (i & (i >> 1)) {
            continue;
        }
        if (i & (i << 2)) {
            continue;
        }
        if (i & (i << 1)) {
            continue;
        }
        s.push_back(i);
    }

    std::vector dp(n + 10, std::vector((int)s.size() + 10, std::vector<int>((int)s.size() + 10, 0)));

    for (int i = 0; i < (int)s.size(); i++) {
        if (!(s[i] & a[0])) {
            dp[0][i][0] = __builtin_popcount(s[i]);
        }
    }

    for (int i = 0; i < (int)s.size(); i++) {
        if (!(s[i] & a[1])) {
            for (int j = 0; j < (int)s.size(); j++) {
                if (!(s[i] & s[j]) && !(s[j] & a[0])) {
                    dp[1][i][j] = __builtin_popcount(s[i]) + __builtin_popcount(s[j]);
                }
            }
        }
    }

    for (int i = 2; i < n; i++) {
        for (int j = 0; j < (int)s.size(); j++) {
            if (!(s[j] & a[i])) {
                for (int k1 = 0; k1 < (int)s.size(); k1++) {
                    if (!(s[j] & s[k1]) && !(s[k1] & a[i - 1])) {
                        for (int k2 = 0; k2 < (int)s.size(); k2++) {
                            if (!(s[j] & s[k2]) && !(s[k1] & s[k2]) && !(s[k2] & a[i - 2])) {
                                dp[i][j][k1] = std::max(dp[i][j][k1], dp[i - 1][k1][k2] + __builtin_popcount(s[j]));
                            }
                        }
                    }
                }
            }
        }
    }

    int ans = 0;

    for (int i = 0; i < (int)s.size(); i++) {
        for (int j = 0; j < (int)s.size(); j++) {
            ans = std::max(ans, dp[n - 1][i][j]);
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
