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

    void dijstra(int start = 0) {
        dist.assign(len, INF);
        st.assign(len, 0);
        dist[start] = 0;
        std::priority_queue<he> heap;
        heap.push({start, 0});

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
    int n, m;
    std::cin >> n >> m;

    std::map<int, int> mp;
    int idx = n;

    Dijstra dij(n + m + 10);
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u -- ;
        v -- ;
        if (!mp[w]) {
            mp[w] = idx ++ ;
        }

        dij.add(u, mp[w], 1);
        dij.add(v, mp[w], 1);
        dij.add(mp[w], u, 0);
        dij.add(mp[w], v, 0);

    }

    int start, end;
    std::cin >> start >> end;
    start -- ;
    end -- ;

    dij.dijstra(start);

    std::cout << dij.dist[end] << "\n";

}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
