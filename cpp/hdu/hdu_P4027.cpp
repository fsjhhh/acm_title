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

typedef long long LL;
typedef std::pair<int, int> PII;
typedef std::pair<LL, LL> PLL;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;

const int N = 1e5 + 10;
struct Node
{
	int l, r;
	LL sum;
	bool pd;
}tr[N * 4];
LL f[N];

int n;

void pushup(int u)
{
	tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
	tr[u].pd = tr[u << 1].pd && tr[u << 1 | 1].pd;
}

void build(int u, int l, int r)
{
	tr[u].l = l;
	tr[u].r = r;
	tr[u].pd = false;
	if (l == r)
	{
		tr[u].sum = f[l];
		if (tr[u].sum <= 1)
			tr[u].pd = true;
		return ;
	}
	int mid = (l + r) >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	pushup(u);
}

void modify(int nl, int nr, int u)
{
	int l = tr[u].l, r = tr[u].r;
	if (tr[u].pd == true)
		return ;
	if (l == r)
	{
		tr[u].sum = (LL)std::sqrt(tr[u].sum * 1.0);
		if (tr[u].sum <= 1) 
			tr[u].pd = true;
		return ;
	}
	int mid = (l + r) >> 1;
	if (nl <= mid) modify(nl, nr, u << 1);
	if (nr > mid) modify(nl, nr, u << 1 | 1);
	pushup(u);
}

LL query(int nl, int nr, int u)
{
	int l = tr[u].l, r = tr[u].r;
	if (nl <= l && nr >= r)
		return tr[u].sum;
	int mid = (l + r) >> 1;
	LL res = 0;
	if (nl <= mid) res += query(nl, nr, u << 1);
	if (nr > mid) res += query(nl, nr, u << 1 | 1);
	//printf("%lld\n", res);
	return res; 
}

void solve()
{
	int test = 1;
	while (scanf("%d", &n) != EOF)
	{
		//scanf("%d", &n);
		memset(f, 0, sizeof f);
		for (int i = 1; i <= n; i ++ )
			scanf("%lld", &f[i]);
		build(1, 1, n);
		int m;
		scanf("%d", &m);
		printf("Case #%d:\n",test++);
		while (m -- )
		{
			int k, a, b;
			scanf("%d%d%d", &k, &a, &b);
			if (a > b) std::swap(a, b);
			if (k == 0)
			{
				modify(a, b, 1);
			}
			else
			{
				LL res = 0;
				res = query(a, b, 1);
				printf("%lld\n", res);
			}
		}
		printf("\n");
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
