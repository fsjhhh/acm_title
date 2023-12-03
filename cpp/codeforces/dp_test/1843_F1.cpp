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
    int n;
    std::cin >> n;
    
    std::vector<int> dp_max(n + 10), dp_min(n + 10), dp_Max(n + 10), dp_Min(n + 10);

    int idx = 1;
    dp_Max[1] = dp_max[1] = 1;
    dp_Min[1] = dp_min[1] = 0;
    
    for (int i = 0; i < n; i++) {
        char op;
        std::cin >> op;
        if (op == '+') {
            int u, x;
            std::cin >> u >> x;
            int v = ++ idx;
            dp_min[v] = std::min(dp_min[u] + x, x);
            dp_max[v] = std::max(dp_max[u] + x, x);

            dp_Max[v] = std::max(dp_max[v], dp_Max[u]);
            dp_Min[v] = std::min(dp_min[v], dp_Min[u]);

        } else {
            int u, v, x;
            std::cin >> u >> v >> x;
            if (x >= dp_Min[v] && x <= dp_Max[v]) {
                std::cout << "YES\n";
            } else {
                std::cout << "NO\n";
            }
        }
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
