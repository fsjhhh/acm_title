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

bool check(int x, std::vector<int> a, int n)
{
	int p = 0;
	for (int i = 0; i < 3; i ++ )
	{
		p = upper_bound(a.begin(), a.end(), a[p] + 2 * x) - a.begin();
		if (p == n)
			return true;
	}
	return false;
}

void solve()
{
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i ++ )
    	std::cin >> a[i];
    std::sort(a.begin(), a.end());
    int l = -1, r = 1000000000;
    while (l < r)
    {
    	int mid = l + r >> 1;
    	if (check(mid, a, n))
    		r = mid;
    	else
    		l = mid + 1;
    } 
    std::cout << r << "\n";
}

int main()
{
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}

