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
    int n;
    std::cin >> n;
    int mex = 0;
    std::vector<int> a(n);
    std::map<int, int> mp;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        mp[a[i]] ++ ;
    }

    std::vector<PII> b(mp.begin(), mp.end());

    for (int i = 0; i < (int)b.size(); i++) {
        if (mex == b[i].first) {
            mex ++ ;
        } else if (mex < b[i].first) {
            break;
        }
    }

    LL ans = 0, idx = 0;
    for (int i = 0; i < (int)b.size(); i++) {
        if (b[i].first < mex && b[i].second == 1) {
            idx ++ ;
            if (idx == 2) {
                std::cout << b[i].first << "\n";
                return ;
            }
        } else if (b[i].first > mex) {
            break;
        }
    }

    std::cout << mex << "\n";

}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
