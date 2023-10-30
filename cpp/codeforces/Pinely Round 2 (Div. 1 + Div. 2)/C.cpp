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
    int n, k;
    std::cin >> n >> k;
    std::vector<int> v(n), st(n + 1);
    for (int i = 0; i < n; i ++ ) {
    	std::cin >> v[i];
    	st[v[i]] = 1;
    }
    int mex = 0;
    for (int i = 0; i <= n; i ++ ) {
    	if (!st[i]) {
    		mex = i;
    		break;
    	}
    }
    int t = k % (n + 1);
    std::deque<int> q;
    for (int i = 0; i < n; i ++ ) {
    	q.push_back(v[i]);
    }
    for (int i = 0; i < t; i ++ ) {
    	q.push_front(mex);
    	mex = q.back();
    	q.pop_back();
    }
    for (auto it : q) {
    	std::cout << it << " ";
    }
    std::cout << "\n";
}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}