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

struct node {
	int d, id, pd;
};

void solve() {
    int n;
    std::cin >> n;
    std::vector<node> a(2 * n);
    for (int i = 0; i < n; i++) {
    	int x, y;
    	std::cin >> x >> y;
    	if (x > y) {
    		std::swap(x, y);
    	}
    	a[i * 2] = {x, i, 0};
    	a[i * 2 + 1] = {y, i, 1};
    } 

    auto cmp = [&](node x, node y) -> bool {
    	if (x.d == y.d) {
    		if (x.id == y.id) {
    			return x.pd < y.pd;
    		}
    		if (x.pd == y.pd && x.pd == 1) {
    			return x.id > y.id;
    		}
    		if (x.pd == y.pd && x.pd == 0) {
    			return x.id < y.id;
    		}
    		return x.pd > y.pd;
    	}
    	return x.d < y.d;
    };

    std::sort(a.begin(), a.end(), cmp);

    std::vector<int> stk;
    for (int i = 0; i < 2 * n; i++) {
    	if (a[i].pd == 0) {
    		stk.push_back(a[i].id);
    	} else {
    		if (stk.back() != a[i].id) {
    			std::cout << "Yes\n";
    			return ;
    		}
    		stk.pop_back();
    	}
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