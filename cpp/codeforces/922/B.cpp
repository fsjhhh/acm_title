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
    std::vector<PII> a(n);
    std::vector<PII> b(n);
    for (int i = 0; i < n; i++) {
    	std::cin >> a[i].first;
    	a[i].second = i;
    }
    for (int i = 0; i < n; i++) {
    	std::cin >> b[i].first;
    	b[i].second = i;
    }

    std::sort(a.begin(), a.end());

    std::vector<int> c(n);
    for (int i = 0; i < n; i++) {
    	c[i] = b[a[i].second].first;
    }

    for (int i = 0; i < n; i++) {
    	std::cout << a[i].first << " \n"[i == n - 1];
    }
    for (int i = 0; i < n; i++) {
    	std::cout << c[i] << " \n"[i == n - 1];
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