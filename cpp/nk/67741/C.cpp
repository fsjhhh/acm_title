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
    LL n, Q, tc;
    std::cin >> n >> Q >> tc;

    std::vector<LL> t(n + 1);
    for (int i = 1; i <= n; i++) {
    	std::cin >> t[i];
    }

    std::sort(t.begin() + 1, t.end());
    LL sum = 0;
    for (int i = 1; i <= n; i++) {
    	t[i] += t[i - 1];
    	sum += t[i];
    }

    std::vector<PLL> q(Q);
    for (int i = 0; i < Q; i++) {
    	std::cin >> q[i].first;
    	q[i].second = i;
    }

    std::sort(q.begin(), q.end());

    std::vector<LL> ans(Q);
    LL tmp = 0;
    int j = 0;
    for (int i = n; i >= 0; i--) {
    	while (j < Q && (tmp * tc > q[j].first)) {
    		ans[q[j].second] = t[i + 1] + tc;
    		j ++ ;
    	}
    	if (j == Q) {
    		break;
    	}
    	tmp ++ ;
    }

    if (j != Q) {
    	for (; j < Q; j++) {
    		ans[q[j].second] = tc;
    	}
    }

    for (int i = 0; i < Q; i++) {
    	std::cout << ans[i] << "\n";
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