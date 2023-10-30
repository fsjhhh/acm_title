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
    std::vector<LL> a(n + 2);
    for (int i = 1; i <= n; i ++ ) {
    	std::cin >> a[i];
    }
    std::vector<LL> q(n + 2), h(n + 2, INF);
    for (int i = 1; i <= n; i ++ ) {
    	q[i] = std::max(q[i - 1], a[i]);
    }
    for (int i = n; i >= 1; i -- ) {
    	h[i] = std::min(h[i + 1], a[i]);
    }
    LL cnt = 0;
    for (int i = 1; i <= n; i ++ ) {
    	bool pd = false;
    	for (int j = i + 1; j <= n; j += i) {
    		if (q[j - 1] > h[j]) {
    			pd = true;
    			break;
    		}
    	}
    	if (!pd) {
    		cnt ++ ;
    	}
    }
    std::cout << cnt << "\n";
}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}