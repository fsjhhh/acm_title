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
//priority_queue 优先队列
#define int long long
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
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<int> h(n);
    for (int i = 0; i < n; i ++ ) {
    	std::cin >> h[i];
    }
    std::vector<std::vector<int>> edges(n);
    std::vector<int> d(n), c(n);
    for (int i = 0; i < m; i ++ ) {
    	int a, b;
    	std::cin >> a >> b;
    	a -- ;
    	b -- ;
    	edges[a].push_back(b);
    	d[b] ++ ;
    	c[a] ++ ;
    }
    std::queue<int> q;
    std::vector<int> ans(n), s;
    for (int i = 0; i < n; i ++ ) {
    	if (!d[i]) {
        s.push_back(i);
    		q.push(i);
    		ans[i] = h[i];
    	}
    }
    
    int maxx = 0;
    auto bfs = [&]() -> void {
    	while (1) {
    		int z = q.size();
    		if (z == 0) {
    			break;
    		}
    		for (int i = 0; i < z; i ++ ) {
    			int t = q.front();
    			q.pop();
    			for (auto it : edges[t]) {
    				d[it] -- ;
    				// int day = ans[t] / k;
    				// if (h[it] + k * day >= ans[t]) {
    				// 	ans[it] = std::max(h[it] + k * day, ans[it]);
    				// }
    				// else {
    				// 	ans[it] = std::max(h[it] + k * (day + 1), ans[it]);
    				// }
            // maxx = std::max(maxx, ans[it]);
            int fv = h[it] > ans[t] ? h[it] : (ans[t] - h[it] + k - 1) / k * k + h[it];
            ans[it] = std::max(fv, ans[it]);
    				if (d[it] == 0) {
    					q.push(it);
    				}
    			}
    		}
    	}
    };

    bfs();
    std::sort(s.begin(), s.end(), [&](int x, int y) -> bool {
      return h[x] < h[y];
    });

    auto calc = [&](auto self, int t) -> void {
      maxx = std::max(maxx, ans[t]);
      for (auto it : edges[t]) {
        // int day = ans[u] / k;
        // if (h[it] + k * day >= ans[u]) {
        //   if (ans[it] < h[it] + k * day) {
        //     self(self, it);          
        //     ans[it] = std::max(h[it] + k * day, ans[it]);
        //     maxx = std::max(maxx, ans[it]);
        //   }
        // }
        // else {
        //   if (ans[it] < h[it] + k * day + k) {
        //     self(self, it);          
        //     ans[it] = std::max(h[it] + k * (day + 1), ans[it]);
        //     maxx = std::max(maxx, ans[it]);
        //   }
        // }
        int fv = h[it] > ans[t] ? h[it] : (ans[t] - h[it] + k - 1) / k * k + h[it];
        if (fv > ans[it]) {
          maxx = std::max(maxx, fv);
          ans[it] = fv;
          self(self, it);
        }
      }
    };

    for (int i = 0; i < n; i ++ ) {
      maxx = std::max(maxx, ans[i]);
    }
    int zz = maxx - h[(int)s[0]];
    for (int i = 0; i < s.size() - 1; i ++ ) {
      h[s[i]] += k;
      ans[s[i]] += k;
      calc(calc, s[i]);
      zz = std::min(zz, maxx - h[(int)s[i + 1]]);
    }
    std::cout << zz << "\n";
}

signed main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}