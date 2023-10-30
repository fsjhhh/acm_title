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

void solve()
{
	std::map<LL, LL> m;
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i ++ ) {
		int a;
		std::cin >> a;
		m[a] ++ ;
	} 
	int q;
	std::cin >> q;
	while (q -- ) {
		LL x, y;
		std::cin >> x >> y;
		LL deita = x * x - 4 * y;
		LL sq_deita = sqrt(deita);
		if (sq_deita * sq_deita != deita) {
			std::cout << 0 << " ";
			continue;
		}
		LL ca_1 = x + sq_deita;
		LL ca_2 = x - sq_deita;
		if (ca_1 % 2 || ca_2 % 2) {
			std::cout << 0 << " ";
			continue;
		}
		ca_1 /= 2, ca_2 /= 2;
		// std::cout << ca_1 << " " << ca_2 << "\n";
		if (ca_1 == ca_2) {
			std::cout << m[ca_1] * (m[ca_1] - 1) / 2 << " ";
			continue;
		}
		std::cout << m[ca_1] * m[ca_2] << " ";
	}
	std::cout << "\n";
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