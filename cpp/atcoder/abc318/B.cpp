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
    int n;
    std::cin >> n;
    std::vector mp(110, std::vector<int>(110));
    std::vector sum(110, std::vector<int>(110));
    for (int i = 0; i < n; i ++ ) {
    	int A, B, C, D;
    	std::cin >> A >> B >> C >> D;
    	A ++ ;
    	B ++ ;
    	C ++ ;
    	D ++ ;
    	mp[A][C] ++ ;
    	mp[B][C] -- ;
    	mp[A][D] -- ;
    	mp[B][D] ++ ;
    }
    for (int i = 1; i < 110; i ++ ) {
    	for (int j = 1; j < 110; j ++ ) {
    		sum[i][j] = mp[i][j] + sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
    	}
    }
    int ans = 0;
    for (int i = 0; i < 110; i ++ ) {
    	for (int j = 0; j < 110; j ++ ) {
    		if (sum[i][j] > 0) {
    			ans ++ ;
    		}
    	}
    }
    std::cout << ans << "\n";
}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}