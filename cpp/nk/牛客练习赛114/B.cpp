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

void solve()
{
    int a1, b1, c1, a2, b2, c2;
    std::cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
    double w = a1 * b2 * 0.01 + b1 * c2 * 0.01 + c1 * a2 * 0.01 + a2 * b1 * 0.01 + b2 * c1 * 0.01 + c2 * a1 * 0.01;
    if (w == 0) {
    	std::cout << "Sorry,NoBruteForce" << "\n";
    	return ;
    }
    double p = a1 * a2 * 0.01 + b1 * b2 * 0.01 + c1 * c2 * 0.01, d = 1.0;
    double ans = 0;
    for (int i = 1; i <= 100; i ++ ) {
    	ans += (w * d * i);
    	d *= p;
    }
    std::cout << std::fixed << std::setprecision(10) << ans << "\n";
}

int main()
{
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}