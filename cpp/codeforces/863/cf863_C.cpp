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
int a[N];

void solve()
{
	int n;
	cin >> n;

	for (int i = 1; i < n; i ++ )
		cin >> a[i];

	bool pd = true;
	for (int i = 1; i < n - 1; i ++ )
	{
		if (pd)
		{
			if (a[i] < a[i + 1])
			{
				cout << 0 << " ";
				cout << a[i] << " ";
				pd = false;
			}
			else
				cout << a[i] << " ";
		}
		else
		{
			if (a[i] > a[i + 1])
			{
				cout << a[i + 1] << " ";
			}
			else
				cout << a[i] << " ";
		}
	}
	cout << a[n - 1] << " ";

	if (pd)
		cout << 0 << " ";

	cout << endl;

}

int main()
{
    IOS;
    int t = 1;
    cin >> t;
    while(t -- )
        solve();

    return 0;
}