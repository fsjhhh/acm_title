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

void solve()
{
	int n;
	std::cin >> n;
	int ali = 0, bob = 0;
	int t = 1;
	int cnt = 1;
	int a = 1, b = 0;
	while (t <= n)
	{
		if (a)
		{
			ali += t;
			n -= t;
			t ++ ;
			cnt ++ ;
		}
		else
		{
			bob += t;
			n -= t;
			t ++ ;
			cnt ++ ;
		}
		if (cnt == 2)
		{
			a = !a;
			b = !b;
			cnt = 0;
		}
	}
	if (n != 0)
	{
		if (a)
			ali += n;
		else
			bob += n;
		
	}
	std::cout << ali << " " << bob << "\n";
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