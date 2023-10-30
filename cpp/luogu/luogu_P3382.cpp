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

const int N = 20;
const double eqs = 1e-6;
double a[N];
int n;
double l1, r1;

double check(double x)
{
	double t = 0;
	for (int i = 0; i <= n; i ++ )
	{
		t = t * x + a[i];
	}
	return t;
}

void solve()
{
	scanf("%d%lf%lf", &n, &l1, &r1);
	for (int i = 0; i <= n; i ++ )
	{
		scanf("%lf", &a[i]);
	}

	double l = l1, r = r1;
	while (r - l > eqs)
	{
		double t = (r - l) / 3.0;
		double mid1 = l + t, mid2 = r - t;
		if (check(mid1) > check(mid2))
		{
			r = mid2;
		}
		else
		{
			l = mid1;
		}
	}

	printf("%.5lf\n", l);

}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
