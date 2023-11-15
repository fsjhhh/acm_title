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
    int n, q;
    std::cin >> n >> q;
    std::vector<int> p(n + 1), dist(n + 1);
    for (int i = 0; i <= n; i++) {
        p[i] = i;
    }

    auto find = [&](auto self, int u) -> int {
        if (u != p[u]) {
            int t = p[u];
            p[u] = self(self, p[u]);
            dist[u] += dist[t];
        }
        return p[u];
    };

    std::set<int> s;
    std::map<int, int> mp;
    for (int i = 0; i < q; i++) {
        int a, b, d;
        std::cin >> a >> b >> d;
        if (d < 0) {
            d = -d;
            std::swap(a, b);
        }
        int fa = find(find, a), fb = find(find, b);
        if (fa == fb) {
            if (dist[a] - dist[b] == -d) {
                s.insert(i + 1);
            }
        } else {
            p[fb] = a;
            dist[fb] = d - dist[b];
            s.insert(i + 1);
        }
    }
    
    for (auto x : s) {
        std::cout << x << " ";
    }
    std::cout << "\n";

}

signed main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
