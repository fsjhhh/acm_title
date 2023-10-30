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

const int N = 2e5 + 10;
PLL a[N];

bool cmp(PLL x, PLL y)
{
	return x.first < y.first;
}

void solve()
{
    int n, k;
    std::cin >> n >> k;
    for (int i = 1; i <= n; i ++ )
    {
    	std::cin >> a[i].first;
    	a[i].second = i;
    }
    std::sort(a + 1, a + n + 1, cmp);
    LL maxx = INFL;
    int _1 = -1, _2 = -1;
    for (int i = 2; i <= n; i ++ )
    {
    	if (maxx > (a[i].first ^ a[i - 1].first))
    	{
    		maxx = (a[i].first ^ a[i - 1].first);
    		_1 = i, _2 = i - 1;
    	}
    }
    LL ans = 0;
    for (int i = 0; i < k; i ++ )
    {
    	int a_1 = (a[_1].first >> i) & 1;
    	int b_1 = (a[_2].first >> i) & 1;
    	if (a_1 == b_1 && a_1 == 0)
    		ans += (1LL << i);
    }
    _1 = a[_1].second, _2 = a[_2].second;
    if (_1 > _2) std::swap(_1, _2);
    std::cout << _1 << " " << _2 << " " << ans << "\n";
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