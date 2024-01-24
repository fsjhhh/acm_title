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

struct DSU {
	std::vector<int> p, siz;
	int num;

	DSU() {}
	DSU(int n) {
		init(n);
	}

	void init(int n) {
		num = n;
		p.resize(n);
		std::iota(p.begin(), p.end(), 0);
		siz.assign(n, 1);
	}

	int find(int u) {
		if (u != p[u]) {
			p[u] = find(p[u]);
		}
		return p[u];
	}

	bool same(int u, int v) {
		return find(u) == find(v);
	}

	bool merge(int u, int v) {
		int fa_u = find(u), fa_v = find(v);
		if (fa_u == fa_v) {
			return false;
		}
		siz[fa_u] += siz[fa_v];
		p[fa_v] = fa_u;
		return true;
	}

	int size(int u) {
		return siz[find(u)];
	}

};

void solve() {
    
}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}