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
const int N = 1e7 + 10;
bool st[N];
std::vector<int> primes;
 
void get_primes() {
    int n = N - 1;
    for(int i = 2; i <= n; i++) {
        if(!st[i]) {
            primes.push_back(i);
        }
        for(int j = 0; primes[j] <= n / i; j++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) {
                break;
            }
        }
    }
}

struct DSU {
    std::vector<int> p, siz;
    int num;

    DSU() {}
    DSU(int n) {
        init(n);
    }

    void init(int n) {
        num = n;
        p.resize(n);
        std::iota(p.begin(), p.end(), 0);
        siz.assign(n, 1);
    }

    int find(int u) {
        if (u != p[u]) {
            p[u] = find(p[u]);
        }
        return p[u];
    }

    bool same(int u, int v) {
        return find(u) == find(v);
    }

    bool merge(int u, int v) {
        int fa_u = find(u), fa_v = find(v);
        if (fa_u == fa_v) {
            return false;
        }
        siz[fa_u] += siz[fa_v];
        p[fa_v] = fa_u;
        return true;
    }

    int size(int u) {
        return siz[find(u)];
    }

};

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::map<int, int> mp;

    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        mp[a[i]] ++ ;
    }

    bool ok = false;
    int id = 0, cnt = 0;
    for (auto [x, y] : mp) {
        if (x == 1) {
            ok = true;
            id = x;
            cnt = y;
        }
    }

    if (ok == 1) {
        if (cnt == n) {
            std::cout << "-1 -1\n";
        } else {
            std::cout << cnt << " " << n - cnt << "\n";
            for (int i = 0; i < cnt; i++) {
                std::cout << "1 ";
            }
            std::cout << "\n";
            for (auto [x, y] : mp) {
                if (x == 1) {
                    continue;
                }
                for (int i = 0; i < y; i++) {
                    std::cout << x << " ";
                }
            }
            std::cout << "\n";
        }
        return ;
    }

    std::map<int, std::vector<int>> ma;
    for (int i = 0; i < n; i++) {
        int w = a[i];
        for (int j = 2; j <= w / j; j++) {
            if (w % j == 0) {
                while (w % j == 0) {
                    w /= j;
                }
                ma[j].push_back(i);
            }
        }
        if (w > 1) {
            ma[w].push_back(i);
        }
    }

    DSU dsu(n);
    for (auto [x, it] : ma) {
        int z = it[0];
        for (auto y : it) {
            dsu.merge(z, y);
        }
    }

    if (dsu.size(0) == n) {
        std::cout << "-1 -1\n";
        return ;
    }
    int x = dsu.find(0);
    std::vector<int> b, c;
    for (int i = 0; i < n; i++) {
        if (dsu.same(0, i)) {
            b.push_back(a[i]);
        } else {
            c.push_back(a[i]);
        }
    }

    std::cout << b.size() << " " << c.size() << "\n";
    for (auto it : b) {
        std::cout << it << " ";
    }
    std::cout << "\n";
    for (auto it : c) {
        std::cout << it << " ";
    }
    std::cout << "\n";
}

signed main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
