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
LL n, m;
int a[N], idx;
int ne[N];

// void solve()
// {
// 	std::cin >> n >> m;
// 	int r = 1;
// 	if (n == 1)
// 	{
// 		std::cout << 0 << "\n";
// 		return ;
// 	}
// 	for (int i = 1; i < N - 2; i ++ )
// 	{
// 		r *= 10;
// 		a[i] = r / n;
// 		r %= n;
// 	}
// 	int z = 0;
// 	for (int i = 2, j = 0; i < N - 2; i ++ )
// 	{
// 		while (j && a[j + 1] != a[i])
// 			j = ne[j];
// 		if (a[j + 1] == a[i])
// 			j ++ ;
// 		ne[i] = j;
// 		if (i % (i - ne[i]) == 0 && i != i - ne[i])
// 		{
// 			if (i - ne[i] <= i / 2)
// 				z = std::max(z, i - ne[i]);
// 		}
// 	}
// 	m %= z;
// 	std::cout << a[m + z] << "\n";
// }

void solve()
{
	std::cin >> n >> m;
	if (n == 1)
	{
		std::cout << 0 << "\n";
		return ;
	}
	int r = 1;
	do
	{
		r *= 10;
		a[idx ++ ] = r / n;
		r %= n;
	} while (r != 1);
	std::cout << a[(m - 1) % idx] << "\n";
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

