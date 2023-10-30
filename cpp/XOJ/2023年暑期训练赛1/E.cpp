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
int a[N];

void solve()
{
	 int n, k;
	 std::cin >> n >> k;
	 for (int i = 1; i <= n; i ++ )
	 	std::cin >> a[i];
	 // if (n == 1)
	 // {
	 // 	std::cout << "Alice" << "\n";
	 // 	return ;
	 // }
	 int ans = 0;
	 for (int i = 1; i <= n; i ++ )
	 {
	 	if (a[i] == 1)
	 		ans ++ ;
	 	else
	 		break;
	 }
	 if (ans == n)
	 {
 		 if (ans % 2 == 1)
		 	std::cout << "Alice" << "\n";
		 else
		 	std::cout << "Bob" << "\n";
		 return ;
	 }
	 if (ans == 0)
	 {
	 	std::cout << "Alice" << "\n";
	 	return ;
	 }
	 if (ans % 2 == 0)
	 	std::cout << "Alice" << "\n";
	 else
	 	std::cout << "Bob" << "\n";
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

