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

std::string s;
std::set<int> o, c;

void check(int u, int pd)
{
	if (s[u] == s[u + 1])
	{
		if (s[u] == '(')
		{
			if (pd)
				o.insert(u);
			else
				o.erase(u);
		}
		else
		{
			if (pd)
				c.insert(u);
			else
				c.erase(u);
		}
	}
}

void solve()
{
    int n, q;
    std::cin >> n >> q >> s;
    if (n % 2)
    {
    	while (q -- )
    	{
    		int x;
    		std::cin >> x;
    		std::cout << "No" << "\n";
    	}
    	return ;
    }

    for (int i = 0; i < n - 1; i ++ )
    	check(i, 1);

    while (q -- )
    {
    	int x;
    	std::cin >> x;
    	x -- ;

    	if (x > 0)
    		check(x - 1, 0);
    	if (x < n - 1)
    		check(x, 0);

    	if (s[x] == '(')
    		s[x] = ')';
    	else
    		s[x] = '(';

    	if (x > 0)
    		check(x - 1, 1);
    	if (x < n - 1)
    		check(x, 1);

    	if (s[0] == ')' || s[n - 1] == '(')
    	{
    		std::cout << "No" << "\n";
    		continue;
    	}
    	if (c.size() && (!o.size() || *o.begin() > *c.begin()))
    	{
    		std::cout << "No" << "\n";
    		continue;
    	}
    	if (o.size())
    	{
    		if (!c.size())
    		{
    			std::cout << "No" << "\n";
    			continue;
    		}
    		auto ito = o.end();
    		ito -- ;
    		auto itc = c.end();
    		itc -- ;
    		if (*ito > *itc)
    		{
    			std::cout << "No" << "\n";
    			continue;
    		}
    	}
    	std::cout << "Yes" << "\n";
    }

}

int main()
{
    IOS;
    int t = 1;
    while (t -- )
        solve();
    return 0;
}
