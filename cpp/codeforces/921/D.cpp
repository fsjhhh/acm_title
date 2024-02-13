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
    int n, m, k;
    std::cin >> n >> m >> k;

    int sum = 0;
    for (int i = 0; i < m; i++) {
    	int a, b, f;
    	std::cin >> a >> b >> f;
    	sum = (sum + f) % mod;
    }

    int C2 = (n * (n - 1)) / 2 % mod;
    int p = inv(C2);
    int q = ((1 - p) % mod + mod) % mod;

    std::vector<int> C(k + 1);
    C[0] = 1;
    int fz = 1, fm = 1;
    for (int i = 1; i <= k; i++) {
    	C[i] = C[i - 1] * (fz * (k - i + 1) % mod) % mod * inv((fm * i) % mod) % mod;
    }

    int ans = 0;
    for (int i = 0; i <= k; i++) {
    	ans = (ans + C[i] * power(p, i) % mod * power(q, (k - i)) % mod * ((sum + (sum + (i - 1) * m % mod) % mod) * i % mod * inv(2) % mod) % mod) % mod;
    }

    std::cout << ans << "\n";
}

signed main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}