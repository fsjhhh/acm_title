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
    std::vector a(n, std::vector<int>(n)), b(n, std::vector<int>(n));

    for (int i = 0; i < n; i ++ ) {
    	std::string s;
    	std::cin >> s;
    	for (int j = 0; j < n; j ++ ) {
    		a[i][j] = s[j] - '0';
    	}
    }

    int ans = 0;
    for (int i = 0; i < n; i ++ ) {
    	for (int j = 0; j < n; j ++ ) {
    		a[i][j] ^= b[i][j];
    		ans += a[i][j];
    		b[i][j] ^= a[i][j];
    		if (i + 1 < n) {
    			a[i + 1][j] ^= b[i][j];
    			if (j - 1 >= 0) {
    				b[i + 1][j - 1] ^= b[i][j]; 
    			}
    			else if (i + 2 < n) {
    				b[i + 2][j] ^= b[i][j];
    			}
    			if (j + 1 < n) {
    				b[i + 1][j + 1] ^= b[i][j];
    			}
    			else if (i + 2 < n) {
    				b[i + 2][j] ^= b[i][j];
    			}
    			if (i + 2 < n) {
    				b[i + 2][j] ^= b[i][j];
    			}
    		}
    		b[i][j] = 0;
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