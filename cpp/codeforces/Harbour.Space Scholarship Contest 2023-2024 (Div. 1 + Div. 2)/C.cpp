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
#include <iomanip> // std::fixed() std::setprecision(x) 保留x位小数
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
    LL n;
    std::cin >> n;
    // if (n == 2) {
    // 	std::cout << 1 << "\n";
    // 	std::cout << 2 << " " << 1 << "\n";
    // 	return ;
    // }
    LL p = 2, ans = 1;
    std::vector<LL> z;
    while (1) {
    	if (ans + p > n - 1) {
    		break;
    	}
    	z.push_back(p);
    	ans += p;
    	p *= 2;
    }
    LL ca = n - 1 - ans;
    std::vector<LL> e;
    for (int i = 0; i < 32; i ++ ) {
    	if (ca >> i & 1) {
    		e.push_back(1 << i);
    	}
    }
    std::cout << e.size() + z.size() + 2 << "\n";
    std::cout << n << " ";
    for (int i = 0; i < e.size(); i ++ ) {
    	n -= e[i];
    	std::cout << n << " ";
    }
    for (int i = z.size() - 1; i >= 0; i -- ) {
    	n -= z[i];
    	std::cout << n << " ";
    }
    std::cout << "1\n";
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