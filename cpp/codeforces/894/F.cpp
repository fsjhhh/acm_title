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

constexpr int N = 1E6 + 10;

void solve()
{
    int w, f;
    std::cin >> w >> f;

    int n, sum = 0;
    std::cin >> n;
    std::vector<int> v(n);
    std::bitset<N> pd;
    pd[0] = 1;

    for (int i = 0; i < n; i ++ ) {
    	std::cin >> v[i];
    	sum += v[i];
    	pd |= pd << v[i];
    }

    int ans = INF;
    for (int i = 0; i <= sum; i ++ ) {
    	if (pd[i]) {
    		ans = std::min(ans, std::max((i + w - 1) / w, (sum - i + f - 1) / f));
    	}
    }
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