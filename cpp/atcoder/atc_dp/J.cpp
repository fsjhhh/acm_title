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

const int N = 310;
double f[N][N][N];
int a[5];

void solve()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++ )
	{
		int x;
		scanf("%d", &x);
		a[x] ++ ;
	}

	for (int k = 0; k <= n; k ++ )
	{
		for (int j = 0; j <= n; j ++ ) 
		{
			for (int i = 0; i <= n; i ++ )
			{
				if (i || j || k)
				{
					if (i)
						f[i][j][k] += f[i - 1][j][k] * i / (i + j + k);
					if (j)
						f[i][j][k] += f[i + 1][j - 1][k] * j / (i + j + k);
					if (k)
						f[i][j][k] += f[i][j + 1][k - 1] * k / (i + j + k);
					f[i][j][k] += ((n * 1.0) / ((i + j + k) * 1.0));
				}
			}
		}
	}

	printf("%0.15lf\n", f[a[1]][a[2]][a[3]]);

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