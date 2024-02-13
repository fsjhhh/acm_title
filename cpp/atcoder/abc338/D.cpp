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
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(m);
    for (int i = 0; i < m; i++) {
    	std::cin >> a[i];
    }

    std::vector<LL> sum(n + 1, 0);
    LL ans = 0;
    for (int i = 1; i < m; i++) {
    	int t1 = std::abs(a[i] - a[i - 1]);
    	int t2 = std::min(a[i], a[i - 1]) + n - std::max(a[i], a[i - 1]);
    	ans += std::min(t1, t2);
    	if (t1 < t2) {
    		sum[std::min(a[i], a[i - 1])] += (t2 - t1);
    		sum[std::max(a[i], a[i - 1])] -= (t2 - t1);
    	} else if (t1 > t2) {
    		sum[1] += (t1 - t2);
    		sum[std::min(a[i], a[i - 1])] -= (t1 - t2);
    		sum[std::max(a[i], a[i - 1])] += (t1 - t2);
    	}
    }

    LL mn = INFL;
    for (int i = 1; i <= n; i++) {
    	sum[i] += sum[i - 1];
    	mn = std::min(mn, sum[i]);
    }

    std::cout << ans + mn << "\n";

}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}