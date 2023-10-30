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

const int N = 3010;
int a[N], sum[N][3];
int f[N], n, m;

bool check(int x, int y)
{
	int s = abs((sum[x][1] - sum[y][1]) - (sum[x][2] - sum[y][2]));
	if (s <= m || !(sum[x][1] - sum[y][1]) || !(sum[x][2] - sum[y][2]))
		return true;
	return false;
}

void solve()
{
    memset(f, 0x3f, sizeof f);
    std::cin >> n >> m;
    for (int i = 1; i <= n; i ++ )  
    {
    	std::cin >> a[i];
    	if (a[i] == 1)
    	{
    		sum[i][1] = sum[i - 1][1] + 1;
    		sum[i][2] = sum[i - 1][2];
    	}
    	else
    	{
    		sum[i][2] = sum[i - 1][2] + 1;
    		sum[i][1] = sum[i - 1][1];
    	}
    }

    f[0] = 0;
    for (int i = 1; i <= n; i ++ )
    {
    	for (int j = 0; j < i; j ++ )
    	{
    		if (check(i, j))
    			f[i] = std::min(f[i], f[j] + 1);
    	}
    }

    std::cout << f[n] << "\n";
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

