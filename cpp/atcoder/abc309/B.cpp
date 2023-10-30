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

const int N = 110;
char a[N][N];
char s, s_1;

void solve()
{
	int n;
	std::cin >> n;
    for (int i = 1; i <= n; i ++ )
    {
    	for (int j = 1; j <= n; j ++ )
    		std::cin >> a[i][j];
    }
    for (int i = 1; i <= n; i ++ )
    {
    	if (i == 1)
    	{
    		for (int j = 1; j <= n; j ++ )
    		{
    			if (j == 1)
    			{
    				s = a[i][j + 1];
    				a[i][j + 1] = a[i][j];
    			}
    			else
    			{
    				s_1 = a[i][j + 1];
    				a[i][j + 1] = s;
    				s = s_1;
    			}
    		}
    	}
    	if (i == n)
    	{
    		for (int j = n; j >= 1; j -- )
    		{
    			if (j == n)
    			{
    				s = a[i][j - 1];
    				a[i][j - 1] = a[i][j];
    			}
    			else
    			{
    				s_1 = a[i][j - 1];
    				a[i][j - 1] = s;
    				s = s_1;
    			}
    		}
    	}
    }
    for (int i = 2; i <= n; i ++ )
    {
    	if (i == 2)
    	{
    		s = a[i][n];
    		a[i][n] = a[i - 1][n + 1];
    	}
    	else
    	{
    		s_1 = a[i][n];
    		a[i][n] = s;
    		s = s_1;
    	}
    }
    for (int i = n - 1; i >= 1; i -- )
    {
    	if (i == n - 1)
    	{
    		s = a[i][1];
    		a[i][1] = a[i + 1][0];
    	}
    	else
    	{
    		s_1 = a[i][1];
    		a[i][1] = s;
    		s = s_1;
    	}
    }
    for (int i = 1; i <= n; i ++ )
    {
    	for (int j = 1; j <= n; j ++ )
        {
    		std::cout << a[i][j];
        }
        std::cout << "\n";
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

