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
    int n;
    std::cin >> n;
    std::vector a(n + 2, std::vector<int>(n + 2));
    std::vector<int> dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};
    for (int i = 0; i <= n + 1; i++) {
        a[i][0] = -1;
        a[0][i] = -1;
        a[n + 1][i] = -1;
        a[i][n + 1] = -1;
    }
    
    int d = 0, x = 1, y = 1;
    a[x][y] = 1;
    for (int i = 2; i < n * n; i++) {
        if (a[x + dx[d]][y + dy[d]] != 0) {
            d = (d + 1) % 4;
            i -- ;
            continue;
        }
        x += dx[d];
        y += dy[d];
        a[x][y] = i;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == 0) {
                std::cout << "T ";
            } else {
                std::cout << a[i][j] << " ";
            }
        }
        std::cout << "\n";
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
