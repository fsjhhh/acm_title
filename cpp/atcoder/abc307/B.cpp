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

const int N = 500;
std::string s[N];

bool check(std::string a, std::string b)
{
	std::string c = a + b;
	int l = 0, r = c.size() - 1;
	while (l <= r)
	{
		if (c[l] == c[r])
		{
			l ++ ;
			r -- ;
		}
		else
			return false;
	}
	return true;
}

void solve()
{
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i ++ )
    	std::cin >> s[i];
    for (int i = 1; i <= n; i ++ )
    {
    	for (int j = 1; j <= n; j ++ )
    	{
    		if (i == j)
    			continue;
    		if (check(s[i], s[j]))
    		{
    			std::cout << "Yes" << "\n";
    			return ;
    		}
    	}
    }
    std::cout << "No" << "\n";
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

