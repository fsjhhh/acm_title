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
    int n, m, k;
    std::cin >> n >> m >> k;
    int x = std::min(n, m) - 1, y = std::max(n, m) - 1;
    int minn = x + y;
    if (k < minn) {
        std::cout << "No\n";
        return ;
    }

    if (k % 2 != minn % 2) {
        std::cout << "No\n";
        return ;
    }

    std::cout << "Yes\n";
    std::vector a(101, std::vector<char>(101, 'B'));
    std::vector b(101, std::vector<char>(101, 'B'));
    bool pd = false;
    for (int i = 1; i < n; i++) {
        if (!pd) {
            a[i][1] = 'B';
        } else {
            a[i][1] = 'R';
        }
        pd = !pd;
    }

    for (int i = 1; i < m; i++) {
        if (!pd) {
            b[n][i] = 'B';
        } else {
            b[n][i] = 'R';
        }
        pd = !pd;
    }

    b[1][1] = 'R';
    b[2][1] = 'R';
    
    b[n - 1][m - 1] = b[n][m - 1];
    if (b[n][m - 1] == 'R') {
        a[n - 1][m] = a[n - 1][m - 1] = 'B';
    } else {
        a[n - 1][m] = a[n - 1][m - 1] = 'R';
    }

    if ((k - n - m + 2) % 4 == 2) {
        b[1][1] = b[2][1] = 'B';
        a[1][2] = 'R';
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < m; j++) {
            std::cout << b[i][j] << " \n"[j == m - 1];
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            std::cout << a[i][j] << " \n"[j == m];
        }
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
