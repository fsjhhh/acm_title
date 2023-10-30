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
//#include <bits/stdc++.h>
//priority_queue 优先队列
#define IOS                           \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(0);                  \
    std::cout.tie(0);

typedef long long LL;
typedef std::pair<int, int> PII;
typedef std::pair<LL, LL> PLL;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;

void solve() {
    LL n, k;
    std::cin >> n >> k;
    double t = 0.499999999999999999;
    // if (k == 1) {
    // 	std::cout << n << " " << n << "\n";
    // 	return ;
    // }
    // std::cout << t << "\n";
    LL minn = 0, maxx = 0;
   	if (2 * n < k) {
   		maxx = 2 * n;
   	}
   	else {
   		double q = n - 0.5 * (k - 1);
   		LL t_q = q;
   		if (q - t_q < 0.5) {
   			maxx = k - 1 + t_q;
   		}
   		else {
   			maxx = k + t_q;
   		}
   	}
   	if (2 * n < k) {
   		minn = 0;
   	}
   	else {
   		double q = n - t * (k - 1);
   		LL t_q = q;
   		if (q - t_q < 0.5) {
   			minn = t_q;
   		}
   		else {
   			minn = t_q + 1;
   		}
   	}
    std::cout << minn << " " << maxx << "\n";
}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}