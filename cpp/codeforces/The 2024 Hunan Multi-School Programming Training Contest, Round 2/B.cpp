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
    std::string v, s;
    std::cin >> v >> s;
    std::vector<int> st(26, 0);
    int cnt = 0, num = 0;

    std::set<int> se[26];
    for (int i = 0; i < (int)s.size(); i++) {
        se[s[i] - 'a'].insert(i + 1);
        if (!st[s[i] - 'a']) {
            cnt ++ ;
            st[s[i] - 'a'] = 1;
        }
        if (cnt == (int)v.size()) {
            num ++ ;
            cnt = 0;
            st.assign(26, 0);
        }
    }


    int n;
    std::cin >> n;
    while (n -- ) {
        std::string q;
        std::cin >> q;
        if ((int)q.size() != num + 1) {
            std::cout << "0\n";
            continue;
        }

        int ls = 0;
        bool pd = false;
        for (auto it : q) {
            auto z = se[it - 'a'].upper_bound(ls);
            if (z == se[it - 'a'].end()) {
                pd = true;
                std::cout << "1\n";
                break;
            } else {
                ls = (*z);
            }
        }

        if (!pd) {
            std::cout << "0\n";
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
