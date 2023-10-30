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

const int N = 1e6 + 10;

struct Node {
	int l, r;
	int lazy;
	int num_0, num_1;
	int num_l, num_r;
} tr[N * 4];
std::string s;

void push_up(int u) {
	if (tr[u << 1].num_r == tr[u << 1 | 1].num_l) {
		if (tr[u << 1].num_r == 0) {
			tr[u].num_0 = tr[u << 1].num_0 + tr[u << 1 | 1].num_0 + 1;
			tr[u].num_1 = tr[u << 1].num_1 + tr[u << 1 | 1].num_1;
		}
		else {
			tr[u].num_1 = tr[u << 1].num_1 + tr[u << 1 | 1].num_1 + 1;
			tr[u].num_0 = tr[u << 1].num_0 + tr[u << 1 | 1].num_0;			
		}
	}
	else {
		tr[u].num_1 = tr[u << 1].num_1 + tr[u << 1 | 1].num_1;
		tr[u].num_0 = tr[u << 1].num_0 + tr[u << 1 | 1].num_0;
	}
	tr[u].num_l = tr[u << 1].num_l;
	tr[u].num_r = tr[u << 1 | 1].num_r;
	tr[u].lazy = 0;
}

void build(int u, int l, int r) {
	if (l == r) {
		tr[u].lazy = 0;
		tr[u].l = l;
		tr[u].r = r;
		tr[u].num_0 = 0;
		tr[u].num_1 = 0;
		tr[u].num_l = (s[l] - '0');
		tr[u].num_r = (s[r] - '0');
		return ;
	}
	tr[u].lazy = 0;
	tr[u].l = l, tr[u].r = r;
	int mid = (l + r) >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	push_up(u);
}

void push_down(int u) {
	if (!tr[u].lazy) {
		return ;
	}
	tr[u << 1].lazy ^= 1;
	tr[u << 1 | 1].lazy ^= 1;
	std::swap(tr[u << 1].num_0, tr[u << 1].num_1);
	tr[u << 1].num_l ^= 1;
	tr[u << 1].num_r ^= 1;
	tr[u << 1 | 1].num_l ^= 1;
	tr[u << 1 | 1].num_r ^= 1;
	std::swap(tr[u << 1 | 1].num_0, tr[u << 1 | 1].num_1);
	tr[u].lazy = 0;
}

void modify(int u, int l, int r) {
	if (tr[u].l >= l && tr[u].r <= r) {
		tr[u].lazy ^= 1;
		tr[u].num_l ^= 1;
		tr[u].num_r ^= 1;
		std::swap(tr[u].num_0, tr[u].num_1);
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

Node query_1(int u, int l, int r) {
	if (tr[u].l >= l && tr[u].r <= r) {
		return tr[u];
	}
	push_down(u);
	int mid = (tr[u].l + tr[u].r) >> 1;
	Node res, q_1, q_2;
	q_1.num_l = q_2.num_l = -1;
	if (mid >= l) {
		auto t = query_1(u << 1, l, r);
		q_1.num_0 = t.num_0;
		q_1.num_1 = t.num_1;
		q_1.num_l = t.num_l;
		q_1.num_r = t.num_r;
	}
	if (mid < r) {
		auto t = query_1(u << 1 | 1, l, r);
		q_2.num_0 = t.num_0;
		q_2.num_1 = t.num_1;
		q_2.num_l = t.num_l;
		q_2.num_r = t.num_r;		
	}
	if (q_1.num_l == -1) {
		return q_2;
	}
	if (q_2.num_l == -1) {
		return q_1;
	}
	if (q_1.num_r == q_2.num_l) {
		if (q_1.num_r == 0) {
			res.num_0 = q_1.num_0 + q_2.num_0 + 1;
			res.num_1 = q_1.num_1 + q_2.num_1;
		}
		else {
			res.num_0 = q_1.num_0 + q_2.num_0;
			res.num_1 = q_1.num_1 + q_2.num_1 + 1;
		}
	}
	else {
			res.num_0 = q_1.num_0 + q_2.num_0;
			res.num_1 = q_1.num_1 + q_2.num_1;
	}
	res.num_l = q_1.num_l;
	res.num_r = q_2.num_r;
	push_up(u);
	return res;
}

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::cin >> s;
    s = " " + s;
    build(1, 1, n);
    while (m -- ) {
    	char op;
    	int l, r;
    	std::cin >> op >> l >> r;
    	if (op == 'M') {
    		modify(1, l, r);
    	}
    	else {
    		auto t = query_1(1, l, r);
    		std::cout << std::max(t.num_0, t.num_1) + 1 << "\n";
    	}
    }
}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}