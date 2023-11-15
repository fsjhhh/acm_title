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

#define int long long

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::string> a(n);
    std::vector<std::map<int, int>> mp(6);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end(), [&](std::string a, std::string b) -> bool {
        if (a.size() == b.size()) {
            return a < b;
        }
        return a.size() < b.size();
    });

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int m = a[i].size();
        std::vector<int> z(m + 1);
        int sum = 0;
        for (int j = 0; j < m; j++) {
            z[j + 1] = (a[i][j] - '0');
            sum += z[j + 1];
        }
        mp[m][sum] ++ ;
        
        std::vector<int> q(m + 2), h(m + 2);
        for (int j = 1; j <= m; j++) {
            q[j] = q[j - 1] + z[j];
        }
        for (int j = m; j >= 1; j--) {
            h[j] = h[j + 1] + z[j];
        }

        for (int j = 0; j <= m; j++) {
            if (m % 2) {
                if (j < (m + 1) / 2) {
                    ans += mp[m - 2 * j][h[j + 1] - q[j]];
                } else {
                    ans += mp[2 * j - m][q[j] - h[j + 1]];
                }
            } else {
                if (j < (m + 1) / 2) {
                    ans += mp[m - 2 * j][h[j + 1] - q[j]];
                } else if (j > (m + 1) / 2) {
                    ans += mp[2 * j - m][q[j] - h[j + 1]];
                }
            }
        }

    }

    std::cout << ans - n << "\n";
}

signed main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
