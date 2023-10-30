#include <iostream>
#include <cstdio>
#include <string>
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

#define int long long

struct node {
    std::string name;
    std::string city;
};

node a[1010];
int st[1010];
int p[1010], num[1010];
std::string g[1010];

std::map<int, std::set<std::string>> v;

void solve() {
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < n; i++) {
        p[i] = i;
        st[i] = -1;
        num[i] = 1;
    }
    
    for (int i = 0; i < n; i++) {
        std::cin >> a[i].name >> a[i].city;
        for (auto &x : a[i].name) {
            x = std::tolower(x);
        }
        std::string z = "";
        for (int j = 0; j < a[i].name.size(); j++) {
            if (a[i].name[j] == '_') {
                v[i].insert(z);
                z = "";
                continue;
            }
            z += a[i].name[j];
        }
        v[i].insert(z);
    }
    for (int i = 0; i < m; i++) {
        std::cin >> g[i];
    }

    auto find_1 = [&](auto self, int u) -> int {
        if (p[u] != u) {
            p[u] = self(self, p[u]);
        }
        return p[u];
    };
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i].city == a[j].city) {
                int fa = find_1(find_1, i), fb = find_1(find_1, j);
                if (fa != fb) {
                    p[fb] = fa;
                    num[fa] += num[fb];
                }
            }
        }
    }
    
    std::map<std::string, std::vector<int>> mp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::string z = a[i].name;
            if (v[i].find(g[j]) != v[i].end()) {
                mp[g[j]].push_back(i);
            }
        }
    }
    
    for (auto [x, y] : mp) {
        if (y.size() <= 1) {
            continue;
        }
        for (int i = 1; i < y.size(); i++) {
            int fa = find_1(find_1, y[0]), fb = find_1(find_1, y[i]);
            if (fa != fb) {
                p[fb] = fa;
                num[fa] += num[fb];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << num[find_1(find_1, i)] - 1 << "\n";
    }

}

signed main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
