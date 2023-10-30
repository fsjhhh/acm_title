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
#include <bitset>
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
    std::bitset<33> v(n);
    // for (int i = 0; i < 32; i ++ ) {
    // 	if (i == 16) {
    // 		std::cout << "\n";
    // 	}
    // 	std::cout << v[i];
    // }
    // std::cout << "\n";
    LL ans = 0;
    LL p = 1;
    for (int i = 16; i <= 31; i ++ ) {
    	ans = ans + v[i] * p;
    	p *= 2;
    }
    for (int i = 0; i <= 15; i ++ ) {
    	ans = ans + v[i] * p;
    	p *= 2;
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