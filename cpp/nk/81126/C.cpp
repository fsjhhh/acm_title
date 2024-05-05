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

LL power(LL a, LL b) {
    LL res = 1;
    while (b) {
        if (b & 1) {
            res = res * a;
        }
        a = a * a;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::map<int, LL> mp;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        mp[a[i]] ++ ;
    }
    std::sort(a.begin(), a.end());
    int q;
    std::cin >> q;

    LL ans = mp[q];
    LL cnt = 1;
    LL k = 0;
    for (int i = q * 3, j = q * 3 - 2; j <= 1e9; i *= 3, j = j * 3 - 2) {
        // std::cout << j << " " << i << "\n";
        LL res = 0;
        while (k < n && a[k] <= i) {
            if (a[k] >= j) {
                res ++ ;
            }
            k ++ ;
        }
        ans = std::max(ans, res * power(2, cnt));
        cnt ++ ;
    }

    std::cout << ans << "\n";

}

signed main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
