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

#define f first
#define s second
typedef long long LL;
typedef __int128 i128;
typedef std::pair<int, int> PII;
typedef std::pair<LL, LL> PLL;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;
#define pi 3.14159265
void solve() {
    double n;
	std::cin >> n;
	if(n == 0)
	{
		std::cout <<"A: 0.00 0.00" << std::endl;
		std::cout <<"B: 0.00 0.00" << std::endl;
		std::cout <<"C: 0.00 0.00" << std::endl;
		std::cout <<"D: 0.00 0.00" << std::endl;
		std::cout <<"E: 0.00 0.00" << std::endl;
        return;
	}
	std::vector<std::pair<double, double>> a(6);
	a[1].f = n + n * sin(18.0 * pi / 180.0);
	a[1].s = 0;
	a[4].f = -a[1].f;
	a[4].s = 0;
	a[2].f = n * sin(54.0 * pi / 180.0);
	a[2].s = -(n * sin(36.0 * pi / 180.0) + n * sin(72.0 * pi / 180.0));
	a[3].f = -a[2].f;
	a[3].s = a[2].s;
	a[5].f = 0;
	a[5].s = n * sin(72.0 * pi / 180.0);
	std::cout << std::fixed << std::setprecision(2) << "A: " << a[1].f << ' ' << a[1].s << std::endl;
	std::cout << std::fixed << std::setprecision(2) << "B: " << a[2].f << ' ' << a[2].s << std::endl;
	std::cout << std::fixed << std::setprecision(2) << "C: " << a[3].f << ' ' << a[3].s << std::endl;
	std::cout << std::fixed << std::setprecision(2) << "D: " << a[4].f << ' ' << a[4].s << std::endl;
	std::cout << std::fixed << std::setprecision(2) << "E: " << a[5].f << ' ' << a[5].s << std::endl;
}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}