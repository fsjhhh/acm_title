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
    int n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;
    std::vector<int> sum_b(n + 1), sum_a(n + 1);
    s = " " + s;
    for (int i = 1; i <= n; i++) {
        sum_b[i] = sum_b[i - 1] + (s[i] == 'B' ? 1 : 0);
        sum_a[i] = sum_a[i - 1] + (s[i] == 'A' ? 1 : 0);
    }
    if (sum_b[n] == k) {
        std::cout << 0 << "\n";
    } else if (sum_b[n] < k) {
        std::cout << 1 << "\n";
        int t = k - sum_b[n];
        for (int i = 1; i <= n; i++) {
            if (sum_a[i] >= t) {
                std::cout << i << " B\n";
                return ;
            }
        }
    } else {
        std::cout << 1 << "\n";
        int t = sum_b[n] - k;
        for (int i = 1; i <= n; i++) {
            if (sum_b[i] >= t) {
                std::cout << i << " A\n";
                return ;
            }
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
