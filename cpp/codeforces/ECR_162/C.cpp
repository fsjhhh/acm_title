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
    int n, q;
    std::cin >> n >> q;

    std::vector<LL> a(n + 1), sum(n + 1), cnt(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
        cnt[i] = cnt[i - 1] + (a[i] == 1);
    }

    while (q -- ) {
        int l, r;
        std::cin >> l >> r;
        LL s = (sum[r] - sum[l - 1]);
        LL c = (cnt[r] - cnt[l - 1]);
        if ((l == r) || (s - c) < ((r - l + 1))) {
            std::cout << "NO\n";
        } else {
            std::cout << "YES\n";
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
