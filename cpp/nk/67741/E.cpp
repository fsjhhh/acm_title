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
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
    	std::cin >> a[i];
    }

    std::vector<PII> edges(m);
    for (int i = 0; i < m; i++) {
    	int u, v;
    	std::cin >> u >> v;
    	u -- ;
    	v -- ;
    	edges[i] = {u, v};
    }

    int ans = INF;
    auto dfs = [&](auto self, int id) -> void {
    	if (id == m) {
    		std::vector<PII> b(n);
            for (int i = 0; i < n; i++) {
                b[i].first = a[i];
                b[i].second = i;
            }
            std::sort(b.begin(), b.end(), std::greater());

            int idx = 0;
            bool pd = false;
            for (int i = 0, j = 0; i < n; i++) {
                j = i;
                while (j < n && b[j].first == b[i].first) {
                    if (b[j].second == 0) {
                        pd = true;
                        break;
                    }
                    j ++ ;
                }
                if (pd) {
                    idx = i + 1;
                    break;
                }
                i = j - 1;
            }
            ans = std::min(ans, idx);
            return ;
    	}

        auto [u, v] = edges[id];
        a[u] += 3;
        self(self, id + 1);
        a[u] -= 3;

        a[v] += 3;
        self(self, id + 1);
        a[v] -= 3;

        a[u] += 1;
        a[v] += 1;
        self(self, id + 1);
        a[u] -= 1;
        a[v] -= 1;

    };

    dfs(dfs, 0);

    std::cout << ans << "\n";

}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}