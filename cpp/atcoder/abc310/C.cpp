#include <iostream>
#include <cstdio>
#include <string>
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

std::set<std::string> s;

void solve()
{
	int n, ans = 0;
	std::cin >> n;
	for (int i = 1; i <= n; i ++ )
	{
		std::string str1;
		std::cin >> str1;
		std::string str2 = str1;
		reverse(str2.begin(), str2.end());
		if (s.find(str1) == s.end() && s.find(str2) == s.end())
		{
			s.insert(str1);
			s.insert(str2);
			ans ++ ;
		}
		else
		{
			s.insert(str1);
			s.insert(str2);
		}

	}   
	std::cout << ans << '\n'; 
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

