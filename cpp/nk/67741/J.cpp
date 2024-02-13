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
    int n, x, y;
    std::cin >> n >> x >> y;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
    	std::cin >> a[i];
    }

    auto check = [&](int d) -> bool {
    	std::set<int> S;
    	int lst = y;
    	if (std::abs(x - y) <= d) {
    		S.insert(x);
    	}

    	for (auto it : a) {
    		if (!S.empty() && std::abs(it - lst) <= d) {
    			S.insert(lst);
    		}

    		while (!S.empty() && *S.begin() < it - d) {
    			S.erase(*S.begin());
    		}

    		while (!S.empty() && *S.rbegin() > it + d) {
    			S.erase(*S.rbegin());
    		}
    		lst = it;
    	}

    	return !S.empty();

    };

    int l = 0, r = 1e9;
    while (l < r) {
    	int mid = (l + r) >> 1;
    	if (check(mid)) {
    		r = mid;
    	} else {
    		l = mid + 1;
    	}
    }

    std::cout << l << "\n";

}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}