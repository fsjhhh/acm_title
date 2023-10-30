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

const int N = 10;
int a[N];

void solve()
{
   	for (int i = 1; i <= 8; i ++ )
   	{
   		std::cin >> a[i];
   	}
   	for (int i = 1; i <= 8; i ++ )
   	{
   		if (a[i] < a[i - 1] || a[i] < 100 || a[i] > 675 || a[i] % 25)
   		{
   			std::cout << "No" << "\n";
   			return ;
   		}
   	}
   	std::cout << "Yes" << "\n";
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

