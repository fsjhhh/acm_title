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

const int N = 1e6;
const LL M = 1e12;
std::set<LL> s;
std::vector<LL> a;

void init() {
	s.insert(1);
	for (LL i = 2; i <= N; i++) {
		LL po = i * i;
		while (po <= M) {
			// std::cerr << i << " " << po << "\n";
			s.insert(po);
			po *= i;
		}
	}
	for (auto it : s) {
		a.push_back(it);
	}
}

void solve() {
	LL n;
	std::cin >> n;
	auto it = std::upper_bound(a.begin(), a.end(), n) - a.begin();
	std::cout << it << "\n";
	
}

int main() {
    IOS;
    int t = 1;
    init();
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}