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
#define IOS ios::sync_with_stdio(false); \
            cin.tie(0);              \
            cout.tie(0);
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;

void solve()
{
	int t;
	double x = 1;
	scanf("%d", &t);
	for (int i = 1; i <= t; i ++ )
	{
		int n;
		scanf("%d", &n);
		if (n == 1)
		{
			double a;
			scanf("%lf", &a);
			printf("%d: %.4lf %.4lf\n", i, a, x);
			continue;
		}
		double c = 0;
		for (int j = 1; j <= n; j ++ )
		{
			double a;
			scanf("%lf", &a);
			if (j == 1) c -= a;
			if (j == n) c += a; 
		}
		c /= 2;

		double s = (n - 1) * 2;

		double d = sqrt(s * s - c * c);

		printf("%d: %.4lf %.4lf\n", i, c + x, d + x);
	}
}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
