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

const int N = 110;
PII a[N];
int f[N][N];

bool cmp(PII x, PII y)
{
	return x.first < y.first;
}

void solve()
{
    int n, m;
    std::cin >> n >> m;
    m = n - m;
    for (int i = 1; i <= n; i ++ )
    	std::cin >> a[i].first >> a[i].second;

    std::sort(a + 1, a + n + 1, cmp);

    memset(f, 0x3f, sizeof f);
    for (int i = 1; i <= n; i ++ )
    	f[i][1] = 0;

    for (int i = 2; i <= n; i ++ )
    	for (int j = 1; j < i; j ++ )
    		for (int k = 2; k <= std::min(i, m); k ++ )
    			f[i][k] = std::min(f[i][k], f[j][k - 1] + abs(a[i].second - a[j].second));
    int minn = INF;
    for (int i = 1; i <= n; i ++ )
    	minn = std::min(minn, f[i][m]);
    std::cout << minn << "\n";
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