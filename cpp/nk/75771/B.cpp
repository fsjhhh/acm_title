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
    std::vector<std::string> mp(10);
    for (int i = 0; i < 10; i++) {
        std::cin >> mp[i];
    }

    if (mp[4].find('&') != -1) {
        int a = mp[1][0] - '0';
        int b = mp[6][0] - '0';
        std::cout << (a & b) << "\n";
    } else if (mp[3].find('=') != -1) {
        int a = mp[1][0] - '0';
        int b = mp[4][0] - '0';
        std::cout << (a | b) << "\n";
    } else {
        int a = mp[3][0] - '0';
        std::cout << (!a) << "\n";
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
