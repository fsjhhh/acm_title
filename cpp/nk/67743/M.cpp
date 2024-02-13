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

void solve() {
    int n;
    std::cin >> n;
    std::vector<LL> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::vector cnt_1(20, std::vector<LL>(36)), cnt_2(20, std::vector<LL>(36));
    LL ans = 0;
    for (int i = 0; i < n; i++) {
        LL x = a[i], k = 0;
        while (x) {
            k ++ ;
            x /= 10;
        }
        ans += (cnt_1[k][(36 - a[i] % 36) % 36]);
        i128 w = 1;
        for (int j = 1; j <= 19; j++) {
            w *= 10;
            cnt_1[j][(w % 36 * a[i] % 36) % 36] ++ ;
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        LL x = a[i], k = 0;
        while (x) {
            k ++ ;
            x /= 10;
        }
        ans += (cnt_2[k][(36 - a[i] % 36) % 36]);
        i128 w = 1;
        for (int j = 1; j <= 19; j++) {
            w *= 10;
            cnt_2[j][(w % 36 * a[i] % 36) % 36] ++ ;
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
