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
    std::vector<std::string> mp(n);
    for (int i = 0; i < n; i ++ ) {
    	std::cin >> mp[i];
    }
    if (m < 4) {
    	std::cout << "NO\n";
    	return ;
    }
    std::string s = "vika";
    int i, j;
    for (i = 0, j = 0; i < m && j < 4; i ++ ) {
    	for (int k = 0; k < n; k ++ ) {
    		if (mp[k][i] == s[j]) {
    			j ++ ;
    			break;
    		}
    	}
    }
    if (j == 4) {
    	std::cout << "YES\n";
    }
    else {
    	std::cout << "NO\n";
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