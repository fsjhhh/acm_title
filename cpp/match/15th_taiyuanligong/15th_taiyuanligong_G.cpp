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

const int N = 510;
int n;
char s[N];

void solve()
{
	std::cin >> n >> s + 1;
	int l = 1, r = n;
	while (l < r)
	{
		if (s[l] != s[r])
		{
			if (s[l] < s[r])
				s[r] = s[l];
			else
				s[l] = s[r];
			break;
		}
		l ++ , r -- ;
	}
	if (l == r)
	{
		if (s[l] == 'a')
			s[l] = 'b';
		else
			s[l] = 'a';
	}
	for (int i = 1; i <= n; i ++ )
		std::cout << s[i];
}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
