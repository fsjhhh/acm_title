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
//priority_queue 优先队列
#define IOS                           \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(0);                  \
    std::cout.tie(0);

typedef long long LL;
typedef std::pair<int, int> PII;
typedef std::pair<LL, LL> PLL;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;

const int N = 1e3 + 10;
int primes[N], st[N], idx;
int n;
LL f[N];

void get_primes()
{
	st[1] = true;
	for (int i = 2; i < N; i ++ )
	{
		if (!st[i])
			primes[idx ++ ] = i;
		for (int j = 0; primes[j] <= n / i; j ++ )
		{
			st[i * primes[j]] = true;
			if (i % primes[j] == 0)
				break;
		}
	}
}

void solve()
{
    std::cin >> n;
    get_primes();

    f[0] = 1;
    for (int i = 2; i <= n; i ++ )
    {
    	if (st[i])
    		continue;
    	for (int j = i; j <= n; j ++ )
    	{
    		f[j] += f[j - i];
    	}
    }

    std::cout << f[n] << "\n";
}

int main()
{
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}

