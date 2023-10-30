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

void solve(int x)
{
	std::string s1, s2;
	std::cin >> s1 >> s2;
	int n = s1.size(), m = s2.size();
	if (m < n)
	{
		std::cout << "Case #" << x << ": " << "IMPOSSIBLE" << "\n";
		return ;
	}
	for (int i = 0, j = 0;; i ++, j ++ )
	{
		while (j < m && s1[i] != s2[j])
			j ++ ;
		if (j >= m)
		{
			std::cout << "Case #" << x << ": " << "IMPOSSIBLE" << "\n";
			return ;
		}
		if (i == (n - 1))
		{
			std::cout << "Case #" << x << ": " << m - n << "\n";
			return ;
		}
	}    
}

int main()
{
	IOS;
	int t = 1;
	std::cin >> t;
	for (int i = 1; i <=	 t; i ++ )
	    solve(i);
	return 0;
}

