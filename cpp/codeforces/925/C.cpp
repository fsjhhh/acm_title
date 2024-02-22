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
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    if (a[0] == a[n - 1]) {
        int ans = 0;
        for (int i = 0, j = n - 1; i <= j; ) {
            if (a[i] != a[0] && a[j] != a[0]) {
                break;
            }
            if (a[i] == a[0]) {
                ans ++ ;
                i ++ ;
            }
            if (a[j] == a[0] && i - 1 != j) {
                ans ++ ;
                j -- ;
            }
        }
        std::cout << n - ans << "\n";
    } else {
        int x = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == a[0]) {
                x ++ ;
            } else {
                break;
            }
        }
        int y = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] == a[n - 1]) {
                y ++ ;
            } else {
                break;
            }
        }
        std::cout << n - std::max(x, y) << "\n";
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
