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

const int mod = 998244353;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::vector<std::string> s(n);
    for (int i = 0; i < n; i++) {
    	std::cin >> a[i] >> s[i];
    	a[i] -- ;
    }

    LL ans = 1;
    std::vector<int> vis(n, -1);
    for (int i = 0; i < n; i++) {
    	int j = i;
    	while (vis[j] == -1) {
    		vis[j] = i;
    		j = a[j];
    	} 

    	if (vis[j] == i) {
    		int k = j, len = 0;
    		do {
    			k = a[k];
    			len ++ ;
    		} while (k != j);

    		LL res = 0;

    		for (int v = 0; v < 5; v++) {
    			int x = v;
    			for (int w = 0; w < len; w++) {
    				x = s[k][x] - 'A';
    				k = a[k];
    			}
    			res += x == v;
    		}
    		ans = ans * res % mod;
    	}

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