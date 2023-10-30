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

const int N = 1010;
int primes[N], cnt;
bool st[N];

void get_primes2(int n) // 线性筛
{
	for(int i = 2; i <= n; i ++ )
	{
		if(!st[i]) primes[cnt ++ ] = i;
		for(int j = 0; primes[j] <= n / i; j ++ )
		{
			st[primes[j] * i] = true;
			if(i % primes[j] == 0)
				break;
		}
	}
}

void solve()
{
	get_primes2(N - 1);
	int t;
	cin >> t;
	while (t -- )
	{
		int n, k, res = 0;
		cin >> n >> k;
		for (int i = 2; i <= n; i ++ )
		{
			if (st[i]) continue;
			else
			{
				for (int j = 1; j < cnt; j ++ )
				{
					if (primes[j - 1] + primes[j] + 1 == i)
					{
						res ++ ;
						break;
					}
				}
			}
		}
		if (res >= k) cout << "YES" << endl;
		else cout << "NO" << endl;
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
