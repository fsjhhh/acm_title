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
    int n;
    std::cin >> n;
    std::vector a(n, std::vector<int>(n)), copy_a(n, std::vector<int>(n)), b(n, std::vector<int>(n));
    for (int i = 0; i < n; i ++ ) {
    	for (int j = 0; j < n; j ++ ) {
    		std::cin >> a[i][j];
    		copy_a[i][j] = a[i][j]; 
    	}
    }
    for (int i = 0; i < n; i ++ ) {
    	for (int j = 0; j < n; j ++ ) {
    		std::cin >> b[i][j]; 
    	}
    }

    auto func = [&]() -> void {
    	for (int j = 0; j < n; j ++ ) {
    		for (int i = n - 1; i >= 0; i -- ) {
    			a[j][n - i - 1] = copy_a[i][j];
    		}
    	}
    	for (int i = 0; i < n; i ++ ) {
    		for (int j = 0; j < n; j ++ ) {
    			copy_a[i][j] = a[i][j];
    		}
    	}
    };

    for (int k = 0; k < 4; k ++ ) {
    	bool pd = false;
    	for (int i = 0; i < n; i ++ ) {
    		for (int j = 0; j < n; j ++ ) {
    			if (a[i][j] == 1 && b[i][j] == 0) {
    				pd = true;
    				break;
    			}
    		}
    		if (pd) {
    			break;
    		}
    	}
    	if (!pd) {
    		std::cout << "Yes\n";
    		return ;
    	}
    	func();
    }
    std::cout << "No\n";
}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}