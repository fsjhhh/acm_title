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
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> pre(n), suf(n);

    for (int i = 0; i < n; i++) {
        pre[i] = a[i] + (n - i - 1);
        suf[i] = a[i] + i;
    }

    for (int i = 1; i < n; i++) {
        pre[i] = std::max(pre[i], pre[i - 1]);
    }

    for (int i = n - 2; i >= 0; i--) {
        suf[i] = std::max(suf[i], suf[i + 1]);
    }

    int ans = INF;
    for (int i = 0; i < n; i++) {
        int c = a[i];
        if (i > 0) {
            c = std::max(c, pre[i - 1]);
        }
        if (i < n - 1) {
            c = std::max(c, suf[i + 1]);
        }
        ans = std::min(ans, c);
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
