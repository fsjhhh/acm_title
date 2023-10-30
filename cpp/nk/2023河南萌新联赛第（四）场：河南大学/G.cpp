// Problem: 继续来数数
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/62880/G
// Memory Limit: 524288 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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

const int N = 1e5 + 10, mod = 1e9 + 7;
int a[N];
int n, m;

LL k_s(LL a, LL b)
{
	LL res = 1;
	while (b)
	{
		if (b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

LL C(LL a, LL b) {
	if (b > a)
		return 0;
	LL _a = 1, _b = 1, _a_b = 1;
	for (int i = 1; i <= a; i ++ ) {
		_a = (_a * i) % mod;
	}
	for (int i = 1; i <= b; i ++ ) {
		_b = (_b * i) % mod;
	}
	for (int i = 1; i <= (a - b); i ++ ) {
		_a_b = (_a_b * i) % mod;
	}
	_b = (_b * _a_b) % mod;
	
	return (_a * k_s(_b, mod - 2)) % mod;
	
}

void solve()
{
	std::cin >> n >> m;
	for (int i = 1; i <= n; i ++ ) {
		std::cin >> a[i];
	}
	
	std::map<int, int> ma;
	LL l = 0, r = 0;
	bool pd = false;
	for (int i = 1; i <= n; i ++ ) {
		if (ma.find(a[i]) != ma.end()) {
			l = ma[a[i]], r = i;
			pd = true;
		}
		ma[a[i]] = i;
	}
	
	if (!pd) {
		std::cout << C(n, m) << "\n";	
	}
	else {
		LL ans = C(n, m);
		LL a = (l - 1 + n - r);
		ans = (ans - C(a, m - 1) + mod) % mod;
		std::cout << ans << "\n";
	}
	
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