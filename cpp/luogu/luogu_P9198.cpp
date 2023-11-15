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
    int n, m, q;
    std::cin >> n >> m >> q;
    std::vector mp(n, std::vector<std::array<LL, 3>>(m));

    auto check = [&]() -> bool {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= ((m - 1) / 2); j++) {
                for (int k = 0; k < 3; k++) {
                    if (mp[i][j][k] != mp[i][(m - j - 1)][k]) {
                        return false;
                    }
                }
            }
        }
        return true;
    };
    
    while (q -- ) {
        int i, j, t;
        LL c;
        std::cin >> i >> j >> t >> c;
        i -- ;
        j -- ;
        t -- ;
        mp[i][j][t] = (mp[i][j][t] + c) % 256;
        if (check()) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
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
