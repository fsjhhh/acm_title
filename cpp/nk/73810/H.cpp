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

const int N = 3e5 + 10;
int h[N], e[N], ne[N], w[N], col[N], idx; // 邻接表
int dist[N][65];
bool st[N][65];
int n, m, l, base;

void add(int a, int b, int c, int co) // 邻接表加边
{
    e[idx] = b, w[idx] = c, col[idx] = co, ne[idx] = h[a], h[a] = idx ++ ;
}

struct node {
    int d, p, c;

    bool operator<(const node a) const {
        if (this -> d == a.d) {
            return this -> p > a.p;
        }
        return this -> d > a.d;
    }

};

void dijkstra()
{
    memset(dist, 0x3f, sizeof dist); // 初始化距离为正无穷
    dist[0][0] = 0;
    std::priority_queue<node> q; // 定义小根堆存储距离与点(优先队列)
    q.push({0, 0, 0});
    
    while (q.size())
    {
        auto t = q.top(); // 取出堆顶 
        q.pop();
        int di = t.d, ver = t.p; // 取出距离与点
        int z = t.c;

        if (st[ver][z]) continue;
        st[ver][z] = true;
        
        for (int i = h[ver]; i != -1; i = ne[i]) // 遍历邻接表
        {
            int j = e[i];
            if (!st[j][col[i]] && dist[j][col[i]] > di + w[i] * (z == col[i] ? 1 : base))
            {
                dist[j][col[i]] = di + w[i] * (z == col[i] ? 1 : base);
                q.push({dist[j][col[i]], j, col[i]});
            }
        }
        
    }
    
}

void solve() {
    memset(h, -1, sizeof h);
    std::cin >> n >> m >> l >> base;
    for (int i = 0; i < m; i++) {
        int u, v, co, w;
        std::cin >> u >> v >> co >> w;
        add(u, v, w, co);
    }
    for (int i = 1; i <= l; i++) {
        add(0, 1, 0, i);
    }
    dijkstra();
    int ans = INF;
    for (int i = 1; i <= l; i++) {
        ans = std::min(ans, dist[n][i]);
    }
    std::cout << (ans == INF ? -1 : ans) << "\n";
}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
