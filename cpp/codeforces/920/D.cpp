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
    std::vector<LL> a(n), b(m);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        std::cin >> b[i];
    }

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end(), std::greater());

    LL ans = 0;
    int j = m - 1;
    for (int i = n - 1; i >= 0; i--) {
        ans += std::abs(a[i] - b[j]);
        j -- ;
    }

    LL res = ans;
    j = m - n;
    for (int i = 0; i < n; i++) {
        res += std::abs(a[i] - b[i]);
        res -= std::abs(a[i] - b[j]);
        ans = std::max(ans, res);
        j ++ ;
    }

    std::cout << ans << "\n";


}

signed main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}

/*
2 5 6
9 7 7 2 1

6 - 1
5 - 2
2 - 9

*/
