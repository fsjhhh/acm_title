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

    if (mp[0][0] == mp[n - 1][m - 1] || mp[n - 1][0] == mp[0][m - 1]) {
        std::cout << "YES\n";
        return ;
    }
    if (mp[0][0] == mp[n - 1][0]) {
        for (int i = 0; i < n; i++) {
            if (mp[i][m - 1] == mp[0][0]) {
                std::cout << "YES\n";
                return ;
            }
        }
    }
    if (mp[0][0] == mp[0][m - 1]) {
        for (int i = 0; i < m; i++) {
            if (mp[n - 1][i] == mp[0][0]) {
                std::cout << "YES\n";
                return ;
            }
        }
    }
    if (mp[0][m - 1] == mp[n - 1][m - 1]) {
        for (int i = 0; i < n; i++) {
            if (mp[i][0] == mp[n - 1][m - 1]) {
                std::cout << "YES\n";
                return ;
            }
        }
    }
    if (mp[n - 1][0] == mp[n - 1][m - 1]) {
        for (int i = 0; i < m; i++) {
            if (mp[0][i] == mp[n - 1][m - 1]) {
                std::cout << "YES\n";
                return ;
            }
        }
    }

    std::cout << "NO\n";

}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
