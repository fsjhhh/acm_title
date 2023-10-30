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

const int N = 1e5 + 10;
int a[N], f[N][25];
int n, m;

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

void pre()
{
	int k = log2(n + 1);
    for (int i = 1; i <= n; i ++ )
        f[i][0] = a[i];
	for (int j = 1; j <= k; j ++ )
		for (int i = 1; i + (1 << j) - 1 <= n; i ++ )
			f[i][j] = std::max(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
}

int rmq(int l, int r)
{
	int k = log2(r - l + 1);
	return std::max(f[l][k], f[r - (1 << k) + 1][k]);
}

void solve()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i ++ )
    	a[i] = read();
    pre();
    while (m -- )
    {
    	int l, r;
    	l = read(), r = read();
    	std::cout << rmq(l, r) << "\n";
    }
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

