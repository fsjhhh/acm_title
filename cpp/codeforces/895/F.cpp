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
    LL n;
    std::cin >> n;
    std::vector<int> a(n), d(n);
    std::vector<int> c(n);
    for (int i = 0; i < n; i ++ ) {
    	std::cin >> a[i];
    	a[i] -- ;
    	d[a[i]] ++ ;
    }
    for (int i = 0; i < n; i ++ ) {
    	std::cin >> c[i];
    }

    std::vector<int> st(n);
    std::queue<LL> q;
    for (int i = 0; i < n; i ++ ) {
    	if (!d[i]) {
            q.push(i);
        }
    }

    if (!q.size()) {
        for (int i = 0; i < n; i ++ ) {
            q.push(i);
        }
    }

	std::queue<int> qq;
    while (q.size()) {
    	auto t = q.front();
    	q.pop();
    	while (st[t] != 2) {
    		st[t] ++ ;
    		t = a[t];
    	}
    }

    for (int i = 0; i < n; i ++ ) {
    	if (!d[i]) {
            q.push(i);
        }
    }

    if (!q.size()) {
        for (int i = 0; i < n; i ++ ) {
            
        }
    }

    std::vector<int> ans;
    
    while (q.size()) {
    	auto t = q.front();
    	q.pop();
    	
    	while (st[t] < 2) {
    		ans.push_back(t + 1);
    		t = a[t];
    	}
    	if (st[t] == 2) {
    		qq.push(t);
    		while (st[t] != 3) {
    			st[t] ++ ;
    			t = a[t];
    		}
    	}
    }

    while (qq.size()) {
    	auto t = qq.front();
    	qq.pop();
    	int minn = INF, z = -1;
    	while (st[t] != 4) {
    		st[t] ++ ;
    		if (minn > c[t]) {
    			z = t;
    		}
    		t = a[t];
    	}

    	t = a[z];
    	while (t != z) {
    		st[t] ++ ;
    		ans.push_back(t + 1);
    		t = a[t];
    	}
    	ans.push_back(z + 1);
    }

    for (auto it : ans) {
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