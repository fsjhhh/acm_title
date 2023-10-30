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

const int N = 25;
char a[N][N];
char b[N][N];
char x[N * 2][N * 2];

void solve()
{
    int ha, wa, hb, wb, hx, wx;
    std::cin >> ha >> wa;
    for (int i = 1; i <= ha; i ++ )
    	for (int j = 1; j <= wa; j ++ )
    		std::cin >> a[i][j];

   	std::cin >> hb >> wb;
   	for (int i = 1; i <= hb; i ++ )
   		for (int j = 1; j <= wb; j ++ )
   			std::cin >> b[i][j];

    for (int i = 0; i < 50; i ++ )
        for (int j = 0; j < 50; j ++ )
            x[i][j] = '.';

    std::cin >> hx >> wx;
   	for (int i = 1; i <= hx; i ++ )
   		for (int j = 1; j <= wx; j ++ )
   			std::cin >> x[i + 10][j + 11];

    for (int i = 1; i <= hx + 10; i ++ )
        for (int j = 1; j <= wx + 11; j ++ )
            for (int p = 1; p <= hx + 10; p ++ )
                for (int q = 1; q <= wx + 11; q ++ )
                {
                    char ans[N * 2][N * 2];
                    for (int u = 0; u < 50; u ++ )
                        for (int v = 0; v < 50; v ++ )
                                ans[u][v] = '.';

                    for (int u = 1; u <= ha; u ++ )
                        for (int v = 1; v <= wa; v ++ )
                            if (a[u][v] == '#')
                                ans[i + u - 1][j + v - 1] = '#';

                    for (int u = 1; u <= hb; u ++ )
                        for (int v = 1; v <= wb; v ++ )
                            if (b[u][v] == '#')
                                ans[p + u - 1][q + v - 1] = '#';

                    bool pd = false;
                    for (int u = 1; u <= 45; u ++ )
                        for (int v = 1; v <= 45; v ++ )
                            if (ans[u][v] != x[u][v])
                                pd = true;

                    if (!pd)
                    {
                        std::cout << "Yes" << "\n";
                        return ;
                    }

                }
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

