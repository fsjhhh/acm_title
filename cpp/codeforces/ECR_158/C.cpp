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
    int n;
    std::cin >> n;
    std::vector<LL> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());
    if (a[0] == a[n - 1]) {
        std::cout << 0 << "\n";
    } else {
        std::vector<LL> ans;
        int res = 0;
        LL x = a[0], y = a[n - 1];
        while (x != y) {
            ans.push_back(x);
            int z = x;
            x = (x + z) / 2;
            y = (y + z) / 2;
            res ++ ;
        }
        if (res <= n) {
            std::cout << res << "\n";
            for (int i = 0; i < res; i++) {
                std::cout << ans[i] << " \n"[i == res - 1];
            }
        } else {
            std::cout << res << "\n";
        }
    }

}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
