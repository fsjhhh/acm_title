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
    std::vector<bool> a(n);
    std::vector<int> b;
    for (int i = 0; i < k; i++) {
    	int x;
    	std::cin >> x;
    	x -- ;
    	a[x] = true;
    }

    for (int i = 0; i < n; i++) {
    	if (a[i]) {
    		b.push_back(i);
    	} else {
    		b.push_back(i);
    		b.push_back(i);
    	}
    }

    int m = b.size();
    if (m % 2 == 0) {
    	LL ans = 0;
    	for (int i = 1; i < m; i += 2) {
    		ans += (b[i] - b[i - 1]);
    	}
    	std::cout << ans << "\n";
    } else {
    	std::vector<LL> s_1(m), s_2(m);
    	for (int i = 0; i < m - 1; i += 2) {
    		if (i) {
    			s_1[i] = s_1[i - 1] + (b[i + 1] - b[i]);
    		} else {
    			s_1[i] = b[i + 1] - b[i];
    		}
    		s_1[i + 1] = s_1[i];
    	}
    	for (int i = m - 1; i > 0; i -= 2) {
    		if (i == m - 1) {
    			s_2[i] = b[i] - b[i - 1];
    		} else {
    			s_2[i] = s_2[i + 1] + b[i] - b[i - 1];
    		}
    		s_2[i - 1] = s_2[i];
    	}
    	LL ans = INFL;
    	for (int i = 0; i < m; i++) {
    		LL z = 0;
    		if (i != 0) {
    			z += s_1[i - 1];
    		}
    		if (i != m - 1) {
    			z += s_2[i + 1];
    		}
    		ans = std::min(ans, z);
    	}
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