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
    std::string s;
    std::cin >> s;
    int n = s.size();
    bool a = false, b = false, c = false;
    for (int i = 0, j = 0; i < n; i++) {
    	j = i;
    	while (j < n && s[i] == s[j]) {
    		j ++ ;
    	}
    	if (s[i] == 'A') {
    		if (a || b || c) {
    			std::cout << "No\n";
    			return ;
    		} else {
    			a = true;
    		}
    	} else if (s[i] == 'B') {
    		if (b || c) {
    			std::cout << "No\n";
    			return ;
    		} else {
    			b = true;
    		}
    	} else {
    		if (c) {
    			std::cout << "No\n";
    			return ;
    		} else {
    			c = true;
    		}
    	}
    	i = j - 1;
    }
    std::cout << "Yes\n";
}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}