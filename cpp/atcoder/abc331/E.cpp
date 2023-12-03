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
    int n, m, l;
    std::cin >> n >> m >> l;
    std::vector<PII> a(n), b(m);
    std::set<PII> s;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i].first;
        a[i].second = i;
    }
    for (int i = 0; i < m; i++) {
        std::cin >> b[i].first;
        b[i].second = i;
        
    }
    for (int i = 0; i < l; i++) {
        int x, y;
        std::cin >> x >> y;
        x -- ;
        y -- ;
        s.insert({x, y});
    }

    std::sort(a.begin(), a.end(), std::greater());
    std::sort(b.begin(), b.end(), std::greater());
    
    LL ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s.find({a[i].second, b[j].second}) == s.end()) {
                ans = std::max(ans, (LL)a[i].first + b[j].first);
                break;
            }
        }
    }

    std::cout << ans << "\n";
    
}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
