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

const int N = 1e6 + 10, mod = 998244353;
int a[N];

void solve()
{
	int n;
	std::string s;
	std::cin >> n >> s;
	for (int i = 0; i < n; i ++ ) {
		a[i + 1] = (s[i] - '0');
	}
	bool pd = false;
	for (int i = 2; i <= n; i ++ ) {
		if (a[i] > 1 && a[i - 1] > 1) {
			pd = true;
		}
	}
	if (pd) {
		std::cout << "-1" << "\n";
		return ;
	}
	LL ans = 1;
	for (int i = n; i >= 1; i -- ) {
		if (i != 1) {
			ans = (ans + 1 + ans * (a[i] - 1) % mod) % mod;
		}
	}
	std::cout << ans - 1 << "\n";
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