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
    std::string bo, s;
    std::cin >> bo >> s;
    int x = 0;
    for (int i = 2; i < (int)bo.size(); i++) {
        x = x * 10 + (bo[i] - '0');
    }

    int c = (x + 1) / 2;
    int r = 0, p = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == 'R') {
            r ++ ;
            if (r >= c) {
                std::cout << "kou!\n" << i + 1 << "\n";
                return ;
            }
        } else {
            p ++ ;
            if (p >= c) {
                std::cout << "yukari!\n" << i + 1 << "\n";
                return ;
            }
        }
    }

    std::cout << "to be continued.\n" << (int)s.size() << "\n";

}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
