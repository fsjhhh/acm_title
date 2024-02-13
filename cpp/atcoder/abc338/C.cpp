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
    std::vector<int> q(n), a(n), b(n);
    for (int i = 0; i < n; i++) {
    	std::cin >> q[i];
    }
    for (int i = 0; i < n; i++) {
    	std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
    	std::cin >> b[i];
    }

    int mx = INF;
    for (int i = 0; i < n; i++) {
    	mx = std::min(mx, (a[i] == 0 ? INF : q[i] / a[i]));
    }

    int ans = 0;
    for (int i = 0; i <= mx; i++) {
    	std::vector<int> z(n);
    	for (int j = 0; j < n; j++) {
    		z[j] = q[j] - i * a[j];
    	}
    	int mxx = INF;
    	for (int j = 0; j < n; j++) {
    		mxx = std::min(mxx, b[j] == 0 ? INF : z[j] / b[j]);
    	}
    	ans = std::max(ans, mxx + i);
    }

    std::cout << ans << "\n";

}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}