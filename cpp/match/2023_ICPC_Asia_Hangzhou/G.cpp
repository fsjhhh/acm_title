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

std::vector<int> ma;

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

    void dijstra(int x) {
        dist.assign(len, INF);
        st.assign(len, 0);
        dist[x] = 0;
        std::priority_queue<he> heap;
        heap.push({x, 0});

        while (heap.size()) {
            auto [u, dis] = heap.top();
            heap.pop();

            if (st[u]) {
                continue;
            }
            st[u] = true;

            for (auto [v, w] : edges[u]) {
                int z = dis + w;
                if (ma[v]) {
                    z = std::max(ma[v], z);
                }
                if (dist[v] > z) {
                    dist[v] = z;
                    heap.push({v, dist[v]});
                }
            }
        }

    }

};

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    ma.resize(n * m, 0);

    int sta;
    for (int i = 0; i < k; i++) {
        int x, y;
        std::cin >> x >> y;
        x -- ;
        y -- ;
        int a = x * m + y;
        if (i == 0) {
            sta = a;
        } else {
            ma[a] = k - i;
        }
    }

    std::vector<std::string> mp(n);
    for (int i = 0; i < n; i++) {
        std::cin >> mp[i];
    }

    Dijstra dij((n * m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mp[i][j] == '.') {
                if (i > 0 && mp[i - 1][j] == '.') {
                    dij.add((i - 1) * m + j, i * m + j, 1);
                    dij.add(i * m + j, (i - 1) * m + j, 1);
                }
                if (j > 0 && mp[i][j - 1] == '.') {
                    dij.add(i * m + j - 1, i * m + j, 1);
                    dij.add(i * m + j, i * m + j - 1, 1);
                }
            }
        }
    }

    dij.dijstra(sta);

    unsigned long long ans = 0;

    for (int i = 0; i < n * m; i++) {
        if (dij.dist[i] == INF) {
            continue;
        }
        ans += ((unsigned long long)dij.dist[i] * dij.dist[i]);
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
