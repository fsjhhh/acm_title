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
#include <bits/stdc++.h>
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

#define int long long

struct DSU {
	std::vector<int> p, siz;
	int num;

	DSU() {}
	DSU(int n) {
		init(n);
	}

	void init(int n) {
		p.resize(n);
		std::iota(p.begin(), p.end(), 0);
		siz.assign(n, 1);
		num = n;
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
		num -- ;
		siz[fa_u] += siz[fa_v];
		p[fa_v] = fa_u;
		return true;
	}

	int size(int u) {
		return siz[find(u)];
	}

};

const int mod = 998244353;

int power(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) {
			res = res * a % mod;
		}
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

int power(int a, int b, int p) {
	int res = 1;
	while (b) {
		if (b & 1) {
			res = res * a % p;
		}
		a = a * a % p;
		b >>= 1;
	}
	return res;
}

int inv(int x) {
	return power(x, mod - 2);
}

int inv(int x, int p) {
	return power(x, p - 2, p);
}

void solve() {
    int h, w;
    std::cin >> h >> w;
    std::vector<std::string> mp(h);
    for (int i = 0; i < h; i++) {
    	std::cin >> mp[i];
    }

    DSU dsu(h * w);
    std::vector st(h, std::vector<bool>(w, 0));

    std::vector<int> dx = {-1, 0, 1, 0}, dy = {0, -1, 0, 1};
    auto dfs = [&](auto self, int x, int y) -> void {
    	st[x][y] = true;
    	for (int i = 0; i < 4; i++) {
    		int tx = x + dx[i], ty = y + dy[i];
    		if (tx < 0 || ty < 0 || (tx >= h) || ty >= w || st[tx][ty] || mp[tx][ty] == '.') {
    			continue;
    		} 
    		dsu.merge(x * w + y, tx * w + ty);
    		self(self, tx, ty);
    	}
    };

    int cnt = 0;
    for (int i = 0; i < h; i++) {
    	for (int j = 0; j < w; j++) {
    		if (!st[i][j] && mp[i][j] == '#') {
    			dfs(dfs, i, j);
    		}
    		if (mp[i][j] == '.') {
    			cnt ++ ;
    		}
    	}
    }

    int ans = 0;

    auto check = [&](int x, int y) -> int {
    	int z = dsu.num - cnt;
    	std::set<int> s;
    	for (int i = 0; i < 4; i++) {
    		int tx = x + dx[i], ty = y + dy[i];
    		if (tx < 0 || ty < 0 || tx >= h || ty >= w || mp[tx][ty] == '.') {
    			continue;
    		}
    		s.insert(dsu.find(tx * w + ty));
    	}
    	int k = s.size();
    	return z - k + 1;
    };

    for (int i = 0; i < h; i++) {
    	for (int j = 0; j < w; j++) {
    		if (mp[i][j] == '.') {
    			ans += check(i, j);
    		}
    	}
    }

    std::cout << ans % mod * inv(cnt) % mod << "\n";

}

signed main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}