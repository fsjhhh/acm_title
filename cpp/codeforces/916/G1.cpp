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
typedef unsigned long long ULL;
typedef __int128 i128;
typedef std::pair<int, int> PII;
typedef std::pair<LL, LL> PLL;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;

const LL mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> v(n + 1);
    n *= 2;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        v[a[i]].push_back(i);
    }

    LL cnt = 1;
    std::vector<PII> ed;
    for (int i = 0; i < n; i++) {
        int m = v[a[i]].back();
        int j;
        for (j = i; j <= m; j++) {
            if (v[a[j]].back() >= m) {
                m = v[a[j]].back();
            }
        }
        ed.push_back({i, j - 1});
        i = j - 1;
    }

    std::cout << ed.size() << " ";
    for (auto [l, r] : ed) {
        std::set<int> s;
        for (int i = l; i <= r; i++) {
            s.insert(a[i]);
        }
        int z = 0;
        for (auto it : s) {
            int L, R;
            auto calc = [&](int x) -> void {
                std::deque<int> q;
                L = v[x][0];
                R = v[x][1];
                std::vector<bool> st(n);
                for (int i = L; i <= R; i++) {
                    if (!st[a[i]]) {
                        st[a[i]] = true;
                        q.push_back(a[i]);
                    }
                }
                while (q.size()) {
                    int cur = q.front();
                    q.pop_front();
                    int le = v[cur][0], ri = v[cur][1];
                    if (le < L) {
                        for (int i = le; i <= L; i++) {
                            if (!st[a[i]]) {
                                st[a[i]] = true;
                                q.push_back(a[i]);
                            }
                        }
                        L = le;
                    }
                    if (ri > R) {
                        for (int i = R; i <= ri; i++) {
                            if (!st[a[i]]) {
                                st[a[i]] = true;
                                q.push_back(a[i]);
                            } 
                        }
                        R = ri;
                    }
                }
            };
            calc(it);
            if (L == l && R == r) {
                z += 2;
            }
        }
        cnt = cnt * z % mod;
    }

    std::cout << cnt << "\n";


}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
