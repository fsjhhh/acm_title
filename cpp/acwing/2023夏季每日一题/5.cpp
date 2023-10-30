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

void solve(int t)
{
    LL L, n, dist = 0, res = 0;
    std::cin >> L >> n;
    for (int i = 1; i <= n; i ++ )
    {
    	LL d;
    	char s;
    	std::cin >> d >> s;
    	if (s == 'C')
    	{
    		dist += d;
    		LL x = abs(dist) / L;
    		res += x;
    		dist = (dist < 0) ? -(abs(dist) % L) : (abs(dist) % L);
    	}
    	else
    	{
    		dist -= d;
    		LL x = abs(dist) / L;
    		res += x;
    		dist = (dist < 0) ? -(abs(dist) % L) : (abs(dist) % L);
    	}	
    }
    std::cout << "Case #" << t << ": " << res << "\n";
}

int main()
{
    IOS;
    int t = 1;
    std::cin >> t;
    for (int i = 1; i <= t; i ++ )
        solve(i);
    return 0;
}

