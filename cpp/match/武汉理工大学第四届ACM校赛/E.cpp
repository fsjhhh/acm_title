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

const int N = 1010;
std::vector<std::pair<int, std::string>> a;
std::vector<int> ans;

void solve()
{
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i ++ )
	{
		std::string s;
		std::cin >> s;
		a.push_back({i, s});
	}
	int m;
	std::cin >> m;
	for (int i = 1; i <= m; i ++ )
	{
		std::string s;
		std::cin >> s;
		int j = 0;
		for (int i = 0; i < n; i ++ )
		{
			std::string str = a[i].second;
			if (str == s)
			{
				ans.push_back(a[i].first);
				a[i].first = 1;
				j = i;
			}
		}
		for (int i = 0; i < j; i ++ )
			a[i].first ++ ;
		std::sort(a.begin(), a.end());
	}
	std::cout << a.size() << "\n";
	for (auto t : ans)
	{
		std::cout << t << "\n";
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

