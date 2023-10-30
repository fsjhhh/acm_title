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
    LL x, y;
    std::cin >> x >> y;
    LL ans = 0;
    auto check = [&](LL a, LL b) -> bool {
    	LL gcd = std::__gcd(a, b);
    	LL lcm = a / gcd * b;
    	if (gcd == x && lcm == y) {
    		return true;
    	}
    	return false;
    };
    for (LL i = x; i <= y; i ++ ) {
    	LL j = x * y / i;
    	if (i * j != x * y) {
    		continue;
    	} 
    	if (check(i, j)) {
    		ans ++ ;
    	}
    }
    std::cout << ans << "\n";
}

int main()
{
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}