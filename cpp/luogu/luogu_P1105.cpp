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

struct Node {
	int h, l, r, id;
};

void solve()
{
    int n;
    std::cin >> n;
    std::vector<Node> v(n);
    for (int i = 0; i < n; i ++ ) {
    	int h, l, r;
    	std::cin >> h >> l >> r;
    	v[i] = {h, l, r, i + 1};
    }
    std::sort(v.begin(), v.end(), [&](Node a, Node b) -> bool {
    	if (a.h == b.h) {
    		return a.id > b.id;
    	}
    	return a.h < b.h;
    });
    // for (int i = 0; i < n; i ++ ) {
    // 	std::cout << v[i].h << " " << v[i].l << " " << v[i].r << " " << v[i].id << "\n"; 
    // }
    std::vector<PII> ans(n);
    for (int i = 0; i < n; i ++ ) {
    	int x = 0, y = 0;
    	for (int j = i - 1; j >= 0; j -- ) {
    		if (v[i].l > v[j].l && v[i].l < v[j].r && v[i].h > v[j].h) {
    			x = v[j].id;
    			break;
    		}
    	}
    	for (int j = i - 1; j >= 0; j -- ) {
    		if (v[i].r > v[j].l && v[i].r < v[j].r && v[i].h > v[j].h) {
    			y = v[j].id;
    			break;
    		}
    	}
    	ans[v[i].id - 1] = {x, y};
    }
    for (auto [x, y] : ans) {
    	std::cout << x << " " << y << "\n";
    }
}

int main()
{
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}