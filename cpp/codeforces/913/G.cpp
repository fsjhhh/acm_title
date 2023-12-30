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

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::vector<std::vector<int>> edges(n);
    std::vector<int> d(n), f(n);
    for (int i = 0; i < n; i++) {
        f[i] = (s[i] - '0');
        int x;
        std::cin >> x;
        x -- ;
        edges[i].push_back(x);
        d[x] ++ ;
    }

    std::queue<int> q;

    for (int i = 0; i < n; i++) {
        if (!d[i]) {
            q.push(i);
        }
    }
    
    std::vector<int> ans;
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (auto v : edges[u]) {
            d[v] -- ;
            if (f[u]) {
                f[u] = 0;
                f[v] = (f[v] ? 0 : 1);
                ans.push_back(u);
            }
            if (!d[v]) {
                q.push(v);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (d[i]) {
            q.push(i);
            std::vector<int> z;
            int cnt = 0, t = 0, res = 0;
            while (q.size()) {
                int u = q.front();
                q.pop();
                z.push_back(u);
                d[u] = 0;
                for (auto v : edges[u]) {
                    if (f[u]) {
                        t = (t ? 0 : 1);
                    }
                    res += t;
                    if (d[v]) {
                        q.push(v);
                    }
                }
            }
            if (t) {
                std::cout << "-1\n";
                return ;
            }
            cnt = z.size(), t = 0;
            if (res < cnt - res) {
                for (auto x : z) {
                    if (f[x]) {
                        t = (t ? 0 : 1);
                    }
                    if (t) {
                        ans.push_back(x);
                    }
                }
            } else {
                for (auto x : z) {
                    if (f[x]) {
                        t = (t ? 0 : 1);
                    }
                    if (!t) {
                        ans.push_back(x);
                    }
                }
            }
        }
    }

    std::cout << ans.size() << "\n";
    for (auto it : ans) {
        std::cout << it + 1 << " ";
    }
    std::cout << "\n";

}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
