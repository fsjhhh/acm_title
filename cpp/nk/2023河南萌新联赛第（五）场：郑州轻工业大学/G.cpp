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

bool check(int x) {
	while (x) {
		if (x % 2 == 0) {
			return false;
		}
		x /= 2;
	}
	return true;
}

void solve()
{
	int n;
 	std::cin >> n;
 	if (check(n)) {
 		std::cout << 1 << "\n";
 	}   
 	else {
 		std::cout << 0 << "\n";
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