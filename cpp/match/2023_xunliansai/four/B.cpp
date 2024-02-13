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

const int N = 1e6 + 10;
std::vector<int> f(N);

void init() {
	for (int i = 1; i < 10; i++) {
		f[i] = 1;
	}
	for (int i = 10; i < N; i++) {
		int m = i, k = 0;
		while (m) {
			k += m % 10;
			m /= 10;
		}
		bool pd = false;
		for (int j = 1; j <= std::min(k, j); j++) {
			if (!f[i - j]) {
				pd = true;
			}
		}
		if (pd) {
			f[i] = 1;
		} else {
			f[i] = 0;
		}
	}
}

void solve() {
    int n;
    std::cin >> n;
    if (f[n]) {
    	std::cout << "A\n";
    } else {
    	std::cout << "B\n";
    }
}

int main() {
    IOS;
    int t = 1;
    init();
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}