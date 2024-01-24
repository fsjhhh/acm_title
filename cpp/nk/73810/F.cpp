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
    int n, m;
    std::cin >> n >> m;

    std::set<int> s;
    int k;
    auto calc = [&](int x) -> void {
        int z = x;
        s.insert(x);
        // int ans = 0;
        while (1) {
            if (z % 2 == 0) {
                z /= 2;
            } else {
                z = z * 3 + 1;
            }
            if (s.find(z) != s.end()) {
                k = z;
                break;
            }
            s.insert(z);
        }
    };

    calc(m);
    int sum = 0, d = 0;
    while (1) {
        sum += m;
        d ++ ;
        if (sum >= n) {
            std::cout << d << "\n";
            return ;
        }
        if (m % 2 == 0) {
            m /= 2;
        } else {
            m = 3 * m + 1;
        }
        if (m == k) {
            break;
        }
    }

    n -= sum;
    sum = 0;
    LL z = 0;
    std::vector<int> w;
    while (1) {
        w.push_back(m);
        sum += m;
        z ++ ;
        if (m % 2 == 0) {
            m /= 2;
        } else {
            m = 3 * m + 1;
        }
        if (m == k) {
            break;
        }
    }


    int b = n / sum;
    n %= sum;
    d += (b * z);
    if (n == 0) {
        std::cout << d << "\n";
        return ;
    }
    sum = 0;
    for (auto it : w) {
        sum += it;
        d ++ ;
        if (sum >= n) {
            std::cout << d << "\n";
            return ;
        }
    }
}

signed main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
