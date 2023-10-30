#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
// #include <unordered_map>
#include <set>
// #include <unordered_set>
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
LL h[N], e[2 * N], ne[2 * N], w[2 * N], idx;
LL seg[N], rev[N * 4], top[N], son[N], siz[N], fa[N], dep[N];
LL n, a[N], v[N], pos[N];
struct node
{
	LL l, r;
	LL sum, tag;
} tr[N * 4];

void add(LL a, LL b, LL c)
{
	e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++ ;
}

void init()
{
	memset(h, -1, sizeof h);
	memset(seg, 0, sizeof seg);
	memset(rev, 0, sizeof rev);
	memset(top, 0, sizeof top);
	memset(son, 0, sizeof son);
	memset(siz, 0, sizeof siz);
	memset(fa, 0, sizeof fa);
	memset(dep, 0, sizeof dep);
	idx = 0;
	seg[1] = ++ seg[0];
	rev[seg[0]] = 1;
	top[1] = 1;
}

void dfs1(LL u, LL f)
{
	siz[u] = 1;
	dep[u] = dep[f] + 1;
	fa[u] = f;
	for (LL i = h[u]; i != -1; i = ne[i])
	{
		LL j = e[i];
		if (j != f)
		{
			dfs1(j, u);
			siz[u] += siz[j];
			if (siz[son[u]] < siz[j])
				son[u] = j;
		}
	}
}

void dfs2(LL u, LL f)
{
	if (son[u])
	{
		seg[son[u]] = ++ seg[0];
		rev[seg[0]] = son[u];
		top[son[u]] = top[u];
		dfs2(son[u], u);
	}
	for (LL i = h[u]; i != -1; i = ne[i])
	{
		LL j = e[i];
		if (!top[j] && j != f)
		{
			seg[j] = ++ seg[0];
			rev[seg[0]] = j;
			top[j] = j;
			dfs2(j, u);
		}
	}
}

void dfs(LL u, LL f)
{
	for (LL i = h[u]; i != -1; i = ne[i])
	{
		LL j = e[i];
		if (j != f)
		{
			v[j] = a[w[i]];
			pos[w[i]] = j;
			dfs(j, u);
		}
	}
}

void push_up(LL u)
{
	tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void build(LL u, LL l, LL r)
{
	if (l == r)
	{
		tr[u].l = tr[u].r = l;
		tr[u].tag = 0;
		tr[u].sum = v[rev[l]];
		return ;
	}
	tr[u].l = l, tr[u].r = r;
	tr[u].tag = 0;
	LL mid = (l + r) >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	push_up(u);
}

void modify1(LL u, LL l, LL x)
{
	if (tr[u].l == l && tr[u].r == l)
	{
		tr[u].sum = x;
		return ;
	}
	LL mid = (tr[u].l + tr[u].r) >> 1;
	if (l <= mid)
		modify1(u << 1, l, x);
	else
		modify1(u << 1 | 1, l, x);
	push_up(u);
}

LL query(LL u, LL l, LL r)
{
	if (l <= tr[u].l && r >= tr[u].r)
	{
		return tr[u].sum;
	}
	LL mid = (tr[u].l + tr[u].r) >> 1;
	LL ans = 0;
	if (l <= mid)
	{
		ans += query(u << 1, l, r);
	}
	if (r > mid)
	{
		ans += query(u << 1 | 1, l, r);
	}
	return ans;
}

void query1(LL u)
{
	if (tr[u].l == tr[u].r)
	{
		std::cout << tr[u].l << " " << tr[u].sum << "\n";
		return ;
	}
	query1(u << 1);
	query1(u << 1 | 1);
}

void solve()
{
	init();   
    std::cin >> n;
    for (LL i = 1; i < n; i ++ )
    {
    	LL x, y, z;
    	std::cin >> x >> y >> z;
    	a[i] = z;
    	add(x, y, i);
    	add(y, x, i);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    dfs(1, 0);
    build(1, 1, n);
    LL m;
    std::cin >> m;
    while (m -- )
    {
    	LL op, x, y;
    	std::cin >> op >> x >> y;
    	if (op == 1)
    	{
    		modify1(1, seg[pos[x]], y);
    	}
    	else
    	{
    		LL ans = 0;
    		// query1(1);
    		while (top[x] != top[y])
    		{
    			if (dep[top[x]] < dep[top[y]])
    				std::swap(x, y);
    			ans += query(1, seg[top[x]], seg[x]);
    			x = fa[top[x]];
    		}
    		if (x != y)
    		{
    			if (dep[x] > dep[y])
    				std::swap(x, y);
    			ans += query(1, seg[son[x]], seg[y]);
    		}
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

