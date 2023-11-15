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
    int n, x;
    std::cin >> n >> x;
    std::vector<int> a(n - 1);
    for (int i = 0; i < n - 1; i++) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    
    int ans = 0;
    for (int i = 1; i < n - 2; i++) {
        ans += a[i];
    }
    
    if (x - ans <= a[0]) {
        std::cout << 0 << "\n";
    }
    else if (x - ans <= a[n - 2]) {
        std::cout << x - ans << "\n";
    }
    else {
        std::cout << -1 << "\n";
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

