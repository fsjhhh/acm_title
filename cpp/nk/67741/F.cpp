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

#define int long long
const int mod = 1e9 + 7;

int power(int a, int b) {
	if (a == 0) {
		return 0;
	}
	int res = 1;
	while (b) {
		if (b & 1) {
			res = res * a % mod;
		}
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

int power(int a, int b, int p) {
	if (a == 0) {
		return 0;
	}
	int res = 1;
	while (b) {
		if (b & 1) {
			res = res * a % p;
		}
		a = a * a % p;
		b >>= 1;
	}
	return res;
}

int inv(int x) {
	return power(x, mod - 2);
}

int inv(int x, int p) {
	return power(x, p - 2, p);
}

void solve() {
    LL n, m;
    std::cin >> n >> m;
    std::vector<LL> a(m + 1);
  	std::vector<LL> jc(m + 1, 1);
  	for (int i = 1; i <= m; i++) {
  		jc[i] = (i * jc[i - 1]) % mod;
  	}
  	std::vector<LL> C(m + 1, 1);
  	LL fz = 1, fm = 1;
    for (int i = 1; i <= m; i++) {
    	fz = fz * (m - i + 1) % mod;
    	fm = fm * i % mod;
    	C[i] = fz * inv(fm) % mod;
    }

    LL ans_1 = 0, ans_2 = 0;
    for (int i = 0; i <= m; i++) {
    	if (i % 2) {
    		ans_1 = (C[i] * power(m - i, n) % mod + ans_1) % mod;
    	} else {
    		ans_2 = (C[i] * power(m - i, n) % mod + ans_2) % mod;
    	}
    }

    LL ans = (ans_2 - ans_1 + mod) % mod;
    ans = (ans * inv(jc[m]) % mod);

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