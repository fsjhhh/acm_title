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

const int N = 1e5 + 10;
std::map<int, std::vector<int>> m;
int a[N];
std::vector<int> arr;

void solve()
{
	int n, q;
	std::cin >> n >> q;
	for (int i = 1; i <= n; i ++ )
	{
		std::cin >> a[i];
		m[a[i]].push_back(i);
	}
	while (q -- )
	{
		int a, b;
		std::cin >> a >> b;
		if (b > m[a].size())
			std::cout << -1 << "\n";
		else
			std::cout << m[a][b - 1] << "\n";
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

