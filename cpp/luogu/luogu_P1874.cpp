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
    std::string s;
    int n;
    std::cin >> s;
    std::cin >> n;
    int len = s.size(), sum = 0;
    std::vector<int> a(len);
    for (int i = 0; i < len; i ++ ) {
    	a[i] = s[i] - '0';
    	sum += a[i];
    }

    if (sum > n) {
    	std::cout << -1 << "\n";
    	return ;
    }

    auto calc_sum_1 = [&](int l, int r) -> int {
    	int res = 0;
    	for (int i = l; i <= r; i ++ ) {
    		res = res * 10 + a[i];
    	}
    	return res;
    };

    auto calc_sum_2 = [&](int l, int r) -> int {
    	int res = 0;
    	for (int i = l; i <= r; i ++ ) {
    		res += a[i];
    	}
    	return res;
    };

    int ans = INF;
    auto dfs = [&](auto self, int res, int u, int cnt) -> void {
    	int tmp_1 = res + calc_sum_1(u + 1, len - 1);
    	if (tmp_1 < n) {
    		return ;
    	}

    	if (ans <= cnt) {
    		return ;
    	}

    	int tmp_2 = res + calc_sum_2(u + 1, len - 1);
    	if (tmp_2 > n) {
    		return ;
    	}

    	if (tmp_1 == n) {
    		ans = std::min(ans, cnt);
    		return ;
    	}

    	for (int i = u + 1; i < len; i ++ ) {
    		self(self, res + calc_sum_1(u + 1, i), i, cnt + 1);
    	}
    };

    dfs(dfs, 0, -1, 0);

    if (ans == INF) {
    	std::cout << -1 << "\n";
    }
    else {
    	std::cout << ans << "\n";
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