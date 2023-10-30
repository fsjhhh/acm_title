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
#include <iomanip> // std::fixed() std::setprecision(x) 保留x位小数
#include <array>
//#include <bits/stdc++.h>
//priority_queue 优先队列
#define IOS                           \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(0);                  \
    std::cout.tie(0);

typedef long long LL;
typedef std::pair<int, int> PII;
typedef std::pair<LL, LL> PLL;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;
constexpr LL mod = 998244353;

typedef __int128 i128;

LL power(i128 x, i128 y) {
	LL res = 1;
	while (y) {
		if (y & 1) {
			res = res * x % mod;
		}
		y >>= 1;
		x = x * x % mod;
	}
	return res;
}

LL inv(i128 x) {
	return power(x, mod - 2);
}

void solve()
{
    LL n;
    std::cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; i ++ ) {
    	std::cin >> v[i];
    }
    std::sort(v.begin(), v.end());
    LL ans = n * n;
    for (int i = 0; i < 30; i ++ ) {
    	for (int l = 0, r = 0; l < n; l = r) {
    		std::array<LL, 2> cnt{};
    		while (r < n && v[l] / 2 == v[r] / 2) {
    			cnt[v[r] % 2] ++ ;
    			r ++ ;
    		}
    		ans += cnt[1] * (cnt[1] + cnt[0]);
    	}
    	
    	for (auto &it : v) {
    		it /= 2;
    	}
    }

    ans = ans % mod * inv(n * n) % mod;
    std::cout << ans << "\n";
}

int main()
{
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}