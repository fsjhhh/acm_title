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
    std::vector<std::string> mp(2);
    for (int i = 0; i < 2; i++) {
        std::cin >> mp[i];
    }

    std::vector st(2, std::vector<bool>(n, 0));
    st[0][0] = true;
    std::queue<PII> q;
    q.push({0, 0});

    std::vector<int> dx = {-1, 0, 1, 0}, dy = {0, -1, 0, 1};
    while (q.size()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int tx = x + dx[i], ty = y + dy[i];
            if (tx < 0 || tx >= 2 || ty < 0 || ty >= n) {
                continue;
            }
            
            if (ty > 0 && mp[tx][ty] == '<') {
                if (!st[tx][ty - 1]) {
                    q.push({tx, ty - 1});
                    st[tx][ty - 1] = true;
                }
            }
            if (ty < n - 1 && mp[tx][ty] == '>') {
                if (!st[tx][ty + 1]) {
                    q.push({tx, ty + 1});
                    st[tx][ty + 1] = true;
                }
            }
        }
    }

    if (st[1][n - 1]) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
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
