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
    std::vector mp(4, std::vector<LL>(4));
    std::map<LL, LL> m;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cin >> mp[i][j];
            m[mp[i][j]] ++ ;
        }
    }

    std::map<LL, LL> s;
    LL ls = 1;
    for (int i = 1; i <= 11; i++) {
        ls *= 2;
        s[ls] = i - 1;
    }

    LL ans = 0;
    for (auto [x, cnt] : m) {
        if (x <= 2) {
            continue;
        }
        LL res = x * s[x];
        ans += (res * cnt);
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
