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
#define IOS std::ios::sync_with_stdio(false); \
            std::cin.tie(0);              \
            std::cout.tie(0);
using namespace std;

typedef long long LL;
typedef std::pair<int, int> PII;
typedef std::pair<LL, LL> PLL;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;

const int N = 1e5 + 10;
LL a[N];
LL tr[N * 4], tag[N * 4]; // 树和懒标记
LL n, m;

void pushup(LL u)
{
	tr[u] = tr[u << 1] + tr[u << 1 | 1];
}

void build(LL u, LL l, LL r)
{
	tag[u] = 0;
	if (l == r)
	{
		tr[u] = a[l];
		return ;
	}
	LL mid = (l + r) >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	pushup(u);
}

void addtag(LL u, LL l, LL r, LL x)
{
	tag[u] += x;
	tr[u] += x * (r - l + 1); 
}

void pushdown(LL u, LL l, LL r)
{
	if (tag[u])
	{
		LL mid = (l + r) >> 1;
		addtag(u << 1, l, mid, tag[u]);
		addtag(u << 1 | 1, mid + 1, r, tag[u]);
		tag[u] = 0;
	}
}

void modify(LL nl, LL nr, LL u, LL l, LL r, LL x)
{
	if (nl <= l && nr >= r)
	{
		addtag(u, l, r, x);
		return ;
	}
	pushdown(u, l, r);
	LL mid = (l + r) >> 1;
	if (nl <= mid) modify(nl, nr, u << 1, l, mid, x);
	if (nr > mid) modify(nl, nr, u << 1 | 1, mid + 1, r, x);
	pushup(u);
}

LL query(LL nl, LL nr, LL u, LL l, LL r)
{
	if (nl <= l && nr >= r)
		return tr[u];
	pushdown(u, l, r);
	LL res = 0;
	LL mid = (l + r) >> 1;
	if (nl <= mid) res += query(nl, nr, u << 1, l, mid);
	if (nr > mid) res += query(nl, nr, u << 1 | 1, mid + 1, r);
	return res;
}

void solve()
{
	std::cin >> n >> m;
	for (int i = 1; i <= n; i ++ )
		std::cin >> a[i];
	build(1, 1, n);
	while (m -- )
	{
		int q;
		std::cin >> q;
		if (q == 1)
		{
			int x, y, k;
			std::cin >> x >> y >> k;
			modify(x, y, 1, 1, n, k);
		}
		if (q == 2)
		{
			int x, y;
			std::cin >> x >> y;
			std::cout << query(x, y, 1, 1, n) << std::endl;
		}
	}
}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
