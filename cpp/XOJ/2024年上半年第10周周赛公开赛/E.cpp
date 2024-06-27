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
    int n, k;
    std::cin >> n >> k;
    
    auto ceil = [&](int x) -> int {
        if (x < 0) {
            x = -x;
            x /= k;
            return -x;
        } else {
            x /= k;
            return x;
        }
    };

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    int pos1 = -1, pos2 = -1;
    for (int i = 1; i <= n; i++) {
        if (a[i] >= 0 && pos1 == -1) {
            pos1 = i;
        }
        if (a[i] < 0) {
            pos2 = i;
        }
    }
    a[0] = -INF;
    a.push_back(INF);
    // std::cerr << pos1 << " " << pos2 << "\n";
    
    if (pos1 == -1) {
        LL cnt = 0;
        for (int i = 1; i <= n; i++) {
            while (a[i] < a[i - 1]) {
                a[i] = ceil(a[i]);
                cnt ++ ;
            }
        }
        std::cout << cnt << "\n";
        return ;
    }
    if (pos2 == -1) {
        LL cnt = 0;
        for (int i = n; i >= 1; i--) {
            while (a[i] > a[i + 1]) {
                a[i] = ceil(a[i]);
                cnt ++ ;
            }
        }
        std::cout << cnt << "\n";
        return ;
    }

    if (pos1 < pos2) {
        LL cnt = 0;
        for (int i = 1; i < pos1; i++) {
            while (a[i] < a[i - 1]) {
                a[i] = ceil(a[i]);
                cnt ++ ;
            }
        }
        for (int i = n; i > pos2; i--) {
            while (a[i] > a[i + 1]) {
                a[i] = ceil(a[i]);
                cnt ++ ;
            }
        }
        for (int i = pos1; i <= pos2; i++) {
            while (a[i]) {
                a[i] = ceil(a[i]);
                cnt ++ ;
            }
        }
        std::cout << cnt << "\n";
    } else {
        LL cnt = 0;
        for (int i = 1; i < pos1; i++) {
            while (a[i] < a[i - 1]) {
                a[i] = ceil(a[i]);
                cnt ++ ;
            }
        }
        for (int i = n; i > pos2; i--) {
            while (a[i] > a[i + 1]) {
                a[i] = ceil(a[i]);
                cnt ++ ;
            }
        }
        std::cout << cnt << "\n";
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
