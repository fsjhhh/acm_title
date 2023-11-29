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
int fa[N], dep[N], siz[N], son[N], top[N], seg[N], rev[N * 2];
int h[N], e[N], ne[N], idx;
int a[N], n, m, Root, mod;
struct Node
{
	int l, r;
	int sum, tag;
} tr[N * 2];

void add(int x, int y)
{
	e[idx] = y, ne[idx] = h[x], h[x] = idx ++ ;
}

void init()
{
	seg[Root] = ++ seg[0];
	rev[seg[0]] = Root;
	top[Root] = Root;
}

void dfs1(int u, int f)
{
	siz[u] = 1;
	fa[u] = f;
	dep[u] = dep[f] + 1;
	for (int i = h[u]; i != -1; i = ne[i])
	{
		int j = e[i];
		if (j != f)
		{
			dfs1(j, u);
			siz[u] += siz[j];
			if (siz[son[u]] < siz[j])
				son[u] = j;
		}
	}
}

void dfs2(int u, int f)
{
	if (son[u])
	{
		seg[son[u]] = ++ seg[0];
		top[son[u]] = top[u];
		rev[seg[0]] = son[u];
		dfs2(son[u], u);
	}
	for (int i = h[u]; i != -1; i = ne[i])
	{
		int j = e[i];
		if (!top[j])
		{
			seg[j] = ++ seg[0];
			top[j] = j;
			rev[seg[0]] = j;
			dfs2(j, u);
		}
	}
}

void push_up(int u)
{
	tr[u].sum = (tr[u << 1].sum + tr[u << 1 | 1].sum) % mod;
}

void build(int u, int l, int r)
{
	if (l == r)
	{
		tr[u].l = l;
		tr[u].r = r;
		tr[u].sum = a[rev[l]];
		tr[u].tag = 0;
		return ;
	}
	tr[u].l = l, tr[u].r = r;
	tr[u].sum = 0, tr[u].tag = 0;
	int mid = (l + r) >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	push_up(u);
}

void push_down(int u)
{
	if (tr[u].tag == 0)
		return ;
	tr[u << 1].sum = (tr[u << 1].sum + tr[u].tag * (tr[u << 1].r - tr[u << 1].l + 1)) % mod;
	tr[u << 1 | 1].sum = (tr[u << 1 | 1].sum + tr[u].tag * (tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1)) % mod;
	tr[u << 1].tag = (tr[u << 1].tag + tr[u].tag) % mod;
	tr[u << 1 | 1].tag = (tr[u << 1 | 1].tag + tr[u].tag) % mod;
	tr[u].tag = 0;
}

void modify(int u, int l, int r, int x)
{
	if (tr[u].l >= l && tr[u].r <= r)
	{
		tr[u].sum = (tr[u].sum + (tr[u].r - tr[u].l + 1) * x) % mod;
		tr[u].tag = (tr[u].tag + x) % mod;
		return ;
	}
	push_down(u);
	int mid = (tr[u].l + tr[u].r) >> 1;
	if (l <= mid)
		modify(u << 1, l, r, x);
	if (r > mid)
		modify(u << 1 | 1, l, r, x);
	push_up(u);
}

int query(int u, int l, int r)
{
	if (l <= tr[u].l && r >= tr[u].r)
		return tr[u].sum;
	push_down(u);
	int mid = (tr[u].l + tr[u].r) >> 1;
	int sum = 0;
	if (l <= mid)
		sum = (sum + query(u << 1, l, r)) % mod;
	if (r > mid)
		sum = (sum + query(u << 1 | 1, l, r)) % mod;
	return sum;
}

void query1(int u)
{
	if (tr[u].l == tr[u].r)
	{
		std::cout << tr[u].l << " " << rev[tr[u].l] <<  " " << tr[u].sum << "\n";
		return ;
	}
	push_down(u);
	query1(u << 1);
	query1(u << 1 | 1);
}

void solve()
{
	memset(h, -1, sizeof h);
	std::cin >> n >> m >> Root >> mod;
	for (int i = 1; i <= n; i ++ )
		std::cin >> a[i];
	for (int i = 1; i < n; i ++ )
	{
		int l, r;
		std::cin >> l >> r;
		add(l, r), add(r, l);
	}
	init();
	dfs1(Root, 0); 
	dfs2(Root, 0); 
	build(1, 1, n);

	while (m -- )
	{
		int op;
		std::cin >> op;
		if (op == 1)
		{
			int x, y, z;
			std::cin >> x >> y >> z;
			while (top[x] != top[y])
			{
				if (dep[top[x]] < dep[top[y]])
					std::swap(x, y);
				modify(1, seg[top[x]], seg[x], z % mod);
				x = fa[top[x]];
			}
			if (dep[x] > dep[y])
				std::swap(x, y);
			modify(1, seg[x], seg[y], z % mod);
		}
		if (op == 2)
		{
			int x, y, ans = 0;
			std::cin >> x >> y;
			while (top[x] != top[y])
			{
				if (dep[top[x]] < dep[top[y]])
					std::swap(x, y);
				ans = (ans + query(1, seg[top[x]], seg[x])) % mod;
				x = fa[top[x]];
			}
			if (dep[x] > dep[y])
				std::swap(x, y);
			ans = (ans + query(1, seg[x], seg[y])) % mod;
			std::cout << ans << "\n";
		}
		if (op == 3)
		{
			int x, z;
			std::cin >> x >> z;
			modify(1, seg[x], seg[x] + siz[x] - 1, z % mod);
			// query1(1);
		}
		if (op == 4)
		{
			int x;
			std::cin >> x;
			int ans = query(1, seg[x], seg[x] + siz[x] - 1) % mod;
			std::cout << ans << "\n";
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

