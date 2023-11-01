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
    std::vector<LL> a(n + 2);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    std::sort(a.begin() + 1, a.begin() + n + 1);
    LL ans = 0, x = 0;
    for (int i = 1, j = n; i <= j; ) {
        if (i == j) {
            LL z = a[i] - x;
            ans += (z + 1) / 2;
            LL k = a[j] - (z + 1) / 2;
            if (k > 0) {
                ans++;
            }
            i++;
            continue;
        }
        if (x >= a[j]) {
            x = 0;
            ans++;
            j--;
            continue;
        } 
        if (a[i] + x < a[j]) {
            x += a[i];
            ans += a[i];
            a[i] = 0;
        } else {
            LL z = a[j] - x;
            ans += z;
            a[i] -= z;
            x += z;
        }
        if (a[i] == 0) {
            i++;
        }
    }
    std::cout << ans << "\n";
}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}


