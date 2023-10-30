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

const LL N = 1e12 + 10;
LL a[1000010];

void solve()
{
	LL n, k;
	std::cin >> n >> k;
	LL t = -1;
	a[0] = 1;
	for (int i = 1; ; i ++ )
	{
		a[i] = a[i - 1] * k;
		if (a[i] > n && t == -1) // i - 1 为 0 的数量
		{
			t = (i - 1);
		}
		if (a[i] >= N)
			break;
	}

	for (int i = 1; i < k; i ++ )
	{
		LL sum = 0, j = 0;
		while (sum <= n) // j - 1 为 i 的数量
		{
			sum += a[j] * i;
			j ++ ;
		}
		t += (j - 1);
	}
	std::cout << t << "\n";

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

