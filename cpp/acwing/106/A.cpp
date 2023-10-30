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

void solve()
{
	int n, m;
	std::cin >> n >> m;
	std::string s;
	std::cin >> s;
	while (m -- )
	{
		int l, r;
		char c1, c2;
		std::cin >> l >> r >> c1 >> c2;
		for (int i = l - 1; i < r; i ++ )
			if (s[i] == c1)
				s[i] = c2;
	}    
	std::cout << s << "\n";
}

int main()
{
    IOS;
    int t = 1;
    while (t -- )
        solve();
    return 0;
}
