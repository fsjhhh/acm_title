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
    int x, y, n;
    std::cin >> x >> y >> n;
    std::vector<int> v(n);
    int p = 1;
    v[n - 1] = y;
    for (int i = n - 2; i >= 0; i -- ) {
    	v[i] = v[i + 1] - p;
    	p ++ ;
    }
    if (v[0] < x) {
    	std::cout << -1 << "\n";
    }
    else {
    	v[0] = x;
    	for (int i = 0; i < n; i ++ ) {
    		std::cout << v[i] << " ";
    	}
    	std::cout << "\n";
    }
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