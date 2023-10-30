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

const int N = 2e5 + 10;

int n, m;
std::string s;

struct Node {
	int l, r;
	int sum;
	int tag;
}tr[N * 4];

int w[N];

void push_up(int u) {
	tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void build(int u, int l, int r) {
	if (l == r) {
		tr[u].l = l, tr[u].r = r;
		tr[u].sum = w[l];
		tr[u].tag = 0;
		return ;
	}
	tr[u].l = l, tr[u].r = r;
	tr[u].tag = 0;
	int mid = (l + r) >> 1;
	build (u << 1, l, mid);
	build (u << 1 | 1, mid + 1, r);
	push_up(u);
}

void push_down(int u) {
	if (!tr[u].tag) {
		return ;
	}
	tr[u << 1].sum = (tr[u << 1].r - tr[u << 1].l + 1) - tr[u << 1].sum;
	tr[u << 1 | 1].sum = (tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1) - tr[u << 1 | 1].sum;
	tr[u << 1].tag = (tr[u << 1].tag ? 0 : 1);
	tr[u << 1 | 1].tag = (tr[u << 1 | 1].tag ? 0 : 1);
	tr[u].tag = 0;
}

void modify(int u, int l, int r) {
	if (tr[u].l >= l && tr[u].r <= r) {
		tr[u].sum = (tr[u].r - tr[u].l + 1) - tr[u].sum;
		tr[u].tag = (tr[u].tag ? 0 : 1);
		return ;
	}
	push_down(u);
	int mid = (tr[u].l + tr[u].r) >> 1;
	if (l <= mid) {
		modify(u << 1, l, r);
	}
	if (r > mid) {
		modify(u << 1 | 1, l, r);
	}
	push_up(u);
}

int query(int u, int l, int r) {
	if (tr[u].l >= l && tr[u].r <= r) {
		return tr[u].sum;
	}
	push_down(u);
	int sum = 0;
	int mid = (tr[u].l + tr[u].r) >> 1;
	if (l <= mid) {
		sum += query(u << 1, l, r);
	}
	if (r > mid) {
		sum += query(u << 1 | 1, l, r);
	}
	return sum;
}

void solve()
{
    std::cin >> n >> m;
    std::cin >> s;
    for (int i = 1; i <= n; i ++ ) {
    	w[i] = s[i - 1] - '0';
    }

    build(1, 1, n);
    while (m -- ) {
    	int op, l, r;
    	std::cin >> op >> l >> r;
    	if (op == 0) {
    		modify(1, l, r);
    	}
    	else {
    		std::cout << query(1, l, r) << "\n";
    	}
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