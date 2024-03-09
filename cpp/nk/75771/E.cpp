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
#include <bits/stdc++.h>
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
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    std::map<int, std::vector<int>> mp;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        mp[i].push_back(i);
    }

    std::vector<int> x(m), y(m);
    for (int i = 0; i < m; i++) {
        std::cin >> x[i] >> y[i];
    }

    std::map<int, int> to;
    for (int i = m - 1; i >= 0; i--) {
        if (!to[y[i]]) {
            to[y[i]] = y[i];
        }
        to[x[i]] = to[y[i]];
    }
    
    for (int i = 0; i < n; i++) {
        if (!to[a[i]]) {
            std::cout << a[i] << " ";
        } else {
            std::cout << to[a[i]] << " ";
        }
    }

    std::cout << "\n";

}

signed main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}

