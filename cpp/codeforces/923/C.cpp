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
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<int> a(k + 1), b(k + 1);
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        if (x > k) {
            continue;
        }
        a[x] = 1;
    }
    for (int i = 0; i < m; i++) {
        int x;
        std::cin >> x;
        if (x > k) {
            continue;
        }
        b[x] = 1;
    }

    int num_a = 0, num_b = 0, num = 0;
    for (int i = 1; i <= k; i++) {
        if (!a[i] && !b[i]) {
            std::cout << "NO\n";
            return ;
        }

        if (a[i] == b[i]) {
            num += a[i];
        } else {
            num_a += a[i];
            num_b += b[i];
        }
    }

    if (abs(num_a - num_b) <= num) {
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
