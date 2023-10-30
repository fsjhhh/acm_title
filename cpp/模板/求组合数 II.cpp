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
#define IOS ios::sync_with_stdio(false); \
            cin.tie(0);              \
            cout.tie(0);
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;

const int N = 1e5 + 10, mod = 1e9 + 7;
LL fac[N], infac[N];

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

void solve()
{
	fac[0] = 1, infac[0] = 1;
	for (int i = 1; i <= 100000; i ++ )
	{
		fac[i] = fac[i - 1] * i % mod;
		infac[i] = infac[i - 1] * k_s(i, mod - 2) % mod; 
	}

	int n;
	cin >> n;
	while (n -- )
	{
		LL a, b;
		cin >> a >> b;
		cout << fac[a] * infac[b] % mod * infac[a - b] % mod << endl;
	}

}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}