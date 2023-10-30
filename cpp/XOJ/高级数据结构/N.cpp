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

const int N = 10010;
int h[N], e[2 * N], ne[2 * N], w[2 * N], idx;
int seg[N], rev[N * 4], top[N], son[N], siz[N], fa[N], dep[N];
int n, a[N], v[N], pos[N];
struct node
{
	int l, r;
	int maxx, minn, tag;
} tr[N * 4];

void add(int a, int b, int c)
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

void dfs1(int u, int f)
{
	siz[u] = 1;
	dep[u] = dep[f] + 1;
	fa[u] = f;
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
		rev[seg[0]] = son[u];
		top[son[u]] = top[u];
		dfs2(son[u], f);
	}
	for (int i = h[u]; i != -1; i = ne[i])
	{
		int j = e[i];
		if (!top[j] && j != f)
		{
			seg[j] = ++ seg[0];
			rev[seg[0]] = j;
			top[j] = j;
			dfs2(j, u);
		}
	}
}

void dfs(int u, int f)
{
	for (int i = h[u]; i != -1; i = ne[i])
	{
		int j = e[i];
		if (j != f)
		{
			v[j] = a[w[i]];
			pos[w[i]] = j;
			dfs(j, u);
		}
	}
}

void push_up(int u)
{
	tr[u].maxx = std::max(tr[u << 1].maxx, tr[u << 1 | 1].maxx);
	tr[u].minn = std::min(tr[u << 1].minn, tr[u << 1 | 1].minn);
}

void build(int u, int l, int r)
{
	if (l == r)
	{
		tr[u].l = tr[u].r = l;
		tr[u].tag = 0;
		tr[u].maxx = tr[u].minn = v[rev[l]];
		return ;
	}
	tr[u].l = l, tr[u].r = r;
	tr[u].tag = 0;
	int mid = (l + r) >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	push_up(u);
}

void modify1(int u, int l, int x)
{
	if (tr[u].l == l && tr[u].r == l)
	{
		tr[u].maxx = x;
		tr[u].minn = x;
		return ;
	}
	int mid = (tr[u].l + tr[u].r) >> 1;
	if (l <= mid)
		modify1(u << 1, l, x);
	else
		modify1(u << 1 | 1, l, x);
	push_up(u);
}

void push_down(int u)
{
	if (tr[u].tag == 0)
		return ;
	if (tr[u << 1].tag)
		tr[u << 1].tag = 0;
	else
		tr[u << 1].tag = 1;
	if (tr[u << 1 | 1].tag)
		tr[u << 1 | 1].tag = 0;
	else
		tr[u << 1 | 1].tag = 1;
	tr[u << 1].maxx = tr[u << 1].minn * (-1);
	tr[u << 1 | 1].maxx = tr[u << 1 | 1].minn * (-1);
	tr[u << 1].minn = tr[u << 1].maxx * (-1);
	tr[u << 1 | 1].minn = tr[u << 1].maxx * (-1);
	tr[u].tag = 0;
}

void modify2(int u, int l, int r)
{
	if (l <= tr[u].l && r >= tr[u].r)
	{
		tr[u].maxx = tr[u].minn * (-1);
		tr[u].minn = tr[u].maxx * (-1);
		if (tr[u].tag)
			tr[u].tag = 0;
		else
			tr[u].tag = 1;
		return ;
	}
	push_down(u);
	int mid = tr[u].l + tr[u].r >> 1;
	if (l <= mid)
		modify2(u << 1, l, r);
	if (r > mid)
		modify2(u << 1 | 1, l, r);
}

LL query(int u, int l, int r)
{
	if (l <= tr[u].l && r >= tr[u].r)
	{
		return tr[u].maxx;
	}
	push_down(u);
	int mid = (tr[u].l + tr[u].r) >> 1;
	LL ans = -INFL;
	if (l <= mid)
	{
		ans = std::max(ans, query(u << 1, l, r));
	}
	if (r > mid)
	{
		ans = std::max(ans, query(u << 1 | 1, l, r));
	}
	return ans;
}

void query1(int u)
{
	if (tr[u].l == tr[u].r)
	{
		std::cout << tr[u].l << " " << tr[u].maxx << ' ' << tr[u].minn << "\n";
		return ;
	}
	push_down(u);
	query1(u << 1);
	query1(u << 1 | 1);
}

void solve()
{
	init();
    char c;
    std::cin >> n;
    for (int i = 1; i < n; i ++ )
    {
    	int x, y, z;
    	std::cin >> x >> y >> z;
    	a[i] = z;
    	add(x, y, i);
    	add(y, x, i);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    dfs(1, 0);
    build(1, 1, n);
    //query1(1);
    std::string s;
    while (1)
    {
    	std::cin >> s;
    	if (s == "DONE")
    		break;
    	if (s == "CHANGE")
    	{
    		int i, x;
    		std::cin >> i >> x;
    		//std::cout << e[2 * (i - 1)] << "\n";
    		//std::cout << seg[e[2 * (i - 1)]] << "\n";
    		modify1(1, seg[pos[i]], x);
    	}
    	if (s == "NEGATE")
    	{
    		int x, y;
    		std::cin >> x >> y;
    		while (top[x] != top[y])
    		{
    			if (dep[top[x]] < dep[top[y]])
    				std::swap(x, y);
    			modify2(1, seg[top[x]], seg[x]);
    			x = fa[top[x]];
    		}
    		if (x != y)
    		{
	    		if (dep[x] > dep[y])
	    			std::swap(x, y);
	    		modify2(1, seg[son[x]], seg[y]);
    		}
    	}
    	if (s == "QUERY")
    	{
    		//query1(1);
    		int x, y;
    		LL ans = -INFL;
    		std::cin >> x >> y;
    		while (top[x] != top[y])
    		{
    			if (dep[top[x]] < dep[top[y]])
    				std::swap(x, y);
    			ans = std::max(ans, query(1, seg[top[x]], seg[x]));
    			x = fa[top[x]];
    		}
    		if (x != y)
    		{
    			if (dep[x] > dep[y])
    				std::swap(x, y);
    			ans = std::max(ans, query(1, seg[son[x]], seg[y]));
    		}
    		std::cout << ans << "\n";
    	}
    }
}

int main()
{
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}

