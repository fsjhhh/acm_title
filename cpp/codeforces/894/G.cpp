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
    std::vector<int> v(n);
    for (int i = 0; i < n; i ++ ) {
    	std::cin >> v[i];
    }

    std::multiset<int> s, c{0};

    auto add = [&](int x) {
    	auto it = s.insert(x);
    	if (it != s.begin()) {
    		c.insert(*it - *std::prev(it));
    	}
    	auto r = std::next(it);
    	if (r != s.end()) {
    		c.insert(*r - *it);
    	}
    	if (it != s.begin() && r != s.end()) {
    		c.extract(*r - *std::prev(it));
    	}
    };

    auto del = [&](int x) {
    	auto it = s.find(x);
    	if (it != s.begin()) {
    		c.extract(*it - *std::prev(it));
    	}
    	auto r = std::next(it);
    	if (r != s.end()) {
    		c.extract(*r - *it);
    	}
    	if (it != s.begin() && r != s.end()) {
    		c.insert(*r - *std::prev(it));
    	}
    	s.erase(it);
    };

    for (int i = 0; i < n; i ++ ) {
    	add(v[i]);
    }

    int q;
    std::cin >> q;
    for (int i = 0; i < q; i ++ ) {
    	int x, y;
    	std::cin >> x >> y;
    	x -- ;
    	del(v[x]);
    	v[x] = y;
    	add(v[x]);
    	auto ans = *s.rbegin() + *c.rbegin();
    	std::cout << ans << " \n"[i == q - 1];
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