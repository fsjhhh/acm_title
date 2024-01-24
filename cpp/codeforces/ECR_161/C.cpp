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

#define int long long

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> qian(n, 0), hou(n, 0);
    qian[1] = 1, hou[n - 2] = 1;
    for (int i = 1; i < n - 1; i++) {
        int z_1 = abs(a[i] - a[i - 1]), z_2 = abs(a[i + 1] - a[i]);
        if (z_1 > z_2) {
            qian[i + 1] = qian[i] + 1;
        } else {
            qian[i + 1] = qian[i] + z_2;
        }
    }

    for (int i = n - 2; i > 0; i--) {
        int z_1 = abs(a[i + 1] - a[i]), z_2 = abs(a[i] - a[i - 1]);
        if (z_1 > z_2) {
            hou[i - 1] = hou[i] + 1;
        } else {
            hou[i - 1] = hou[i] + z_2;
        }
    }

    int q;
    std::cin >> q;
    while (q -- ) {
        int x, y;
        std::cin >> x >> y;
        x -- ;
        y -- ;
        if (x < y) {
            std::cout << qian[y] - qian[x] << "\n";
        } else {
            std::cout << hou[y] - hou[x] << "\n";
        }
    }

}

signed main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
