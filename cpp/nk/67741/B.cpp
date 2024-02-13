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
    std::set<PII> sx, sd, s1, s2;
    bool ok_1 = false, ok_2 = false;
    for (int i = 0; i < n; i++) {
    	int r, c;
    	std::cin >> r >> c;
    	r -- ;
    	if (sx.find({r, c}) != sx.end()) {
    		ok_1 = true;
    	}
    	if (sd.find({r, c}) != sd.end()) {
    		ok_2 = true;
    	}
    	if (c <= 0) {
    		s1.insert({r, c});
    		sx.insert({!r, c - 1});
    		sx.insert({!r, c});
    		sx.insert({!r, std::min(c + 1, 0)});
    	}
    	if (c >= 0) {
    		s2.insert({r, c});
    		sd.insert({!r, std::max(c - 1, 0)});
    		sd.insert({!r, c});
    		sd.insert({!r, c + 1});
    	}
    	
    }

    if (ok_1 && ok_2) {
    	std::cout << "0\n";
    	return ;
    }
    if (ok_1) {
    	if (s2.size()) {
    		std::cout << "1\n";
    	} else {
    		std::cout << "2\n";
    	}
    	return ;
    }
    if (ok_2) {
    	if (s1.size()) {
    		std::cout << "1\n";
    	} else {
    		std::cout << "2\n";
    	}
    	return ;
    }
    if (!ok_1 && !ok_2) {
    	if (s1.find({1, 0}) != s1.end()) {
    		std::cout << "2\n";
    		return ;
    	}
    	if (s1.find({0, -1}) != s1.end() && s2.find({0, 1}) != s2.end()) {
    		std::cout << "1\n";
    	} else if (s1.find({0, -1}) != s1.end()) {
    		std::cout << "2\n";
    	} else if (s2.find({0, 1}) != s2.end()) {
    		std::cout << "2\n";
    	} else {
    		if (s1.size() && s2.size()) {
    			std::cout << "2\n";
    		} else {
    			std::cout << "3\n";
    		}
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