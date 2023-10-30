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

const int N = 100010;
int pri[N], idx;
bool primes[N];
std::string start, end;
bool st[N];

void init()
{
	int n = 10000;
	for(int i = 2; i < n; i ++ )
	{
		if(!primes[i]) pri[idx ++ ] = i;
		for(int j = 0; pri[j] <= n / i; j ++ )
		{
			primes[pri[j] * i] = true;
			if(i % pri[j] == 0)
				break;
		}
		// bool pd = true;
		// for (int j = 2; j * j <= i; j ++ )
		// {
		// 	if (i % j == 0)
		// 		pd = false;
		// }
		// if (pd)
		// 	primes[i] = true;
	}
}

int s_n(std::string s)
{
	int ans = 0;
	for (int i = 0; i < s.size(); i ++ )
	{
		ans = ans * 10 + (s[i] - '0');
	}
	return ans;
}

bool check(int n)
{
	for (int i = 2; i * i <= n; i ++ )
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

void bfs()
{
	std::queue<std::pair<std::string, int> > q;
	q.push({start, 0});
	while (q.size())
	{
		std::pair<std::string, int> t = q.front();
		q.pop();
		int tt = s_n(t.first), dist = t.second;
		if (t.first == end)
		{
			std::cout << dist << "\n";
			return ;
		}
		if (st[tt])
			continue;
		st[tt] = true;
		for (int i = 0; i < 4; i ++ )
		{
			std::string s = t.first;
			for (int j = 0; j <= 9; j ++ )
			{
				if (i == 0 && j == 0)
					continue;
				char c = s[i];
				s[i] = j + '0';
				if (s == t.first)
				{
					s[i] = c;
					continue;
				}
				int num = s_n(s);
				if (!st[num] && !primes[num])
				{
					q.push({s, dist + 1});
				}
				s[i] = c;
			}
		}
	}
	std::cout << "Impossible" << "\n";
}

void solve()
{
	memset(st, 0, sizeof st);
	std::cin >> start >> end;
	bfs();
}

int main()
{
    IOS;
    int t = 1;
    init();
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}

