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

const int N = 1e5 + 10;

int a[N];
std::string s;

struct Node {
	int l, r;
	int lazy, sum, num;
} tr[N * 4];

void push_up(int u) {
	tr[u].lazy = 0;
	tr[u].sum = (tr[u << 1].sum ^ tr[u << 1 | 1].sum);
	tr[u].num = (tr[u << 1].num ^ tr[u << 1 | 1].num); 
}

void build(int u, int l, int r) {
	if (l == r) {
		tr[u].l = tr[u].r = l;
		tr[u].lazy = 0;
		tr[u].num = a[l];
		if (s[l] == '1') {
			tr[u].sum = a[l];
		}
		else {
			tr[u].sum = 0;
		}
		return ;
	}
	tr[u].l = l;
	tr[u].r = r;
	int mid = (l + r) >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	push_up(u);
}

void push_down(int u) {
	if (tr[u].lazy == 0) {
		return ;
	}
	tr[u << 1].sum = (tr[u << 1].num ^ tr[u << 1].sum);
	tr[u << 1 | 1].sum = (tr[u << 1 | 1].num ^ tr[u << 1 | 1].sum);
	tr[u << 1].lazy ^= 1;
	tr[u << 1 | 1].lazy ^= 1;
	tr[u].lazy = 0;
}

void modify(int u, int l, int r) {
	if (tr[u].l >= l && tr[u].r <= r) {
		tr[u].lazy ^= 1;
		tr[u].sum = (tr[u].num ^ tr[u].sum);
		return ;
	}
	push_down(u);
	int mid = (tr[u].l + tr[u].r) >> 1;
	if (mid >= l) {
		modify(u << 1, l, r);
	}
	if (mid < r) {
		modify(u << 1 | 1, l, r);
	}
	push_up(u);
}

void solve() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i ++ ) {
    	std::cin >> a[i];
    }
    std::cin >> s;
    s = " " + s;
    build(1, 1, n);
    int q;
    std::cin >> q;
    while (q -- ) {
    	int op;
    	std::cin >> op;
    	if (op == 1) {
    		int l, r;
    		std::cin >> l >> r;
    		modify(1, l, r);
    	}
    	else {
    		int g;
    		std::cin >> g;
    		if (g) {
    			std::cout << tr[1].sum << " ";
    		}
    		else {
    			std::cout << (tr[1].num ^ tr[1].sum) << " ";
    		}
    	}
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