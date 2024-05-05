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
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    while (q -- ) {
        int l, r, t;
        std::cin >> l >> r >> t;
        l -- ;
        r -- ;
        LL q_1 = l / n, q_2 = l % n;
        LL h_1 = r / n, h_2 = r % n;

        if (q_1 == h_1) {
            LL ans = 0;
            for (int i = 0; i < n; i++) {
                if (i >= q_2 && i <= h_2 && a[i] == t) {
                    ans ++ ;
                }
            }
            std::cout << (ans * (ans - 1) / 2) << "\n";
            continue;
        }

        LL cnt = 0;

        LL q = 0, h = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == t) {
                cnt ++ ;
            }
            if (i >= q_2 && a[i] == t) {
                q ++ ;
            }
            if (i <= h_2 && a[i] == t) {
                h ++ ;
            }
        }

        LL w = (h_1 - q_1 - 1);
        LL ans = (cnt * w + q + h);
        std::cout << (ans * (ans - 1) / 2) << "\n";

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
