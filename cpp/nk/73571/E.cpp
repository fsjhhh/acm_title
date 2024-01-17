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
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> mp(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char z;
            std::cin >> z;
            mp[i] += z;
        }
    }

    std::string as = "", bs = "";
    for (int i = 0; i < n; i++) {
        if (i % 2) {
            for (int j = m - 1; j >= 0; j--) {
                as += mp[i][j];
            }
        } else {
            for (int j = 0; j < m; j++) {
                as += mp[i][j]; 
            }
        }
    }

    for (int i = 0; i < m; i++) {
        if (i % 2) {
            for (int j = n - 1; j >= 0; j--) {
                bs += mp[j][i];
            }
        } else {
            for (int j = 0; j < n; j++) {
                bs += mp[j][i];
            }
        }
    }

    int len = as.size();
    
    std::vector<std::set<int>> ast(26), bst(26);
    for (int i = 0; i < len; i++) {
        ast[as[i] - 'a'].insert(i);
    }
    for (int i = 0; i < len; i++) {
        bst[bs[i] - 'a'].insert(i);
    }

    int q;
    std::cin >> q;
    while (q -- ) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int x, y;
            char c;
            std::cin >> x >> y >> c;
            int sa, sb;
            if ((x - 1) % 2) {
                sa = (x - 1) * m + m - 1 - y + 1;
            } else {
                sa = (x - 1) * m + y - 1;
            }

            if ((y - 1) % 2) {
                sb = (y - 1) * n + n - 1 - x + 1;
            } else {
                sb = (y - 1) * n + x - 1;
            }

            ast[as[sa] - 'a'].erase(sa);
            bst[bs[sb] - 'a'].erase(sb);

            ast[c - 'a'].insert(sa);
            bst[c - 'a'].insert(sb);

            as[sa] = c;
            bs[sb] = c;

        } else if (op == 2) {
            int x, y;
            std::cin >> x >> y;
            int s;
            if ((x - 1) % 2) {
                s = (x - 1) * m + m - 1 - y + 1;
            } else {
                s = (x - 1) * m + y - 1;
            }

            int minn = n * m;

            for (int i = 0; i < 26; i++) {
                if (ast[i].size() && i != as[s] - 'a') {
                    auto z = ast[i].lower_bound(s);
                    if (z == ast[i].end()) {
                        continue;
                    }
                    minn = std::min(minn, *z);
                }
            }
            std::cout << minn - s << "\n";

        } else {
            int x, y;
            std::cin >> x >> y;
            int s;
            int minn = n * m;

            if ((y - 1) % 2) {
                s = (y - 1) * n + n - 1 - x + 1;
            } else {
                s = (y - 1) * n + x - 1;
            }

            for (int i = 0; i < 26; i++) {
                if (bst[i].size() && i != bs[s] - 'a') {
                    auto z = bst[i].lower_bound(s);
                    if (z == bst[i].end()) {
                        continue;
                    }
                    minn = std::min(minn, *z);
                }
            }
            std::cout << minn - s << "\n";

        }
    }
    
}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
