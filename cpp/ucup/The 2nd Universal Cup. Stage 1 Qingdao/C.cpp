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

struct Node {
	std::string s;
	int v, k;
};

void solve() {
    int n;
    std::cin >> n;
    std::vector<Node> a(n + 1);
    for (int i = 1; i <= n; i ++ ) {
    	std::cin >> a[i].s;
    	if (a[i].s == "add") {
    		std::cin >> a[i].v;
    		a[i].k = -1;
    	}
    	else {
    		std::cin >> a[i].v >> a[i].k;
    	}
    }
    int r = 0;
    constexpr int mod = 256;
    std::map<int, std::set<int>> v;
    int i = 1;
    while (i <= n) {
    	if (v[i].find(r) != v[i].end()) {
    		std::cout << "No\n";
    		return ;
    	}
    	if (a[i].s == "add") {
    		r = (r + a[i].v) % mod;
    		i ++ ;
    	}
    	else if (a[i].s == "beq") {
    		if (r == a[i].v) {
    			v[i].insert(r);
    			i = a[i].k;
    		}
    		else {
    			i ++ ;
    		}
    	}
    	else if (a[i].s == "bne") {
    		if (r != a[i].v) {
    			v[i].insert(r);
    			i = a[i].k;
    		}
    		else {
    			i ++ ;
    		}
    	}
    	else if (a[i].s == "blt") {
    		if (r < a[i].v) {
    			v[i].insert(r);
    			i = a[i].k;
    		}
    		else {
    			i ++ ;
    		}
    	}
    	else if (a[i].s == "bgt") {
    		if (r > a[i].v) {
    			v[i].insert(r);
    			i = a[i].k;
    		}
    		else {
    			i ++ ;
    		}
    	}
    }
    std::cout << "Yes\n";
}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}