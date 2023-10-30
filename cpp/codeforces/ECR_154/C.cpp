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
    int n = s.size(), idx = 0;
    std::vector<int> v;
    int pd = 0;
    for (int i = 0; i < n; i ++ ) {
    	if (s[i] == '+') {
    		v.push_back(0);
    		v[0] = 1;
    	}
    	if (s[i] == '-') {
    		if (v.size()) {
    			if (v.back() == 1) {
    				int t = v.back();
    				v.pop_back();
    				if (v.size()) {
    					v.back() = t;
    				}
    			}
    			else {
    				if (v.back() == -1) {
    					pd -- ;
    				}
    				v.pop_back();
    			}
    		}
    		else {
    			std::cout << "NO\n";
    			return ;
    		}
    	}
    	if (s[i] == '1') {
    		if (v.size()) {
	    		if (!pd) {
	    			v.back() = 1;
	    		}
	    		else {
	    			std::cout << "NO\n";
	    			return ;
	    		}
	    	}
    	}
    	if (s[i] == '0') {
    		if (v.size()) {
	    		if (v.back() == 1) {
	    			std::cout << "NO\n";
	    			return ;
	    		}
	    		else if (v.back() == 0) {
	    			v.back() = -1;
	    			pd ++ ;
	    		}
	    	}
	    	else {
	    		std::cout << "NO\n";
	    		return ;
	    	}
    	}
    }
    std::cout << "YES\n";
}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}