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

const int N = 1e4 + 10;
const double eps = 1e-5;
int a[N][3], n;

double check(double x)
{
	double ans = 0;
	for (int i = 0; i < 3; i ++ )
		ans = ans * x + a[1][i];
	for (int i = 2; i <= n; i ++ )
	{
		double t = 0;
		for (int j = 0; j < 3; j ++ )
			t = t * x + a[i][j];
		ans = std::max(t, ans);
	}
	return ans;

}

void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++ )
	{
		for (int j = 0; j < 3; j ++ )
			scanf("%d", &a[i][j]);
	}

	double l = 0, r = 1000;
	while (r - l > eps)
	{
		double k = (r - l) / 3;
		double mid1 = l + k, mid2 = r - k;
		if (check(mid1) > check(mid2))
		{
			l = mid1;
		}
		else
		{
			r = mid2;
		}
	}

	printf("%.4lf\n", check(l));

}

int main()
{
    IOS;
    int t = 1;
    scanf("%d", &t);
    while(t -- )
        solve();

    return 0;
}
