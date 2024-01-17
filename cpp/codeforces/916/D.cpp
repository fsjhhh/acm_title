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
    std::vector<PLL> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i].first;
        a[i].second = i;
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i].first;
        b[i].second = i;
    }
    for (int i = 0; i < n; i++) {
        std::cin >> c[i].first;
        c[i].second = i;
    }

    std::sort(a.begin(), a.end(), std::greater());
    std::sort(b.begin(), b.end(), std::greater());
    std::sort(c.begin(), c.end(), std::greater());

    LL ans = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (a[i].second != b[j].second && a[i].second != c[k].second && b[j].second != c[k].second) {
                    ans = std::max(ans, a[i].first + b[j].first + c[k].first);
                }
            }
        }
    }
    std::cout << ans << "\n";

}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
