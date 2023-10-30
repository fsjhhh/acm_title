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
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	double tx1 = ((x1 + x2) * 1.0) / 2.0;
	double ty1 = ((y1 + y2) * 1.0) / 2.0;
	cin >> x1 >> y1 >> x2 >> y2;
	double tx2 = ((x1 + x2) * 1.0) / 2.0;
	double ty2 = ((y1 + y2) * 1.0) / 2.0;

	double k = (ty1 - ty2) / (tx1 - tx2);
	double b = ty1 - k * tx1;
	printf("%.8lf\n%.8lf\n", k, b);

}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
