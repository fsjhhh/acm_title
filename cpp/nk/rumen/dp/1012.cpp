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

const int N = 1e5 + 10;
int a[N];
int f[N], g[N];

void solve()
{
	int n, x;
    while (std::cin >> x)
    	a[++ n ] = x;

    int idx = 0;
    f[0] = INF;
    for (int i = 1; i <= n; i ++ )
    {
    	if (a[i] <= f[idx])
    		f[++ idx] = a[i];
    	else
    	{
    		int l = 1, r = idx;
    		while (l < r)
    		{
    			int mid = l + r >> 1;
    			if (f[mid] < a[i])
    				r = mid;
    			else
    				l = mid + 1;
    		}
    		f[l] = a[i];
    	}
    }
    std::cout << idx << "\n";
    
    idx = 0;
    for (int i = 1; i <= n; i ++ )
    {
    	if (a[i] > g[idx])
    		g[++ idx] = a[i];
    	else
    	{
    		int l = 1, r = idx;
    		while (l < r)
    		{
    			int mid = l + r >> 1;
    			if (g[mid] > a[i])
    				r = mid;
    			else
    				l = mid + 1;
    		}
    		g[l] = a[i];
    	}
    }
    std::cout << idx << "\n";

}

int main()
{
    IOS;
    int t = 1;
    while (t -- )
        solve();
    return 0;
}
