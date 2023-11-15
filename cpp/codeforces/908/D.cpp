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
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n + 1), b(m + 1);
    for (int i = 1; i <= n; i++) { 
        std::cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        std::cin >> b[i];
    }
    std::sort(b.begin() + 1, b.end(), [&](int x, int y) -> bool {
        return x > y;
    });
    int l = 1, r = 1;
    while (l <= n && r <= m) {
        if (a[l] >= b[r]) {
            std::cout << a[l] << " ";
            l++;
        } else {
            std::cout << b[r] << " ";
            r++;
        }
    }
    while (l <= n) {
        std::cout << a[l] << " ";
        l++;
    }
    while (r <= m) {
        std::cout << b[r] << " ";
        r++;
    }
    std::cout << "\n";
}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
