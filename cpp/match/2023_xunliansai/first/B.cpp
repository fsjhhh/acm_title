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
    std::vector<PLL> a(n + 1);
    
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i].first;
        a[i].second = i;
    }

    std::sort(a.begin() + 1, a.end());

    int m;
    std::cin >> m;
    std::vector<LL> b(m + 1);
    
    for (int i = 1; i <= m; i++) {
        std::cin >> b[i];
    }

    std::sort(b.begin() + 1, b.end());

    std::vector<int> ans(n + 1);
    LL sum = 0;
    for (int i = 1, j = 0; i <= n; i++) {
        while (j <= m && sum <= a[i].first) {
            j ++ ;
            sum += b[j];
        }
        ans[a[i].second] = j - 1;
    }

    for (int i = 1; i <= n; i++) {
        std::cout << ans[i] << " \n"[i == n];
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
