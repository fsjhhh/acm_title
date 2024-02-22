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
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }

    if (n == 1) {
        std::cout << "-1\n";
        return ;
    }
    if (n == 2) {
        if (a[0] == b[0]) {
            std::cout << "-1\n";
        } else {
            std::cout << "1\n";
        }
        return ;
    }

    bool ok = false;
    for (int i = 1; i < n - 1; i++) {
        if (a[i] == b[i]) {
            ok = true;
            break;
        }
    }

    if (ok) {
        std::cout << "1\n";
        return ;
    }

    for (int i = 1; i < n; i++) {
        if (a[i] == b[i - 1] || a[i - 1] == b[i]) {
            ok = true;
            break;
        }
    }

    if (ok) {
        std::cout << "1\n";
    } else {
        std::cout << "2\n";
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
