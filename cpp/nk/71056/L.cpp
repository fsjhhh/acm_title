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
    std::vector<std::vector<PII>> a(n);
    for (int i = 0; i < n; i++) {
        int m;
        std::cin >> m;
        for (int j = 0; j < m; j++) {
            int x, y;
            std::cin >> x >> y;
            a[i].push_back({x, y});
        }
    }

    int z = a[0].size();
    auto check = [&](std::vector<PII> x, std::vector<PII> y) -> bool {
        for (int i = 0; i < z; i++) {
            int e = x[0].first - y[i].first;
            bool pd = false;
            for (int j = 0; j < z; j++) {
                if (x[j].second != y[(i + j) % z].second || x[j].first - y[(i + j) % z].first != e) {
                    pd = true;
                    break;
                }
            }
            if (!pd) {
                std::cout << e << "\n";
                return true;
            }
        }
        return false;
    };

    for (int i = 1; i < n; i++) {
        if (a[i].size() != z) {
            continue;
        }
        if (check(a[i], a[0])) {
            return ;
        }
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
