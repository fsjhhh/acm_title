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

int ask(int i, int j, int x) {
    std::cout << "? " << i << " " << j << " " << x << "\n";
    std::cout.flush();
    int res;
    std::cin >> res;
    return res;
}

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector st(n + 1, std::vector<int>(n + 1, -1));

    auto check = [&](int x) -> int {
        int ans = 0, j = 1, ls = 0;
        for (int i = n; i >= 1; i--) {
            while (j <= n && ask(i, j, x)) {
                ls ++ ;
                j ++ ;
            }
            ans += ls;
        }
        // std::cout << "ans: " << ans << "\n";
        // std::cout.flush();
        return ans;
    };

    int l = 1, r = n * n;
    k = n * n - k + 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        // std::cout << "mid: " << mid << "\n";
        // std::cout.flush();
        if (check(mid) >= k) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         std::cout << st[i][j] << " \n"[j == n];
    //     }
    // }
    std::cout << "! " << l << "\n";
} 

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}

