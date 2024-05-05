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

#define int long long

void solve() {
    int n, m, s, p, q;
    std::cin >> n >> m >> s >> p >> q;
    s -- ;
    std::vector<int> a(p), b(q);
    std::vector<int> st(n + 1);
    for (int i = 0; i < p; i++) {
        std::cin >> a[i];
        st[a[i]] = 1;
    }
    for (int i = 0; i < q; i++) {
        std::cin >> b[i];
    }

    int mi = s, mx = s;

    int w = (n + m - 1) / m;
    int ls = 0;
    int ans = 0;
    for (int i = 0; i < w; i++) {
        int cnt1 = 0, cnt2 = 0, cnt3 = 0;
        for (int j = i * m + 1; j <= std::min((i + 1) * m, n); j++) {
            if (ls < q && j == b[ls]) {
                cnt3 ++ ;
                if (!st[j]) {
                    cnt1 ++ ;
                }
                ls ++ ;
            } else if (st[j]) {
                cnt2 ++ ;
            }
        }
        if (cnt1 + cnt2 == 0) {
            continue;
        }
        if (i < s) {
            mi = std::min(mi, i);
        } else if (i > s) {
            mx = std::max(mx, i);
        }

        int res = std::min(1 + cnt3, 1 + ((i == w - 1) ? (n % m ? n % m : m) : m) - cnt3);
        res = std::min(res, cnt1 + cnt2);
        ans += res;
    }

    int l = s - mi, r = mx - s;
    ans += (std::max(l, r) + 2 * std::min(l, r));

    std::cout << ans << '\n';

}

signed main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
