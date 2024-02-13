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
    int n, k, m;
    std::cin >> n >> k >> m;
    std::string s;
    std::cin >> s;
    int num = 0;
    std::string ans;
    bool pd = false;
    for (int i = 0, j = 0; num < n; i++) {
        std::vector<bool> st(k, 0);
        int cnt = 0;
        j = i;
        while (j < m && cnt < k) {
            if (!st[s[j] - 'a']) {
                cnt ++ ;
                st[s[j] - 'a'] = true;
            }
            j ++ ;
        }
        if (cnt < k) {
            pd = true;
            for (int w = 0; w < k; w++) {
                if (!st[w]) {
                    ans += (char)(w + 'a');
                    break;
                }
            }
            num ++ ;
        } else {
            ans += s[j - 1];
            num ++ ;
        }
        i = j - 1;
    }
    if (pd) {
        std::cout << "NO\n";
        std::cout << ans << "\n";
    } else {
        std::cout << "YES\n";
    }
}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}