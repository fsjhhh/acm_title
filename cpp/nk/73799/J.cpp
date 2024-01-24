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
    int k;
    std::cin >> k;
    if (k == 1) {
    	int q;
    	std::cin >> q;
    	while (q -- ) {
    		LL x;
    		std::cin >> x;
    		std::cout << x - 1 << "\n";
    	}
    	return ;
    }
    std::vector<i128> cf = {1};
    while (cf.back() * k <= 1e18) {
    	cf.push_back(cf.back() * k);
    }
    for (int i = 1; i < (int)cf.size(); i++) {
    	cf[i] += cf[i - 1];
    }
    int q;
    std::cin >> q;
    while (q -- ) {
    	LL x;
    	std::cin >> x;
    	// double y = (x * (k - 1) * 1.0) / (k * 1.0) + 1;
    	int l = 0, r = cf.size() - 1;
    	while (l < r) {
    		int mid = (l + r) >> 1;
    		if (cf[mid] < x) {
    			l = mid + 1;
    		} else {
    			r = mid;
    		}
    	}
    	std::cout << l << "\n";
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