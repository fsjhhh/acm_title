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
    std::map<int, int> mp;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        mp[a[i]] ++ ;
    }

    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }

    std::sort(a.begin(), a.end());
    
    int id = 0, minn = INF, z = 0;
    for (int i = 0; i < n; i++) {
        auto it = std::lower_bound(a.begin(), a.end(), b[i]);
        if (it != a.end()) {
            if (minn > std::abs(*it - b[i])) {
                id = i;
                minn = std::abs(*it - b[i]);
                z = *it;
            }
        }
        if (it != a.begin()) {
            it -- ;
            if (minn > std::abs(*it - b[i])) {
                id = i;
                minn = std::abs(*it - b[i]);
                z = *it;
            }
        }
    }

    std::vector<int> ans(n);
    ans[id] = z;
    mp[z] -- ;
    int idx = 0;
    for (auto [x, y] : mp) {
        if (idx == id) {
            idx ++ ;
        }
        for (int i = 0; i < y; i++) {
            ans[idx] = x;
            idx ++ ;
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << ans[i] << " \n"[i == n - 1];
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
