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

const int N = 2e6 + 10;
struct Node
{
	int l, r;
	int ans;
} tr[N];
PII a[N];
int b[N], idx;
int hs[N * 10];
bool st[N];
int sum;

void build(int u, int l, int r)
{
	if (l == r)
	{
		tr[u].l = l, tr[u].r = r;
		tr[u].ans = 0;
		return ;
	}
	tr[u].l = l, tr[u].r = r;
	int mid = (l + r) >> 1;
	tr[u].ans = 0;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
}

void push_down(int u)
{
	if (tr[u].ans == 0)
		return ;
	tr[u << 1].ans = tr[u].ans;
	tr[u << 1 | 1].ans = tr[u].ans;
	tr[u].ans = 0;
}

void modify(int u, int l, int r, int x)
{
	if (l <= tr[u].l && r >= tr[u].r)
	{
		tr[u].ans = x;
		return ;
	}
	push_down(u);
	int mid = tr[u].l + tr[u].r >> 1;
	if (l <= mid)
		modify(u << 1, l, r, x);
	if (r > mid)
		modify(u << 1 | 1, l, r, x);
}

void query(int u)
{
	if (tr[u].ans && !st[tr[u].ans])
	{
		sum ++ ;
		st[tr[u].ans] = true;
		return ;
	}
	if (tr[u].l == tr[u].r)
		return ;
	push_down(u);
	query(u << 1);
	query(u << 1 | 1);
}

void init()
{
	memset(st, 0, sizeof st);
	idx = 0;
	sum = 0;
}

void solve()
{
	int n;
	init();
	std::cin >> n;
	for (int i = 0; i < n; i ++ )
	{
		std::cin >> a[i].first >> a[i].second;
		b[idx ++ ] = a[i].first;
		b[idx ++ ] = a[i].second;
	}
	std::sort(b, b + idx);
	idx = std::unique(b, b + idx) - b;
	for (int i = 0; i < idx; i ++ )
		hs[b[i]] = i + 1;
	build(1, 1, idx);
	for (int i = 0; i < n; i ++ )
	{
		int l = hs[a[i].first];
		int r = hs[a[i].second];
		modify(1, l, r, i + 1);
	}
	query(1);
	std::cout << sum << "\n";
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