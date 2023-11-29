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

const LL maxx = 2e12;

void solve() {
    LL D;
    std::cin >> D;
    std::vector<LL> a;
    for (LL i = 1; i * i <= maxx; i++) {
        a.push_back(i * i);
    }

    int n = a.size();
    LL ans = INFL;
    for (int i = 0; i < n; i++) {
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (a[i] + a[mid] - D <= 0) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        ans = std::min(ans, (LL)abs(a[i] + a[l] - D));
        if (l < n - 1) {
            ans = std::min(ans, (LL)abs(a[i] + a[l + 1] - D));
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
