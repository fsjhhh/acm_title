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
    std::vector<int> p(n);
    std::map<int, int> mp;
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
        mp[p[i]] = i;
    }

    int _1 = 0;
    for (int i = 0; i < n; i++) {
        if (p[i] == 1) {
            _1 = i;
            break;
        }
    }

    int l = _1 - 1, r = _1 + 1;
    std::set<int> s;
    while (l > 0) {
        s.insert(p[l]);
        l -= 2;
    }
    while (r < n - 1) {
        s.insert(p[r]);
        r += 2;
    }

    std::sort(p.begin(), p.end(), [&](int x, int y) -> bool {
        if (s.count(x) > s.count(y)) {
            return true;
        } else if (s.count(x) < s.count(y)) {
            return false;
        } else {
            return x < y;
        }
    });
    
    std::vector<int> ans(n);
    for (int i = n, j = 0; i > 0; i--, j++) {
        ans[mp[p[j]]] = i;
    }

    for (int i = 0; i < n; i++) {
        std::cout << ans[i] << " \n"[i == n - 1];
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
