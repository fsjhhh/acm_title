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
    LL n, k;
    std::cin >> n >> k;
    std::vector<LL> a(n);
    LL sum = 0;
    for (int i = 0; i < n; i++) {
    	std::cin >> a[i];
    	a[i] -= k;
    	sum += a[i];
    }

    int z = 0, f = 0, ze = 0;
    for (int i = 0; i < n; i++) {
    	if (a[i] > 0) {
    		z ++ ;
    	} else if (a[i] < 0) {
    		f ++ ;
    	} else {
    		ze ++ ;
    	}
    }

    if (!z && !f) {
    	std::cout << "0\n";
    } else if (!z && !ze) {
    	LL ans = -a[0];
    	for (int i = 1; i < n; i++) {
    		ans = std::__gcd(ans, -a[i]);
    	}
    	std::cout << (-sum) / ans - n << "\n";
    } else if (!f && !ze) {
    	LL ans = a[0];
    	for (int i = 1; i < n; i++) {
    		ans = std::__gcd(ans, a[i]);
    	}
    	std::cout << sum / ans - n << "\n";
    } else {
    	std::cout << "-1\n";
    }

}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}