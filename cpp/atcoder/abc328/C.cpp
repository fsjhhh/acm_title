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
    int n, q;
    std::cin >> n >> q;
    std::string s;
    std::cin >> s;
    s = " " + s;
    std::vector<int> d(n + 1), sum(n + 1);
    for (int i = 1; i <= n; i++) {
        if (s[i] == s[i - 1]) {
            d[i] ++ ;
        }
    }

    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + d[i];
    }

    while (q -- ) {
        int l, r;
        std::cin >> l >> r;
        if (d[l] == 1) {
            std::cout << sum[r] - sum[l - 1] - 1 << "\n";
        } else {
            std::cout << sum[r] - sum[l - 1] << "\n";
        }
    }

}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
