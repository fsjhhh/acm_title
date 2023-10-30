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
#define IOS std::ios::sync_with_stdio(false); \
            std::cin.tie(0);              \
            std::cout.tie(0);

typedef long long LL;
typedef std::pair<int, int> PII;
typedef std::pair<LL, LL> PLL;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;

const int N = 1e5 + 10;
int n;
int a[N], l[N], r[N];

void solve()
{
	std::cin >> n;
	for (int i = 1; i <= n; i ++ )
		std::cin >> a[i];
	for (int i = 1; i <= n; i ++ )
		l[i] = (l[i - 1] | a[i]);
	for (int i = n; i >= 1; i -- )
		r[i] = (r[i + 1] | a[i]);
	int res = 0;
	for (int i = 1; i <= n; i ++ )
	{
		res = std::max(res, l[i - 1] | r[i + 1]);
	}
	std::cout << res << std::endl;
}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
