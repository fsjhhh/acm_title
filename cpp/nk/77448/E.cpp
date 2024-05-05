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

const int N = 2e6 + 10;
int h[N], e[2 * N], ne[2 * N], idx; // 邻接表
std::set<int> s[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

int cnt;
bool dfs(int u, int fa) {
    bool pd = true;
    for (int i = h[u]; i != -1; i = ne[i]) {
        int v = e[i];
        if (v == fa) {
            continue;
        }

        if (dfs(v, u) && pd) {
            if (s[v].size() > s[u].size()) {
                std::swap(s[u], s[v]);
            }
            for (auto it : s[v]) {
                if (s[u].find(it) == s[u].end()) {
                    s[u].insert(it);
                } else {
                    pd = false;
                    break;
                }
            }
        } else {
            pd = false;
        }
    }
    cnt += pd;
    return pd;

}

void solve() {
    memset(h, -1, sizeof h);
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::vector<int> st(n);

    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    for (int i = 1; i < n; i++) {
        int j;
        std::cin >> j;
        j -- ;
        add(i, j);
        add(j, i);
    }

    for (int i = 0; i < n; i++) {
        s[i].insert(a[i]);
    }
    
    dfs(0, -1);
    std::cout << cnt << "\n";

}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
