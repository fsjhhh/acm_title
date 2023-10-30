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
    int l, r;
    std::cin >> l >> r;
    if (r <= 3) {
    	std::cout << -1 << "\n";
    	return ;
    }
    if (l != r) {
    	if (r % 2 == 0) {
    		std::cout << r / 2 << " " << r / 2 << "\n";
    	}
    	else {
    		std::cout << (r - 1) / 2 << " " << (r - 1) / 2 << "\n";
    	}
    }
    else {
    	if (l % 2 == 0) {
    		std::cout << l / 2 << " " << l / 2 << "\n";
    	}
    	else {
    		for (int i = 2; i <= sqrt(l); i ++ ) {
    			if (l % i == 0) {
    				int t = l / i;
    				std::cout << t << " " << t * (i - 1) << "\n";
    				return ;
    			}
    		}
			std::cout << -1 << "\n";
    	}
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