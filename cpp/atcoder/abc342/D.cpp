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

    LL ans = 0, cnt = 0;
    std::map<LL, LL> mp;
    for (int i = 0; i < n; i++) {
        LL a;
        std::cin >> a;
        if (a == 0) {
            ans += (n - i - 1);
            ans += cnt;
            continue;
        }
        cnt ++ ;

        for (int j = 2; j * j <= a; j++) {
            while (a % (j * j) == 0) {
                a /= (j * j);
            }
        }

        ans += mp[a];
        mp[a] ++ ;

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
