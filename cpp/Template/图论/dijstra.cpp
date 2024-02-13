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

struct Dijstra_ {
	struct node {
		int w;
	};
	int len;
	std::vector<std::vector<node>> mp;
	std::vector<int> dist;
	std::vector<bool> st;

	Dijstra_() {}
	Dijstra_(int n) {
		init(n);
	}

	void init(int n) {
		len = n;
		mp.resize(n);
		dist.resize(len, INF);
		st.resize(len, 0);
		for (int i = 0; i < n; i++) {
			mp[i].resize(n, {INF});
		}
	}

	void add(int u, int v, int w) {
		mp[u][v].w = std::min(mp[u][v].w, w);
	}

	void dijstra() {
		dist.assign(len, INF);
		st.assign(len, 0);
		dist[0] = 0;
		for (int i = 0; i < len; i++) {
			int t = -1;
			for (int j = 0; j < len; j++) {
				if (!st[j] && (t == -1 || dist[j] < dist[t])) {
					t = j;
				}
			}
			st[t] = true;
			for (int j = 0; j < len; j++) {
				dist[j] = std::min(dist[j], dist[t] + mp[t][j].w);
			}
		}
	}

};

struct Dijstra {
	struct node {
		int to, w;
	};
	struct he {
		int id, dis;

		bool operator<(const he other) const {
			return this -> dis > other.dis;
		}

	};
	int len;
	std::vector<std::vector<node>> edges;
	std::vector<int> dist;
	std::vector<bool> st;

	Dijstra() {}
	Dijstra(int n) {
		init(n);
	}

	void init(int n) {
		len = n;
		edges.resize(n);
		dist.resize(n, INF);
		st.resize(n, 0);
	}

	void add(int u, int v, int w) {
		edges[u].push_back({v, w});
	}

	void dijstra() {
		dist.assign(len, INF);
		st.assign(len, 0);
		dist[0] = 0;
		std::priority_queue<he> heap;
		heap.push({0, 0});

		while (heap.size()) {
			auto [u, dis] = heap.top();
			heap.pop();

			if (st[u]) {
				continue;
			}
			st[u] = true;

			for (auto [v, w] : edges[u]) {
				if (dist[v] > dis + w) {
					dist[v] = dis + w;
					heap.push({v, dist[v]});
				}
			}
		}

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