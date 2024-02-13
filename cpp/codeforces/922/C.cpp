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
    LL a, b, r;
    std::cin >> a >> b >> r;
    if (a < b) {
    	std::swap(a, b);
    }
    bool pd = false, limit = false;
    std::vector<int> d(64);
    for (int i = 62; i >= 0; i--) {
    	if ((a >> i & 1) != (b >> i & 1)) {
    		if ((a >> i & 1)) {
    			if (pd) {
    				if (limit || (r >> i & 1)) {
    					d[i] = 1;
    				}
    			} else {
    				pd = true;
    				if ((r >> i & 1)) {
    					limit = true;
    				}
    			}
    		} else {
    			if ((r >> i & 1)) {
    				limit = true;
    			}
    		}
    	} else {
    		if ((r >> i & 1)) {
    			limit = true;
    		}
    	}
    }

    LL x = 0;
    for (int i = 0; i <= 62; i++) {
    	if (d[i]) {
    		x += (1ll << i);
    	}
    }

    // std::cout << x << "\n";

    std::cout << std::abs((a ^ x) - (b ^ x)) << "\n";

}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}