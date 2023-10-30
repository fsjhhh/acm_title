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

const int N = 1e6 + 10;
char c[N];
int f[N][2];

void solve()
{
    int n;
    std::cin >> n >> c + 1;
    for (int i = 1; i <= n; i ++ )
    {
    	if (c[i] == '0')
    	{
    		int _0 = 0, _1 = 0;
    		_0 ++ ;
    		_1 += (f[i - 1][0] + f[i - 1][1]);
    		f[i][0] = _0;
    		f[i][1] = _1;
    	}
    	else
    	{
    		int _0 = 0, _1 = 0;
    		_1 ++ ;
    		_0 += (f[i - 1][1]);
    		_1 += (f[i - 1][0]);
    		f[i][0] = _0;
    		f[i][1] = _1;
    	}
    }
    LL ans = 0;
    for (int i = 1; i <= n; i ++ )
    	ans += f[i][1];
    std::cout << ans << "\n";
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


#include <iostream>
using namespace std;

int main()
{
    
    return 0;
}
