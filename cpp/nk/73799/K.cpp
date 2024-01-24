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
    std::string s;
    std::cin >> s;
    int n = (int)s.size();
    std::string z = s;
    int ans1 = 0, ans2 = 0;
    std::vector<char> stk;
    if (z[0] == 'A') {
    	stk.push_back(0);
    }
    for (int i = 1; i < n; i++) {
    	if (z[i] == 'A') {
    		if (z[i - 1] == 'B') {
    			z[i] = 'B';
    			ans1 ++ ;
    		} else {
    			stk.push_back(i);
    		}
    	} else {
    		if (!stk.size()) {
    			continue;
    		}
    		ans1 += stk.size();
    		z[i] = 'C';
    		stk.clear();
    	}
    }

    stk.clear();
    z = s;
    if (z[n - 1] == 'A') {
    	stk.push_back(n - 1);
    }
    for (int i = n - 2; i >= 0; i--) {
		if (z[i] == 'A') {
    		if (z[i + 1] == 'B') {
    			z[i] = 'B';
    			ans2 ++ ;
    		} else {
    			stk.push_back(i);
    		}
    	} else {
    		if (!stk.size()) {
    			continue;
    		}
    		ans2 += stk.size();
    		z[i] = 'C';
    		stk.clear();
    	}
    }
    std::cout << std::max(ans1, ans2) << "\n";
}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}