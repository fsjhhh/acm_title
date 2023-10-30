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
// #include <ranges>
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

void solve(int t) {
    int n, m, k;
    std::cin >> n >> k >> m;
    std::vector<double> v(n);
    for (int i = 0; i < n; i ++ ) {
    	std::cin >> v[i];
    }

    std::vector<double> f(m + 1);
    for (int i = 1; i <= m; i ++ ) {
    	for (int j = 0; j < n; j ++ ) {
    		f[i] += v[j] * std::pow(f[i - 1], j);
    	}
    }
    double ans = std::pow(f[m], k);
    std::cout << "Case #" << t << ": ";
    std::cout << std::fixed << std::setprecision(10) << ans << "\n";
}

int main() {
    IOS;
    int t = 1, z = 1;
    std::cin >> t;
    while (t -- ) {
        solve(z);
        z ++ ;
    }
    return 0;
}