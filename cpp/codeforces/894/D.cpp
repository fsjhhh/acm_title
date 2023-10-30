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

typedef __int128 i128;

void solve()
{
    LL n;
    std::cin >> n;
    i128 l = 1, r = 10000000000;

    auto check = [&](i128 x) -> bool {
    	if (x * (x - 1) / 2 > n) {
    		return true;
    	}
    	return false;
    };

    while (l < r) {
    	i128 mid = (l + r) >> 1;
    	if (check(mid)) {
    		r = mid;
    	}
    	else {
    		l = mid + 1;
    	}
    }
    LL ans = l - 1;
    i128 t = (l - 1) * (l - 2) / 2;
    ans += n - t;
    std::cout << ans << "\n";
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