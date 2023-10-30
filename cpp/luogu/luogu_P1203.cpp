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
int n;

int check(int u)
{
	int ans = 0;
	char x = s[u], y = s[u + n - 1];
	int l = u;
	while (x == 'w' && l < u + n)
		x = s[l ++ ];
	if (l == u + n)
		return n;
	l = u + n - 1;
	while (y == 'w' && l >= u)
		y = s[l -- ];
	if (l == u)
		return n;

	for (int i = u; i < u + n; i ++ )
	{
		if (s[i] == x)
			ans ++ ;
		else if (s[i] == 'w')
			ans ++ ;
		else
			break;
	}
	for (int i = u + n - 1; i >= u; i -- )
	{
		if (s[i] == y)
			ans ++ ;
		else if (s[i] == 'w')
			ans ++ ;
		else
			break;
	}
	return ans;
}

void solve()
{ 
    std::cin >> n >> s;
    s = s + s;
    int ans = -1;
    for (int i = 0; i < n; i ++ )
    	ans = std::max(ans, check(i));
    if (ans > n)
    	ans = n;
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

