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
    std::vector<LL> a(n + 1);
    for (int i = 1; i <= n; i ++ ) {
    	std::cin >> a[i];
    }
    std::vector sum(n + 1, std::vector<int>(61));
    for (int i = 1; i <= n; i ++ ) {
    	for (int j = 0; j <= 59; j ++ ) {
    		sum[i][j] = sum[i - 1][j] + (a[i] >> j & 1);
    	}
    }
    while (q -- ) {
    	LL l, r, x;
    	std::cin >> l >> r >> x;
    	std::vector<int> z(61);
    	for (int i = 0; i <= 59; i ++ ) {
    		if (sum[r][i] - sum[l - 1][i] > 0 || x >> i & 1) {
    			z[i] = 1;
    		}
    	}
    	LL ans = 0;
    	LL p = 1;
    	for (int i = 0; i <= 59; i ++ ) {
    		ans = ans + z[i] * p;
    		p *= 2;
    	}
    	std::cout << ans << "\n";
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