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
    std::vector<LL> a(n), b(n), c(n);
    std::map<LL, LL> mp;
    for (int i = 0; i < n; i++) {
    	std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
    	std::cin >> b[i];
    	mp[b[i]] ++ ;
    }
    for (int i = 0; i < n; i++) {
    	std::cin >> c[i];
    }

    std::sort(a.rbegin(), a.rend());
    std::sort(c.rbegin(), c.rend());
    std::vector<LL> z;
    for (int i = 0; i < n; i++) {
    	auto w = mp.upper_bound(a[i]);
    	if (w != mp.end()) {
    		int k = (*w).first;
    		mp[k] -- ;
    		if (!mp[k]) {
    			mp.erase(k);
    		}
    		z.push_back(k - a[i]);
    	}
    }

    std::sort(z.begin(), z.end());

    LL ans = 0;
    for (int i = 0; i < n; i++) {
    	ans += c[i] * z[i];
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