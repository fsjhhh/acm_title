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

const int N = 110;
int f[N];

void solve()
{
	/*
		打表
		K T  循环节
		3 4  0111
		4 3  011
		5 3  011
		6 7  0110111
		7 3  011
		8 3  011
		9 10 0110110111
	*/
	/*
	int n, k;
	cin >> n >> k;
	f[0] = 0;
	for (int i = 1; i <= n; i ++ )
	{
		int d[] = {1, 2, k};
		for (int x : d)
		{
			if (i >= x && !f[i - x])
				f[i] = 1;
		}
	}

	for  (int i = 0; i <= n; i ++ )
		cout << f[i] << " ";
	*/

	int t;
	cin >> t;
	while (t -- )
	{
		int n, k;
		cin >> n >> k;
		if (k % 3)
		{
			if (n % 3) cout << "Alice" << endl;
			else cout << "Bob" << endl;
		}
		else
		{
			int r = n % (k + 1);
			if (r == k || r % 3) cout << "Alice" << endl;
			else cout << "Bob" << endl;
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
