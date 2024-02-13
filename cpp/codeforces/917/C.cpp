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
    int n, k, d;
    std::cin >> n >> k >> d;
    std::vector<int> a(n + 1), b(k);
    for (int i = 1; i <= n; i++) {
    	std::cin >> a[i];
    }

    for (int i = 0; i < k; i++) {
    	std::cin >> b[i];
    }

    LL sum = 0;
    for (int i = 1; i <= n; i++) {
    	if (a[i] == i) {
    		sum ++ ;
    	}
    }

    LL ans = 0;
    for (int i = 1, j = 0; i <= std::min(d, 2 * n + 1); i++) {
    	ans = std::max(ans, sum + (d - i) / 2);
    	for (int i = 1; i <= b[j]; i++) {
    		if (a[i] == i) {
    			sum -- ;
    			a[i] ++ ;
    		} else {
    			a[i] ++ ;
    			if (a[i] == i) {
    				sum ++ ;
    			}
    		}
    	}
    	j = (j + 1) % k;
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