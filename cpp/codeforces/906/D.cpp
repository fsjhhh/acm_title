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
    LL n, c;
    std::cin >> n >> c;
    std::vector<LL> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<PLL> p(n - 1);
    for (int i = 1; i < n; i++) {
        p[i - 1] = {a[i] - c * (i + 1), i + 1};
    }

    std::sort(p.begin(), p.end(), std::greater<PLL>());
    
    LL x = a[0];
    for (auto [y, j] : p) {
        j -- ;
        if (y + x >= 0) {
            x += a[j];
        }
        else {
            std::cout << "No\n";
            return ;
        }
    }
    std::cout << "Yes\n";

}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}


