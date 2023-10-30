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

#define int long long

void solve() {
    int n, d, p;
    std::cin >> n >> d >> p;
    std::vector<int> v(n);
    for (int i = 0; i < n; i ++ ) {
    	std::cin >> v[i];
    }
    std::sort(v.begin(), v.end(), std::greater());
    int sum = 0, ans = 0;
    int t = 0;
    for (int i = 0; i < n; i ++ ) {
    	sum += v[i];
    	if ((i + 1) % d == 0 || i == n - 1) {
    		if (sum > p) {
    			t = i + 1;
    			sum = 0;
    			ans += p;
    		}
    		else {
    			break;
    		}
    	}
    }
    for (int i = t; i < n; i ++ ) {
    	ans += v[i];
    }
    std::cout << ans << "\n";
}

signed main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}