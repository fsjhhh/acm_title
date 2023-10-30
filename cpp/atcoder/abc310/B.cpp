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

int p[210];
std::vector<int> c[210];

void solve()
{
    int n, m;
    std::cin >> n >> m;

    for (int i = 1; i <= n; i ++ )
    {
    	std::cin >> p[i];
    	int t;
        std::cin >> t;
    	for (int j = 0; j < t; j ++ )
    	{
    		int x;
    		std::cin >> x;
    		c[i].push_back(x);
    	}
    	std::sort(c[i].begin(), c[i].end());
    }

    for (int i = 1; i <= n; i ++ )
    {
    	for (int j = 1; j <= n; j ++ )
    	{
    		if (i == j)
    			continue;
    		if (p[i] > p[j])
    		{
    			bool pd = false;
    			for (int u = 0; u < c[i].size(); u ++ )
    			{
    				pd = false;
    				for (int v = 0; v < c[j].size(); v ++ )
    				{
    					if (c[i][u] == c[j][v])
    					{
    						pd = true;
    						break;
    					}
    				}
    				if (!pd)
    					break;
    			}
    			if (pd)
    			{
    				std::cout << "Yes" << "\n";
    				return ;
    			}
    		}
            else if (p[i] == p[j])
            {
                bool pd = false;
                for (int u = 0; u < c[i].size(); u ++ )
                {
                    pd = false;
                    for (int v = 0; v < c[j].size(); v ++ )
                    {
                        if (c[i][u] == c[j][v])
                        {
                            pd = true;
                            break;
                        }
                    }
                    if (!pd)
                        break;
                }
                if (pd && c[i].size() < c[j].size())
                {
                    std::cout << "Yes" << "\n";
                    return ;
                }
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

