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
    int n, h;
    std::cin >> n >> h;
    std::vector<std::string> mp(5);

    for (int i = 0; i < 5; i++) {
        std::cin >> mp[i];
    }

    LL ans = 0;

    for (int i = 0; i < n; i++) {
        if (!h) {
            break;
        }
        if (mp[1][i] == '*') {
            ans ++ ;
            h -- ;
        }
        if (!h) {
            break;
        }
        if (mp[3][i] == '*') {
            ans ++ ;
            h -- ;
        }
        if (!h) {
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        if (!h) {
            break;
        }
        if (mp[0][i] == '*' && mp[1][i] == '*') {
            ans ++ ;
            h -- ;
        }
        if (!h) {
            break;
        }
        if (mp[4][i] == '*' && mp[3][i] == '*') {
            ans ++ ;
            h -- ;
        }
        if (!h) {
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        if (h <= 1) {
            break;
        }

        if (mp[0][i] == '*' && mp[1][i] == '#') {
            ans ++ ;
            h -= 2;
        }
        if (h <= 1) {
            break;
        }
        if (mp[4][i] == '*' && mp[3][i] == '#') {
            ans ++ ;
            h -= 2;
        }
        if (h <= 1) {
            break;
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
