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
    LL n, k;
    std::cin >> n >> k;
    std::vector<LL> a((1 << n), 0);
    for (int i = 0; i < (1 << n); i++) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end(), std::greater<LL>());

    LL ans = 0;
    for (int i = 0; i < n; i++) {
        int t = ((1 << (n - i)) / 2);
        int ls = ((1 << (n - i)) - 1);
        for (int j = t - 1; j >= 0; j--) {
            int l = t, r = ls;
            while (l < r) {
                int mid = (l + r + 1) >> 1;
                if (a[mid] >= a[j] - k) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
            if (a[j] - a[l] > k) {
                break;
            }
            ls = l - 1;
            ans ++ ;
            if (ls < t) {
                break;
            }
        }

        for (int i = 0; i < t; i++) {
            a.pop_back();
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
