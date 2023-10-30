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

const LL mod = 998244353;

void solve() {
    int Q;
    std::cin >> Q;
    std::deque<LL> q = {1};
    LL ans = 1;

    auto power = [&](LL a, LL b) -> LL {
    	LL res = 1;
    	while (b) {
    		if (b & 1) {
    			res = res * a % mod;
    		}
    		b >>= 1;
    		a = a * a % mod;
    	}
    	return res;
    };

    while (Q -- ) {
    	int op;
    	std::cin >> op;
    	if (op == 1) {
    		int x;
    		std::cin >> x;
    		q.push_back(x);
    		ans = (ans * 10 % mod + x) % mod;
    	}
    	if (op == 2) {
    		int z = q[0];
    		q.pop_front();
    		LL c = power(10, q.size());
    		ans = (ans - z * c % mod + mod) % mod;
    	}
    	if (op == 3) {
    		std::cout << ans << "\n";
    	}
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