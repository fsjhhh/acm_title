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

const int N = 1e5 + 10;
bool st[N];
int n, k;

void bfs()
{
	std::queue<PII> q;
	q.push({n, 0});
	while (q.size())
	{
		PII t = q.front();
		q.pop();
		int d = t.first, ti = t.second;
		if (d == k)
		{
			std::cout << ti << "\n";
			return ;
		}
		if (st[d])
			continue;
		st[d] = true;
		for (int i = 1; i <= 3; i ++ )
		{
			if (i == 1)
			{
				if (d - 1 >= 0 && st[d - 1] == false)
				{
					q.push({d - 1, ti + 1});
				}
			}
			if (i == 2)
			{
				if (d + 1 <= 100000 && st[d + 1] == false)
				{
					q.push({d + 1, ti + 1});
				}
			}
			if (i == 3)
			{
				if (2 * d <= 100000 && st[2 * d] == false)
				{
					q.push({d * 2, ti + 1});
				}
			}
		}
	}
}

void solve()
{
    std::cin >> n >> k;
    bfs();
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

