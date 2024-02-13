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
// #include <bits/stdc++.h>
// priority_queue 优先队列
// std::cout.flush(); 交互题
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
    std::string s;
    std::cin >> s;
    std::map<char, int> mp;
    bool ok_1 = false, ok_2 = false;
    for (int i = 0; i < n; i++) {
    	if (s[i] == 'd' || s[i] == 'D') {
    		mp[s[i]] ++ ;
    	}
    	if (s[i] == 'f' && mp['d']) {
    		mp[s[i]] ++ ;
    	}
    	if (s[i] == 'F' && mp['D']) {
    		mp[s[i]] ++ ;
    	}
    	if (s[i] == 's' && mp['f']) {
    		ok_2 = true;
    	}
    	if (s[i] == 'S' && mp['F']) {
    		ok_1 = true;
    	}
    }

    std::cout << ok_1 << " " << ok_2 << "\n";
}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}