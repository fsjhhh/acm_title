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
    std::string s;
    std::cin >> s;
    int n = s.size();
    if (s == "()") {
    	std::cout << "NO\n";
    	return ;
    }
    std::cout << "YES\n";
    bool pd = false;
    for (int i = 0; i < n - 1; i ++ ) {
    	if (s[i] == s[i + 1]) {
    		pd = true;
    		break;
    	}
    }
    if (pd) {
    	for (int i = 1; i <= n; i ++ ) {
    		std::cout << "()";
    	}
    	std::cout << "\n";
    }
    else {
    	std::cout << std::string(n, '(') + std::string(n, ')') << "\n";
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