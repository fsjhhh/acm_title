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
    int n, k;
    std::cin >> n >> k;
    if (k == 0) {
        for (int i = n; i > 0; i--) {
            std::cout << i << " \n"[i == 1];
        }
        return ;
    }
    std::vector<int> a(n);
    int cnt = 0;
    a[cnt ++ ] = 1;
    for (int i = n - k + 1; i <= n; i++) {
        a[cnt ++ ] = i;
    }
    for (int i = n - k; i > 1; i--) {
        a[cnt ++ ] = i;
    }
    for (int i = 0; i < cnt; i++) {
        std::cout << a[i] << " \n"[i == cnt - 1];
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
