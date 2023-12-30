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
    std::map<int, std::priority_queue<int>> mp;
    std::map<int, int> ans;
    std::vector<bool> st(n);
    std::vector<int> s(n + 2);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int t, x;
        std::cin >> t >> x;
        if (t == 1) {
            st[i] = true;
            mp[x].push(i);
        } else {
            if (mp[x].size()) {
                s[i + 1] -- ;
                s[mp[x].top() + 1] ++ ;
                ans[mp[x].top()] ++ ;
                mp[x].pop();
            } else {
                std::cout << -1 << "\n";
                return ;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        s[i] += s[i - 1];
        sum = std::max(sum, s[i]);
    }

    std::cout << sum << "\n";
    for (int i = 0; i < n; i++) {
        if (st[i] && ans[i]) {
            std::cout << "1 ";
        } else if (st[i]) {
            std::cout << "0 ";
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
