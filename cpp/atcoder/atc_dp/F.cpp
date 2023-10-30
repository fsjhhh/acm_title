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

const int N = 30010;
int f[3010][3010];
std::string a, b;
char s[N];

void solve()
{
    std::cin >> a >> b;
    a = " " + a, b = " " + b;
    int n = a.size() - 1, m = b.size() - 1;
    for (int i = 1; i <= n; i ++ )
    	for (int j = 1; j <= m; j ++ )
    	{
    		f[i][j] = std::max(f[i - 1][j], f[i][j - 1]);
    		if (a[i] == b[j])
    			f[i][j] = std::max(f[i][j], f[i - 1][j - 1] + 1);
    	}

    int i = n, j = m;
    while (f[i][j] > 0)
    {
    	if (a[i] == b[j])
    	{
    		s[f[i][j]] = a[i];
    		i -- , j -- ;
    	}
    	else
    	{
    		if (f[i][j] == f[i - 1][j])
    			i -- ;
    		else
    			j -- ;
    	}
    }
    std::cout << s + 1 << "\n";

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