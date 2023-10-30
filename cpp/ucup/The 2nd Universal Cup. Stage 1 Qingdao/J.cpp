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
	LL a, b, c, d, t, v;
    std::cin >> a >> b >> c >> d >> v >> t;
    LL ans = (t / a + 1) * b + (t / c + 1) * d;
    if (std::min(a, c) <= v) {
        ans -- ;
    }
    else {
        for (LL i = 0; i < c; i ++ ) {
            if (i * a <= t && (i * a  - 1 + c) % c + 1 > v) {
                ans -= (t - i * a) / a / c + 1;
            }
        }
        for (LL i = 0; i < a; i ++ ) {
            if (i * c <= t && (i * c) % a > v) {
                ans -= (t - i * c) / a / c + 1;
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