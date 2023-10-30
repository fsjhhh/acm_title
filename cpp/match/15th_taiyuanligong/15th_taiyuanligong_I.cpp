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

std::string s;

void solve()
{
	std::cin >> s;
	bool pd = false;
	for (int i = 0; i < s.size() - 2; i ++ )
	{
		if (s[i] == 'e' && s[i + 1] == 'a' && s[i + 2] == 't')
		{
			pd = true;
			break;
		}
	}
	if (pd) std::cout << "eeffQAQ" << std::endl;
	else std::cout << "What does it mean?" << std::endl;
}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
