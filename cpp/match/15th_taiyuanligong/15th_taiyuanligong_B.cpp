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
#define IOS std::ios::sync_with_stdio(false); \
            std::cin.tie(0);              \
            std::cout.tie(0);

typedef long long LL;
typedef std::pair<int, int> PII;
typedef std::pair<LL, LL> PLL;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;

int n;
std::string s;

void solve()
{
	std::cin >> n >> s;
	int t = -1;
	for (int i = n - 1; i >= 0; i -- )
	{
		if (s[i] == 'C')
		{
			t = i;
			break;
		}
	}
	if (t == -1) 
	{
		std::cout << "draw" << std::endl;
		return ;
	}
	if (t == 0) 
	{
		std::cout << "draw" << std::endl;
		return ;
	}
	int ans = 0;
	for (int i = 0; i < t; i ++ )
	{
		if (s[i] == 'C' || s[i] == 'B')
			ans ++ ;
	}
	std::cout << ans - 1 << std::endl;
}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
