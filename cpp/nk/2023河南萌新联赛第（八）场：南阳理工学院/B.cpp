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
    if (n == 0) {
        std::cout << 0 << "\n";
        return ;
    }
    constexpr int N = 500010, mod = 1e9 + 7;
    std::vector<LL> a(N, 0), b(N, 0), sum_1(N, 0), sum_2(N, 0);
    for (int i = 0; i < n; i ++ ) {
    	int l1, r1, l2, r2;
    	std::cin >> l1 >> r1 >> l2 >> r2;
        if (r1 < l2 || r2 < l1) {
            a[l1] ++ ;
            a[r1 + 1] -- ;
            a[l2] ++ ;
            a[r2 + 1] -- ;
        }
        else {
            int l = std::min(l1, l2), r = std::max(r1, r2);
            a[l] ++ ;
            a[r + 1] -- ;
        }
        b[l1] ++ ;
        b[r1 + 1] -- ;
        b[l2] ++ ;
        b[r2 + 1] -- ;
    }
    for (int i = 1; i < N; i ++ ) {
    	sum_1[i] = sum_1[i - 1] + a[i];
        sum_2[i] = sum_2[i - 1] + b[i];
    }

    auto power = [&](LL x, LL y) -> LL {
        LL res = 1;
        while (y) {
            if (y & 1) {
                res = res * x % mod;
            }
            y >>= 1;
            x = x * x % mod;
        }
        return res;
    };

    LL ans = 0;
    for (int i = 1; i <= N - 10; i ++ ) {
    	if (sum_1[i] == n) {
            ans = (ans + power(2, sum_2[i] - sum_1[i])) % mod;
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