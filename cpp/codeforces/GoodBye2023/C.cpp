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
    LL sum = 0, odd = 0, even = 0;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
    	std::cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
    	if (a[i] % 2) {
    		odd ++ ;
    	} else {
    		even ++ ;
    	}
    	sum += a[i];
    	if (odd % 3 == 0) {
    		std::cout << sum - odd / 3 << " ";
    	} else if (odd % 3 == 1) {
    		if (odd + even == 1) {
    			std::cout << sum - odd / 3 << " ";
    			continue;
    		}
    		std::cout << sum - odd / 3 - 1 << " ";
    	} else {
    		std::cout << sum - odd / 3 << " ";
    	}
    }
    std::cout << "\n";

}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}