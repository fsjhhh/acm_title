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
    LL n, t;
    std::cin >> n >> t;
    std::vector<LL> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    LL sum = 0, q = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] <= t) {
            sum += a[i];
            q ++ ;
        }
    }
    if (sum == 0) {
        std::cout << 0 << "\n";
        return ;
    }

    LL ans = t / sum * q;
    t %= sum;

    LL cnt = 0, i = 0;
    while (t > 0 && cnt < n) {
        if (t >= a[i]) {
            t -= a[i];
            ans ++ ;
            cnt = 0;
        }
        else {
            cnt ++ ;
        }
        i = (i + 1) % n;
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
