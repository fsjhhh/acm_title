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
int a[N];

void solve()
{
    int n;
    std::string s;
    std::cin >> n;
    for (int i = 1; i <= n; i ++ )
    	std::cin >> a[i];
    std::cin >> s;
    s = " " + s;
    std::vector<PII> _0, _1;
    for (int i = 1; i <= n; i ++ ) {
    	if (s[i] == '0')
    		_0.push_back({a[i], i});
    	else
    		_1.push_back({a[i], i});
    }

    std::sort(_0.begin(), _0.end());
    std::sort(_1.begin(), _1.end());

    std::vector<int> v(n + 1);
    int t = 1;
    for (auto [x, y] : _0) {
    	v[y] = t ++ ;
    }
    for (auto [x, y] : _1) {
    	v[y] = t ++ ;
    }

    for (int i = 1; i <= n; i ++ )
    	std::cout << v[i] << " \n"[i == n];
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