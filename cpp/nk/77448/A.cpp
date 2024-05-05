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

    std::vector st(n, std::vector<int>(m, 0));

    LL _1 = 0, _2 = 0, _3 = 0;
    auto check = [&](int x, int y, int id) -> bool {
        if (id == 1) {
            if (x < 0 || x >= n || y < 0 || y >= m || mp[x][y] == '.' || st[x][y]) {
                return false;
            }
            if (x < 0 || x >= n || y + 1 < 0 || y + 1 >= m || mp[x][y + 1] == '.' || st[x][y + 1]) {
                return false;
            }
            if (x < 0 || x >= n || y + 2 < 0 || y + 2 >= m || mp[x][y + 2] == '.' || st[x][y + 2]) {
                return false;
            }
            if (x + 1 < 0 || x + 1 >= n || y < 0 || y >= m || mp[x + 1][y] == '.' || st[x + 1][y]) {
                return false;
            }
            if (x + 1 < 0 || x + 1 >= n || y + 2 < 0 || y + 2 >= m || mp[x + 1][y + 2] == '.' || st[x + 1][y + 2]) {
                return false;
            }
            if (x + 2 < 0 || x + 2 >= n || y < 0 || y >= m || mp[x + 2][y] == '.' || st[x + 2][y]) {
                return false;
            }
            if (x + 2 < 0 || x + 2 >= n || y + 1 < 0 || y + 1 >= m || mp[x + 2][y + 1] == '.' || st[x + 2][y + 1]) {
                return false;
            }
            if (x + 2 < 0 || x + 2 >= n || y + 2 < 0 || y + 2 >= m || mp[x + 2][y + 2] == '.' || st[x + 2][y + 2]) {
                return false;
            }
            if (x + 3 < 0 || x + 3 >= n || y < 0 || y >= m || mp[x + 3][y] == '.' || st[x + 3][y]) {
                return false;
            }
            if (x + 4 < 0 || x + 4 >= n || y < 0 || y >= m || mp[x + 4][y] == '.' || st[x + 4][y]) {
                return false;
            }
            return true;
        } else if (id == 2) {
            if (x < 0 || x >= n || y < 0 || y >= m || mp[x][y] == '.' || st[x][y]) {
                return false;
            }
            if (x < 0 || x >= n || y + 1 < 0 || y + 1 >= m || mp[x][y + 1] == '.' || st[x][y + 1]) {
                return false;
            }
            if (x < 0 || x >= n || y + 2 < 0 || y + 2 >= m || mp[x][y + 2] == '.' || st[x][y + 2]) {
                return false;
            }
            if (x + 1 < 0 || x + 1 >= n || y + 2 < 0 || y + 2 >= m || mp[x + 1][y + 2] == '.' || st[x + 1][y + 2]) {
                return false;
            }
            if (x + 2 < 0 || x + 2 >= n || y + 1 < 0 || y + 1 >= m || mp[x + 2][y + 1] == '.' || st[x + 2][y + 1]) {
                return false;
            }
            if (x + 2 < 0 || x + 2 >= n || y + 2 < 0 || y + 2 >= m || mp[x + 2][y + 2] == '.' || st[x + 2][y + 2]) {
                return false;
            }
            if (x + 3 < 0 || x >= n || y + 2 < 0 || y + 2 >= m || mp[x + 3][y + 2] == '.' || st[x + 3][y + 2]) {
                return false;
            }
            if (x + 4 < 0 || x + 4 >= n || y + 2 < 0 || y + 2 >= m || mp[x + 4][y + 2] == '.' || st[x + 4][y + 2]) {
                return false;
            }
            return true;
        } else {
            if (x < 0 || x >= n || y < 0 || y >= m || mp[x][y] == '.' || st[x][y]) {
                return false;
            }
            if (x < 0 || x >= n || y + 1 < 0 || y + 1 >= m || mp[x][y + 1] == '.' || st[x][y + 1]) {
                return false;
            }
            if (x < 0 || x >= n || y + 2 < 0 || y + 2 >= m || mp[x][y + 2] == '.' || st[x][y + 2]) {
                return false;
            }
            if (x + 1 < 0 || x + 1 >= n || y < 0 || y >= m || mp[x + 1][y] == '.' || st[x + 1][y]) {
                return false;
            }
            if (x + 1 < 0 || x + 1 >= n || y + 2 < 0 || y + 2 >= m || mp[x + 1][y + 2] == '.' || st[x + 1][y + 2]) {
                return false;
            }
            if (x + 2 < 0 || x + 2 >= n || y < 0 || y >= m || mp[x + 2][y] == '.' || st[x + 2][y]) {
                return false;
            }
            if (x + 2 < 0 || x + 2 >= n || y + 1 < 0 || y + 1 >= m || mp[x + 2][y + 1] == '.' || st[x + 2][y + 1]) {
                return false;
            }
            if (x + 2 < 0 || x + 2 >= n || y + 2 < 0 || y + 2 >= m || mp[x + 2][y + 2] == '.' || st[x + 2][y + 2]) {
                return false;
            }
            if (x + 3 < 0 || x + 3 >= n || y < 0 || y >= m || mp[x + 3][y] == '.' || st[x + 3][y]) {
                return false;
            }
            if (x + 4 < 0 || x + 4 >= n || y < 0 || y >= m || mp[x + 4][y] == '.' || st[x + 4][y]) {
                return false;
            }
            if (x + 3 < 0 || x + 3 >= n || y + 2 < 0 || y + 2 >= m || mp[x + 3][y + 2] == '.' || st[x + 3][y + 2]) {
                return false;
            }
            if (x + 4 < 0 || x + 4 >= n || y + 2 < 0 || y + 2 >= m || mp[x + 4][y + 2] == '.' || st[x + 4][y + 2]) {
                return false;
            }
            if (x + 4 < 0 || x + 4 >= n || y + 1 < 0 || y + 1 >= m || mp[x + 4][y + 1] == '.' || st[x + 4][y + 1]) {
                return false;
            }
            return true;
        } 
    };

    auto change = [&](int x, int y, int id) -> void {
        if (id == 1) {
            st[x][y] = !st[x][y];
            st[x][y + 1] = !st[x][y + 1];
            st[x][y + 2] = !st[x][y + 2];
            st[x + 1][y] = !st[x + 1][y];
            st[x + 1][y + 2] = !st[x + 1][y + 2];
            st[x + 2][y] = !st[x + 2][y];
            st[x + 2][y + 1] = !st[x + 2][y + 1];
            st[x + 2][y + 2] = !st[x + 2][y + 2];
            st[x + 3][y] = !st[x + 3][y];
            st[x + 4][y] = !st[x + 4][y];
        } else if (id == 2) {
            st[x][y] = !st[x][y];
            st[x][y + 1] = !st[x][y + 1];
            st[x][y + 2] = !st[x][y + 2];
            st[x + 1][y + 2] = !st[x + 1][y + 2];
            st[x + 2][y + 1] = !st[x + 2][y + 1];
            st[x + 2][y + 2] = !st[x + 2][y + 2];
            st[x + 3][y + 2] = !st[x + 3][y + 2];
            st[x + 4][y + 2] = !st[x + 4][y + 2];
        } else {
            st[x][y] = !st[x][y];
            st[x][y + 1] = !st[x][y + 1];
            st[x][y + 2] = !st[x][y + 2];
            st[x + 1][y] = !st[x + 1][y];
            st[x + 1][y + 2] = !st[x + 1][y + 2];
            st[x + 2][y] = !st[x + 2][y];
            st[x + 2][y + 1] = !st[x + 2][y + 1];
            st[x + 2][y + 2] = !st[x + 2][y + 2];
            st[x + 3][y] = !st[x + 3][y];
            st[x + 4][y] = !st[x + 4][y];
            st[x + 3][y + 2] = !st[x + 3][y + 2];
            st[x + 4][y + 1] = !st[x + 4][y + 1];
            st[x + 4][y + 2] = !st[x + 4][y + 2];
        }
    };

    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (mp[i][j] == '#' && !st[i][j]) {
                if(check(i, j, 3)) {
                    _3 ++ ;
                    change(i, j, 3);
                }
                if (check(i, j, 1)) {
                    _1 ++ ;
                    change(i, j, 1);
                }
                if (check(i, j, 2)) {
                    _2 ++ ;
                    change(i, j, 2);
                }
            }
        }
    }

    std::cout << _1 << " " << _2 << " " << _3 << "\n";


}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
