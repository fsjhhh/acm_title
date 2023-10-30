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
    int n, m;
    std::cin >> n >> m;
    std::vector<int> v(n + 1);
    for (int i = 1; i <= n; i ++ ) {
    	std::cin >> v[i];
    }

    std::vector<int> c(n + 2);
    std::vector<int> d(m + 1), l(m + 1), r(m + 1);
    for (int i = 1; i <= m; i ++ ) {
    	std::cin >> d[i] >> l[i] >> r[i];
    }

    auto check = [&](int x) -> bool {
    	std::vector<int> di(n + 1, 0);
    	for (int i = 1; i <= x; i ++ ) {
    		di[l[i]] += d[i];
    		di[r[i] + 1] -= d[i];
    	}
    	for (int i = 1; i <= n; i ++ ) {
    		c[i] = c[i - 1] + di[i];
    		if (c[i] > v[i]) {
    			return false;
    		}
    	}
    	return true;
    };

    if (check(m)) {
    	std::cout << 0 << "\n";
    	return ;
    }

    int ll = 1, rr = m;
    while (ll < rr) {
    	int mid = (ll + rr) >> 1;
    	if (check(mid)) {
    		ll = mid + 1;
    	}
    	else {
    		rr = mid;
    	}
    }

    std::cout << -1 << "\n";
    std::cout << ll << "\n";
    

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