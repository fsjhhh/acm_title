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
    int n, m, d;
    std::cin >> n >> m >> d;
    std::vector<int> v(n);
    for (int i = 0; i < n; i ++ ) {
    	std::cin >> v[i];
    }
    LL sum = 0, ans = 0;
    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    for (int i = 0; i < n; i ++ ) {
    	if (v[i] > 0) {
    		q.push(v[i]);
    		sum += v[i];
    	}
    	if (q.size() > m) {
    		sum -= q.top();
    		q.pop();
    	}
    	ans = std::max(ans, sum - 1LL * (i + 1) * d);
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