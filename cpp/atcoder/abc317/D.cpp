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
    int n;
    std::cin >> n;
    std::vector<LL> f{0};
    LL sum = 0;
    for (int i = 0; i < n; i ++ ) {
    	int x, y, z;
    	std::cin >> x >> y >> z;
    	LL cost = std::max(0, (x + y + 1) / 2 - x);
    	sum += z;
    	f.resize(sum + 1, INFL);
    	for (int j = sum; j >= z; j -- ) {
    		f[j] = std::min(f[j], f[j - z] + cost);
    	} 
    }
    LL ans = INFL;
    for (int i = (sum + 1) / 2; i < f.size(); i ++ ) {
    	ans = std::min(ans, f[i]);
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