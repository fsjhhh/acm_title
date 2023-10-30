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

const int N = 2e5 + 10;
int a[N];

void solve()
{
    int n;
    std::cin >> n;
    int c[4];
    for (int i = 1; i <= n; i ++ )
    {
    	std::cin >> a[i];
    	if (a[i] == 1)
    		c[1] = i;
    	if (a[i] == 2)
    		c[2] = i;
    	if (a[i] == n)
    		c[3] = i;
    }
    if (c[3] > c[1] && c[3] < c[2])
    {
    	std::cout << c[3] << " " << c[3] << "\n";
    	return ;
    }
    if (c[3] < c[1] && c[3] > c[2])
    {
    	std::cout << c[3] << " " << c[3] << "\n";
    	return ;    	
    }
    if (abs(c[3] - c[1]) > abs(c[3] - c[2]))
    {
    	std::cout << c[3] << " " << c[2] << "\n";
    	return ;
    }
    if (abs(c[3] - c[1]) < abs(c[3] - c[2]))
    {
    	std::cout << c[3] << " " << c[1] << "\n";
    	return ;
    }

}

int main()
{
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
