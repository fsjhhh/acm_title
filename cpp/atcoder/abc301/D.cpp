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
LL n;

LL a[70];

void solve()
{
	std::string t;
    std::cin >> s >> n;
    reverse(s.begin(), s.end());
    
    LL ans = 0, cnt = 1;
   	for (int i = 0; i < s.size(); i ++ )
   	{
   		if (s[i] != '?')
   		{
   			ans = (ans + (cnt * (s[i] - '0')));
   		}
   		a[i] = cnt;
   		cnt *= 2;
   	}

   	if (ans > n)
   	{
   		std::cout << -1 << "\n";
   		return ;
   	}

   	for (int i = s.size(); i >= 0; i -- )
   	{
   		LL x = ans;
   		if (s[i] == '?')
   		{
   			ans = (ans + a[i]);
   			if (ans > n)
   				ans = x;
   		}
   	}

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

