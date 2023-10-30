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
    int n, m, k, w;
    std::cin >> n >> m >> k >> w;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i ++ ) {
    	std::cin >> a[i];
    }
    for (int i = 0; i < n; i ++ ) {
    	std::cin >> b[i];
    }
    std::vector<int> p(n);
    std::vector<LL> sum(n);
    for (int i = 0; i < n; i ++ ) {
    	p[i] = i;
    	sum[i] = a[i];
    }

    auto find = [&](auto self, int u) -> int {
    	if (p[u] != u) {
    		p[u] = self(self, p[u]);
    	}
    	return p[u];
    };

    for (int i = 0; i < m; i ++ ) {
    	int x, y;
    	std::cin >> x >> y;
    	x -- ;
    	y -- ;
    	if (b[x] == b[y] && b[x] == 1) {
    		int px = find(find, x), py = find(find, y);
    		if (px != py) {
    			sum[px] += sum[py];
    			p[py] = px;
    		}
    	}
    }

    std::vector<LL> c;
    for (int i = 0; i < n; i ++ ) {
    	if (p[i] == i && b[i] == 1) {
    		c.push_back(sum[i]);
    	}
    } 
    std::sort(c.begin(), c.end(), std::greater());
    if (k == 0 && c.size()) {
    	std::cout << c[0] << "\n";
    	return ;
    }
    LL ans = 0;
    for (int i = 0; i < std::min(k, (int)c.size()); i ++ ) {
    	ans += c[i];
    }
    std::cout << ans << "\n";

}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}