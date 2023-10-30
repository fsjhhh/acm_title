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
    int n, k;
    std::cin >> n >> k;
    std::vector<LL> a(n + 1);
    for (int i = 1; i <= n; i ++ ) {
    	std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    std::map<LL, LL> mp;
    std::set<LL> s;
    LL ans = INFL, z = 0, c = INFL;
    for (int i = 2; i <= n; i ++ ) {
    	z += a[i] - a[i - 1];
    	s.insert(a[i] - a[i - 1]);
    	mp[a[i] - a[i - 1]] ++ ;
    	if (i == k) {
    		ans = std::min(ans, *s.begin() * z);
    	}
    	if (i > k) {
    		s.erase(a[i - k + 1] - a[i - k]);
    		z -= a[i - k + 1] - a[i - k];
    		mp[a[i - k + 1] - a[i - k]] -- ; 
    		if (mp[a[i - k + 1] - a[i - k]]) {
    			s.insert(a[i - k + 1] - a[i - k]);
    		}
    		ans = std::min(ans, *s.begin() * z);
    	}
    }
    std::cout << ans << "\n";
}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}