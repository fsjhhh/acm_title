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
int n, c[N], l[N], r[N], f[N], tr[N], count;

int lowbit(int u)
{
	return u & (-u);
}

void modify(int u, int w)
{
	for (int i = u; i < n; i += lowbit(i))
		tr[i] = std::max(tr[i], w);
}

int query(int u)
{
	int mx = 0;
	for (int i = u; i > 0; i -= lowbit(i))
		mx = std::max(mx, tr[i]);
	return mx;
}

void solve()
{
	std::cin >> n;
	for (int i = 1; i <= n; i ++ )
	{
		std::cin >> c[i];
		if (!l[c[i]])
		{
			l[c[i]] = i;
			count ++ ;
		}
		r[c[i]] = i;
	}

	int ans = 0;
	for (int i = 1; i <= n; i ++ )
	{
		if (i == l[c[i]])
			f[c[i]] = query(c[i] - 1) + 1;
		if (i == r[c[i]])
			modify(c[i], f[c[i]]);
		ans = std::max(ans, f[c[i]]);
	}
	std::cout << count - ans << "\n";
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

