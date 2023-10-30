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
    std::vector<int> v(n);
    for (int i = 0; i < n; i ++ ) {
    	std::cin >> v[i];
    }
    std::vector<int> ans;
    ans.push_back(v[0]);
    for (int i = 1; i < n; i ++ ) {
    	ans.push_back(v[i]);
    	if (v[i - 1] > v[i]) {
    		ans.push_back(v[i]);
    	}
    }
    std::cout << ans.size() << "\n";
    for (auto it : ans) {
    	std::cout << it << " ";
    }
    std::cout << "\n";
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