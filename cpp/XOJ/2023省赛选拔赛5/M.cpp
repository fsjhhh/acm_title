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

const int N = 1e7 + 10;
int primes[N], cnt = 0, f[N];
LL sum[N];
bool st[N];

void get_primes2()
{
	for(int i = 2; i <= N - 1; i ++ )
	{
		if(!st[i]) primes[cnt ++ ] = i;
		for(int j = 0; primes[j] <= (N - 1) / i; j ++ )
		{
			st[primes[j] * i] = true;
			if(i % primes[j] == 0)
				break;
		}
	}
}

int get(int n) {
    if (n % 2 == 0 && n != 2) {
        return 2;
    }
    else {
        if (!st[n]) {
            return 1;
        }
        else if (!st[n - 2]) {
            return 2;
        }
        else {
            return 3;
        }
    }

}

void solve()
{
    get_primes2();
    for (int i = 2; i < N; i ++ ) {
        f[i] = get(i);
        sum[i] = sum[i - 1] + f[i];
    }
    int q;
    std::cin >> q;
    while (q -- ) {
    	int n;
    	std::cin >> n;
        std::cout << sum[n] << "\n";
    }
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