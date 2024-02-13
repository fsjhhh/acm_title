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
    int n, m;
    std::cin >> n >> m;
    int N = 2 * n - 1;
    std::vector<int> z(N + 2, 0);
    for (int i = 0; i < m; i++) {
    	int r, c;
    	std::cin >> r >> c;
    	int k = N - (r - 1) * 2;
    	if (c <= 2) {
    		int w = c + (r - 1);
    		z[1] ++ ;
    		z[w + 1] -- ;
    	}
    	if (c >= k - 1) {
    		int w = c + (r - 1);
    		z[w] ++ ;
    		z[N + 1] -- ;
    	}
    	int w = c + (r - 1);
    	z[w] ++ ;
    	z[w + 1] -- ;
    }

    std::string s = "";
    for (int i = 1; i <= N; i++) {
    	z[i] += z[i - 1];
    	if (z[i] > 0) {
    		s += '0';
    	} else {
    		s += '1';
    	}
    }

    std::cout << s << "\n";

}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}