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
    int n, k;
    std::cin >> n >> k;
    std::vector<std::vector<int>> edges(n);
    std::set<PII> s;
    std::vector<int> in(n);
    for (int i = 0; i < k; i++) {
        std::vector<int> a(n);
        for (int j = 0; j < n; j++) {
            std::cin >> a[j];
            a[j] -- ;
            if (j > 1 && !s.count({a[j - 1], a[j]})) {
                edges[a[j - 1]].push_back(a[j]);
                s.insert({a[j - 1], a[j]});
                in[a[j]] ++ ;
            }
        }
    }

    std::queue<int> q;
    for (int i = 0; i < n; i++) {
        if (!in[i]) {
            q.push(i);
        }
    }

    while (q.size()) {
        auto u = q.front();
        q.pop();
        for (auto v : edges[u]) {
            in[v] -- ;
            if (!in[v]) {
                q.push(v);
            }
        }
    }

    bool ok = false;
    for (int i = 0; i < n; i++) {
        if (in[i]) {
            ok = true;
        }
    }

    if (ok) {
        std::cout << "NO\n";
    } else {
        std::cout << "YES\n";
    }

}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
