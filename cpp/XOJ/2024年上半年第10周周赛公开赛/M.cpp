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
    int n;
    std::cin >> n;
    std::vector mp(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> mp[i][j];
        }
    }

    std::set<int> s;

    auto check = [&](int x, int y) -> bool {
        bool ok = false;
        for (int i = 0; i < n; i++) {
            if (mp[i][y] != mp[x][y]) {
                ok = true;
                break;
            }
        }
    
        if (!ok) {
            return true;
        }

        ok = false;
        for (int i = 0; i < n; i++) {
            if (mp[x][i] != mp[x][y]) {
                ok = true;
            }
        }

        return (!ok);

    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mp[i][j] && check(i, j)) {
                s.insert(mp[i][j]);
            }
        }
    }

    std::cout << s.size() << "\n";
    for (auto it : s) {
        std::cout << it << " \n"[it == (*s.rbegin())];
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
