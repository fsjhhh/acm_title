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
	constexpr LL mod = 998244353;

    int n, a, b, p, q;
    std::cin >> n >> a >> b >> p >> q;
    std::vector dp(n + 1, std::vector (n + 1, std::vector<int>(2, -1)));

    auto power = [&](LL x, LL y) -> LL {
    	LL res = 1;
    	while (y) {
    		if (y & 1) {
    			res = res * x % mod;
    		}
    		y >>= 1;
    		x = x * x % mod;
    	}
    	return res;
    };

    auto inv = [&](LL x) -> LL {
    	return power(x, mod - 2);
    };

    LL invp = inv(p);
    LL invq = inv(q);

    auto dfs = [&](auto self, LL u, LL v, int pos) -> LL {
    	if (u == n) {
    		return 1;
    	}
    	if (v == n) {
    		return 0;
    	}
    	if (dp[u][v][pos] != -1) {
    		return dp[u][v][pos];
    	}
    	LL val = 0;
    	if (!pos) {
    		for (int i = 1; i <= p; i ++ ) {
    			int x = std::min((LL)n, u + i);
    			val += self(self, x, v, pos ^ 1);
    			val %= mod;
    		}
    		val = val * invp % mod;
    	}
    	else {
    		for (int i = 1; i <= q; i ++ ) {
    			int y = std::min((LL)n, v + i);
    			val += self(self, u, y, pos ^ 1);
    			val %= mod;
    		}
    		val = val * invq % mod;
    	}
    	dp[u][v][pos] = val;
    	return dp[u][v][pos];
    };

    std::cout << dfs(dfs, a, b, 0) << "\n";

}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}