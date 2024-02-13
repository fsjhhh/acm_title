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

const int N = 1e5;
const int inf = 1e9;

void solve() {
    int n, Q;
    std::cin >> n >> Q;
    std::vector<int> a(n);
    std::map<int, int> mp;

    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        mp[a[i]] ++ ;
    }

    std::set<int> S = {0};
    if (mp.size() <= 20) {
        for (auto [x, num] : mp) {
            for (int i = -N; i <= N; i++) {
                LL res = 1;
                int c = x - i;
                for (auto [y, cnt] : mp) {
                    int v = y - c;
                    if (v == 1) {
                        continue;
                    }
                    if (v == -1) {
                        if (cnt % 2) {
                            res *= -1;
                        }
                        continue;
                    }
                    for (int i = 0; i < cnt; i++) {
                        res *= v;
                        if (std::abs(res) > inf) {
                            break;
                        }
                    }
                    if (std::abs(res) > inf) {
                        break;
                    }
                }
                if (std::abs(res) <= inf) {
                    S.insert(res);
                }
            }
        }
    }

    while (Q -- ) {
        int x;
        std::cin >> x;
        if (S.count(x)) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
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