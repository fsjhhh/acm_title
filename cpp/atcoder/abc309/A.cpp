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
	int a, b;
	std::cin >> a >> b;
	if (a > b)
		std::swap(a, b);
	if ((a == 1 && b == 2) || (a == 2 && b == 3) || (a == 4 && b == 5) || (a == 5 && b == 6) || (a == 7 && b == 8) || (a == 8 && b == 9))
		std::cout << "Yes" << "\n";
	else
		std::cout << "No" << "\n";    
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

