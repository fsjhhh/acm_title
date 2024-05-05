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
    int n;
    std::cin >> n;
    std::vector<PLL> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i].second;
    }
    for (int i = 0; i < n; i++) {
        std::cin >> a[i].first;
        a[i].first -- ;
    }

    PLL ans = {0, 0};
    std::priority_queue<LL, std::vector<LL>, std::greater<LL>> pq;
    for (int i = n - 1; i >= 0; i--) {
        pq.push(a[a[i].first].second);
        while ((int)pq.size() > (i + 1)) {
            pq.pop();
        }

        if ((int)pq.size() == (i + 1)) {
            ans = std::max(ans, {pq.top() * (LL)(i + 1), -(i + 1)});
        }

    }

    std::cout << ans.first << " " << -ans.second << "\n";

}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
