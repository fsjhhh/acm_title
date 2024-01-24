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
    int n, w;
    std::cin >> n >> w;
    std::vector<PII> a, b;
    for (int i = 0; i < n; i++) {
    	int x, y, z;
    	std::cin >> x >> y >> z;
    	if (x == 0) {
    		a.push_back({y, z});
    	} else {
    		b.push_back({y, z});
    	}
    }
    std::vector<int> f1(w + 1), f2(w + 1);
    for (int i = 0; i < (int)a.size(); i++) {
    	for (int j = w; j >= a[i].first; j--) {
    		f1[j] = std::max(f1[j], f1[j - a[i].first] + a[i].second);
    	} 
    }
    for (int i = 0; i < (int)b.size(); i++) {
    	for (int j = w; j >= b[i].first; j--) {
    		f2[j] = std::max(f2[j], f2[j - b[i].first] + b[i].second);
    	} 
    }
    if (f1[w] >= f2[w]) {
    	std::cout << f1[w] << " 0\n";
    } else {
    	std::cout << f2[w] << " 1\n";
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