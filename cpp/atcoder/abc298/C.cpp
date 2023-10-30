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
    int n, q;
    std::cin >> n >> q;
    std::vector<std::map<int, int>> a(n);
    std::vector<std::set<int>> b(200010);
    while (q -- ) {
    	int op, i, j;
    	std::cin >> op;
    	if (op == 1) {
    		std::cin >> i >> j;
    		a[j - 1][i] ++ ;
    		b[i].insert(j);
    	}
    	if (op == 2) {
    		std::cin >> i;
    		for (auto [x, y] : a[i - 1]) {
    			for (int t = 0; t < y; t ++ ) {
    				std::cout << x << " ";
    			}
    		}
    		std::cout << "\n";
    	}
    	if (op == 3) {
    		std::cin >> i;
    		for (auto it : b[i]) {
    			std::cout << it << " ";
    		}
    		std::cout << "\n";
    	}
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