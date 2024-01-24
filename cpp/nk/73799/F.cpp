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
    int n, m;
    std::cin >> n >> m;
    std::string s;
    std::cin >> s;
    std::string c = "";
    while (m -- ) {
    	std::string op;
    	std::cin >> op;
    	if (op == "cc") {
    		int st, ed;
    		std::cin >> st >> ed;
    		st -- ;
    		ed -- ;
    		c = s.substr(st, ed - st + 1);
    	} else if (op == "cx") {
    		int st, ed;
    		std::cin >> st >> ed;
    		st -- ;
    		ed -- ;
    		c = s.substr(st, ed - st + 1);
    		std::string z1 = s.substr(0, st);
    		std::string z2 = s.substr(ed + 1, (int)s.size() - ed);
    		s = z1 + z2;
    	} else {
    		int idx;
    		std::cin >> idx;
    		if (idx < 0 || idx > (int)s.size()) {
    			continue;
    		}
    		std::string z1 = s.substr(0, idx);
    		std::string z2 = s.substr(idx, (int)s.size() - idx);
    		s = z1 + c + z2;
    	}
    }
    std::cout << s << "\n";
}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}