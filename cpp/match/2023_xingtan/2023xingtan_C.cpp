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

const int N = 200010;
int primes[N], idx;
bool st[N];

void get_primes(int x)
{
	st[1] = true;
	for (int i = 2; i <= x; i ++ )
	{
		if (!st[i]) primes[idx ++ ] = i;
		for (int j = 0; primes[j] * i <= x; j ++ )
		{
			st[primes[j] * i] = true;
			if (i % primes[j] == 0) break;
		}
	}
}

bool cmp(int a, int b)
{
	if (a % 2 == 0 && b % 2 == 1)
		return a < b;
	return a > b;
}

void solve()
{
	int a[4];
	for (int i = 1; i <= 3; i ++ )
		cin >> a[i];
	sort(a + 1, a + 4, cmp);
	for (int i = 1; i <= 3; i ++ )
		cout << a[i] << " ";
	cout << endl;
	if (a[1] + a[2] == 2)
	{
		if (a[3] % 2)
		{
			cout << "p" << endl;
			return ;
		}
		else
		{
			cout << "R" << endl;
			return ;
		}
	}
	if (a[1] % 2 && a[2] % 2 && a[3] % 2 == 0)
	{
		if (!st[a[1] + a[3]] && !st[a[2] + a[3]] && a[3])
		{
			cout << "R" << endl;
			return ;
		}
		else
		{
			cout << "P" << endl;
			return ;
		}

	}
	else if (!(a[1] % 2) && !(a[2] % 2) && !(a[3] % 2))
	{
		cout << "R" << endl;
		return ;
	}
	else
	{
		cout << "P" << endl;
		return ;
	}

}

int main()
{
    IOS;
    get_primes(200000);
    int t = 1;
    cin >> t;
    while(t -- )
        solve();

    return 0;
}
