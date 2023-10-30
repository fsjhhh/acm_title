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

const int N = 5;
char a[N][N];

void solve()
{
    for (int i = 1; i <= 3; i ++ )
    	for (int j = 1; j <= 3; j ++ )
    		std::cin >> a[i][j];

    for (int i = 1; i <= 3; i ++ )
    {
    	if (a[i][1] == a[i][2] && a[i][2] == a[i][3] && a[i][1] != '.')
    	{
    		std::cout << a[i][1] << "\n";
    		return ;
    	}
    	if (a[1][i] == a[2][i] && a[2][i] == a[3][i] && a[1][i] != '.')
    	{
    		std::cout << a[1][i] << "\n";
    		return ;
    	}
    }
    if (a[1][1] == a[2][2] && a[2][2] == a[3][3] && a[1][1] != '.')
    {
		std::cout << a[1][1] << "\n";
		return ;   	
    }
    if (a[1][3] == a[2][2] && a[2][2] == a[3][1] && a[3][1] != '.')
    {
    	std::cout << a[1][3] << "\n";
    	return ;
    }
    std::cout << "DRAW" << "\n";
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

