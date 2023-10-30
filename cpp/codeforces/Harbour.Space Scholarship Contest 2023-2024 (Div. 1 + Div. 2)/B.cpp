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
    int n, k;
    std::cin >> n >> k;
    std::string s, even = "", odd = "", ans = "";
    std::cin >> s;
    // std::cout << s << "\n";
    for (int i = 0; i < n; i ++ ) {
    	ans += s[i];
    	if (i % 2) {
    		even += s[i];
    	}
    	else {
    		odd += s[i];
    	}
    }
    // std::cout << even << " " << odd << "\n";
    std::sort(even.begin(), even.end());
    std::sort(odd.begin(), odd.end());
    // std::cout << even << " " << odd << "\n";
    std::string h;
    if (k % 2) {
    	int pd = false;
    	int a = 0, b = 0;
    	for (int i = 0; i < n; i ++ ) {
    		if (!pd) {
    			std::cout << odd[a ++ ];
    			pd = true;
    		}
    		else {
    			std::cout << even[b ++ ];
    			pd = false;
    		}
    	}
    	std::cout << "\n";
    }
    else {
    	std::sort(ans.begin(), ans.end());
    	std::cout << ans << "\n";
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