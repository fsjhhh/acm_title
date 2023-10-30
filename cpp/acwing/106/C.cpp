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
typedef std::pair<int, std::pair<int, int>> PIII;
typedef std::pair<LL, LL> PLL;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;

const int N = 2e5 + 10;
int n;
char s[N];
int a[N];
int l[N], r[N];
bool st[N];
std::vector<PII> ans;

void solve()
{
	std::cin >> n >> s + 1;
	for (int i = 1; i <= n; i ++ )
		std::cin >> a[i];

	for (int i = 1; i <= n; i ++ )
	{
		l[i] = i - 1;
		r[i] = i + 1;
	}

	std::priority_queue<PIII, std::vector<PIII>, std::greater<PIII>> q;
	for (int i = 1; i < n; i ++ )
	{
		if (s[i] != s[i + 1])
		{
			int t = abs(a[i] - a[i + 1]);
			q.push({t, {i, i + 1}});
		}
	}

	while (q.size() && r[0] != n + 1)
	{
		auto t = q.top();
		q.pop();
		int x = t.second.first, y = t.second.second;
		if (st[x] || st[y])
			continue;

		st[x] = st[y] = true;
		ans.push_back({x, y});

		if (r[y] <= n && l[x] >= 1 && s[l[x]] != s[r[y]])
		{
			int res = abs(a[l[x]] - a[r[y]]);
			q.push({res, {l[x], r[y]}});
		}

		r[l[x]] = r[y];
		l[r[y]] = l[x];
	}

	std::cout << ans.size() << "\n";
	for (auto [x, y] : ans)
		std::cout << x << " " << y << "\n";
}

int main()
{
    IOS;
    int t = 1;
    while (t -- )
        solve();
    return 0;
}
