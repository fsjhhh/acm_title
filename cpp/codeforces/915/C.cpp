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
    std::vector<int> v;
    for (int i = 0; i < n; i++) {
        while (v.size() && s[v.back()] < s[i]) {
            v.pop_back();
        }
        v.push_back(i);
    }

    int m = v.size(), ans = 0;
    while (ans < m && s[v[ans]] == s[v[0]]) {
        ans ++ ;
    }

    ans = m - ans;
    for (int i = 0; i < m - 1 - i; i++) {
        std::swap(s[v[i]], s[v[m - 1 - i]]);
    }

    for (int i = 1; i < n; i++) {
        if (s[i] < s[i - 1]) {
            std::cout << "-1\n";
            return ;
        }
    }
    std::cout << ans << "\n";

}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
