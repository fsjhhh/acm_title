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

#define int long long
const int N = 5010;
int n, m, k;
PII z[N];
int dist[N];
bool st[N];

int spfa() {
    dist[0] = 0;
    std::queue<int> q;
    q.push(0);
    st[0] = true;
    
    while (q.size()) {
        auto t = q.front();
        q.pop();
        st[t] = false;
        for (int i = 0; i < m; i++) {
            int x = (t + z[i].first) % n, w = z[i].second;
            if (dist[x] > dist[t] + w) {
                dist[x] = dist[t] + w;
                if (!st[x]) {
                    q.push(x);
                    st[x] = true;
                }
            }
        }
    }
    
    return dist[k];
}

void solve() {
    std::cin >> n >> m >> k;
    k = n - k;
    for (int i = 0; i < m; i++) {
        std::cin >> z[i].first >> z[i].second;
    }

    for (int i = 0; i <= n; i++) {
        dist[i] = INFL;
        st[i] = false;
    }
    
    int res = spfa();
    
    if (res == INFL) {
        std::cout << "-1\n";
    } else {
        std::cout << res << "\n";
    }
}

signed main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
