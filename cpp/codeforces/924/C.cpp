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
    LL n, x;
    std::cin >> n >> x;
    std::set<LL> ans;
    for (LL i = 1; i * i <= (n - x); i++) {
        if ((n - x) % i == 0) {
            if (i % 2 == 0) {
                ans.insert((i / 2 + 1));
            }
            if ((n - x) / i % 2 == 0) {
                ans.insert((n - x) / i / 2 + 1);
            }
        }
    }

    if (x == 1) {
        int cnt = 0;
        for (auto it : ans) {
            if (it >= x) {
                cnt ++ ;
            }
        }
        std::cout << cnt << "\n";
        return ;
    }

    for (LL i = 1; i * i <= (n + x - 2); i++) {
        if ((n + x - 2) % i == 0) {
            if (i % 2 == 0) {
                ans.insert((i / 2 + 1));
            }
            if ((n + x - 2) / i % 2 == 0) {
                ans.insert((n + x - 2) / i / 2 + 1);
            }
        }
    }

    int cnt = 0;
    for (auto it : ans) {
        if (it >= x) {
            cnt ++ ;
        }
    }

    std::cout << cnt << "\n";

}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
