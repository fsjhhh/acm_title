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
    LL n, d;
    std::cin >> n >> d;
    if (d < n - 1 || d > ((n - 1 + 1) * (n - 1)) / 2) {
        std::cout << "NO\n";
        return ;
    }
    
    std::deque<PII> edges;
    for (int i = 2; i <= n; i++) {
        edges.push_back({1, i});
    }
    LL len = n - 1, mx = 1;
    for (int i = n; i > 2; i--) {
        if (len == d) {
            break;
        }
        edges.pop_back();
        mx ++ ;
        LL z = len - 1 + mx;
        if (z > d) {
            LL c = z - d;
            edges.push_front({i, (i + c + 1) > n ? 2 : i + c + 1});
            break;
        } else {
            edges.push_front({i, (i + 1) > n ? 2 : i + 1});
        }
        len = z;
    }

    std::cout << "YES\n";
    for (auto [u, v] : edges) {
        std::cout << u << " " << v << "\n";
    }
    std::cout << "1\n";

}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
