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
	int n;
	cin >> n;
	int t = n * (n + 1) / 2;
	if (n == 1)
	{
		cout << 2 << endl;
		cout << 2 << " " << 1 << endl;
	}
	else
	{
		cout << 3 << endl;
		cout << 1 << " " << t - 1 << " " << 0 << endl;
		for (int i = 2; i <= n; i ++ )
		{
			cout << i << " " << 0 << " " << i << endl;
		}
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
