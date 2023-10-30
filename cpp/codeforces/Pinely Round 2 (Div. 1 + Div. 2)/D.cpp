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
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> mp(n);
    std::vector ans(n, std::string(m, '.'));
    for (int i = 0; i < n; i ++ ) {
        std::cin >> mp[i];
    }
    std::vector<int> col(n), row(m) ;
    int t = 0;
    for (int i = 0; i < n; i ++ ) {
        for (int j = 0; j < m; j ++ ) {
            if (mp[i][j] == 'U' || mp[i][j] == 'D') {
                col[i] ++ ;
            }
            if (mp[i][j] == 'L' || mp[i][j] == 'R') {
                row[j] ++ ;
            }
        }
    }
    for (int i = 0; i < n; i ++ ) {
        if (col[i] % 2) {
            std::cout << -1 << "\n";
            return ;
        }
    }
    for (int i = 0; i < m; i ++ ) {
        if (row[i] % 2) {
            std::cout << -1 << "\n";
            return ;
        }
    }
    std::vector<int> l(m), u(n);
    for (int i = 0; i < n; i ++ ) {
        for (int j = 0; j < m; j ++ ) {
            if (mp[i][j] == 'L') {
                if (!l[j]) {
                    ans[i][j] = 'W';
                    l[j] = !l[j];
                }
                else {
                    ans[i][j] = 'B';
                    l[j] = !l[j];
                }
            }
            if (mp[i][j] == 'R') {
                if (ans[i][j - 1] == 'W') {
                    ans[i][j] = 'B';
                }
                else {
                    ans[i][j] = 'W';
                }
            }
            if (mp[i][j] == 'U') {
                if (!u[i]) {
                    ans[i][j] = 'W';
                    u[i] = !u[i];
                }
                else {
                    ans[i][j] = 'B';
                    u[i] = !u[i];
                }
            }
            if (mp[i][j] == 'D') {
                if (ans[i - 1][j] == 'W') {
                    ans[i][j] = 'B';
                }
                else {
                    ans[i][j] = 'W';
                }
            }
        }
    }
    for (int i = 0; i < n; i ++ ) {
        std::cout << ans[i] << "\n";
    }
}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}