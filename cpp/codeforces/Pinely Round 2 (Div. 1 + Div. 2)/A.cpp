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
#include <iomanip> // std::fixed std::setprecision(x) 保留x位小数
#include <array>
#include <bitset>
#include <functional>
#include <ranges>
//#include <bits/stdc++.h>
//priority_queue 优先队列
#define IOS                           \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(0);                  \
    std::cout.tie(0);

typedef long long LL;
typedef __int128 i128;
typedef std::pair<int, int> PII;
typedef std::pair<LL, LL> PLL;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, a, q;
    std::cin >> n >> a >> q;
    std::string s;
    std::cin >> s;
    if (a >= n) {
    	std::cout << "YES" << "\n";
    	return ;
    }
    int cnt = 0;
    int b = n - a;
    for (int i = 0; i < q; i ++ ) {
    	if (s[i] == '-') {
    		cnt ++ ;
    	}
    	else {
    		a ++ ;
    		if (a >= cnt + n) {
    			std::cout << "YES" << "\n";
    			return ;
    		}
    	}
    }
    if (a >= n) {
    	std::cout << "MAYBE" << "\n";
    	return ;
    }
   	std::cout << "NO" << "\n";

}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}