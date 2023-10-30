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

const int N = 2e5 + 10;
LL a[N], b[N];
LL res[N], idx;

void solve()
{
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);
    int n;
    std::cin >> n;
    std::map<LL, int> m;
    int cnt = 0;
    LL _2;
    bool pd = false;
    for (int i = 1; i < n; i ++ )
    {
    	std::cin >> a[i];
    	b[i] = a[i] - a[i - 1];
    	m[b[i]] ++ ;
    	if (b[i] > n || m[b[i]] >= 2)
    	{
    		cnt ++ ;
    		_2 = b[i];
    		if (cnt >= 2)
    			pd = true;
    	}
    }
    if (pd)
    {
    	std::cout << "No" << "\n";
    	return ;
    }
    
    idx = 0;
    for (int i = 1; i <= n; i ++ )
    {
    	if (m.find(i) == m.end())
    		res[idx ++ ] = i;
    }

    if (idx > 2)
    {
    	std::cout << "No" << "\n";
    }
    else
    {
        if (idx == 1)
        {
            std::cout << "Yes" << "\n";
            return ;
        }
    	if (res[0] + res[1] == _2)
    		std::cout << "Yes" << "\n";
        else
            std::cout << "No" << "\n";
    }

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