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

const int N = 2e5 + 10;
char a[N];

void solve()
{
	int n, d;
	scanf("%d%d%s", &n, &d, a + 1);

	bool pd = true;
	int c = 0;
	for (int i = 1; i <= n; i ++ )
	{
		if (a[i] < (d + '0') && pd)
		{
			c = i;
			pd = false;
		}
	}
	
	for (int i = 1; i <= n; i ++ )
	{
		if (c == i)
			cout << d;		
		cout << a[i];
	}
	if (c == 0)
		cout << d;


	cout << endl;

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
