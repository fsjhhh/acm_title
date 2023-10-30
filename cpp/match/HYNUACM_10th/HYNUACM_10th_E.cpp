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
#define IOS ios::sync_with_stdio(false); \
            cin.tie(0);              \
            cout.tie(0);
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;

const int N = 1e6 + 10;
int ans[N], f[N * 4];
struct Node
{
	int l, r, id;
}p[N], s[N];

bool cmp(Node a1, Node b1)
{
	if (a1.l == b1.l) return a1.r < b1.r;
	return a1.l < b1.l;
}

void pushup(int u)
{
	f[u] = min(f[u << 1], f[u << 1 | 1]);
}

void build(int u, int l, int r)
{
	if (l == r)
	{
		f[u] = INF;
		return ;
	} 
	int mid = l + r >> 1;
	build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
	pushup(u);
}

int query(int nl, int nr, int l, int r, int u)
{
	int res = INF;
	if (nl <= l && nr >= r)
		return f[u];
	int mid = (l + r) >> 1;
	if (nl <= mid) res = min(res, query(nl, nr, l, mid, u << 1));
	if (nr > mid) res = min(res, query(nl, nr, mid + 1, r, u << 1 | 1));
	return res;
}

void modify(int nl, int nr, int l, int r, int u, int x)
{
	if (nl <= l && nr >= r)
	{
		f[u] = min(f[u], x);
		return ;
	}
	int mid = (l + r) >> 1;
	if (nl <= mid) modify(nl, nr, l, mid, u << 1, x);
	if (nr > mid) modify(nl, nr, mid + 1, r, u << 1 | 1, x);
	pushup(u);
}

void solve()
{
	int n, q, L;
	cin >> n >> q >> L;
	build(1, 1, L);
	for (int i = 1; i <= n; i ++ )
	{
		cin >> p[i].l >> p[i].r;
		p[i].id = i;
	}
	for (int i = 1; i <= q; i ++ )
	{
		cin >> s[i].l >> s[i].r;
		s[i].id = i;
	}

	sort(p + 1, p + n + 1, cmp);
	sort(s + 1, s + q + 1, cmp);

	//for (int i = 1; i <= n; i ++ ) cout << p[i].l << " " << p[i].r << " " << p[i].id << endl;

	int pos = 1;
	for (int i = 1; i <= q; i ++ )
	{
		while (pos <= n && p[pos].l <= s[i].l)
		{
			modify(p[pos].r, p[pos].r, 1, L, 1, p[pos].id);
			pos ++ ;
		}
		int res = query(s[i].r, L, 1, L, 1);
		if (res == INF) ans[s[i].id] = 0;
		else ans[s[i].id] = res;
	}

	for (int i = 1; i <= q; i ++ )
		cout << ans[i] << endl;
}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
