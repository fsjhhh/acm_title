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
 	int n, a, b;
 	std::cin >> n >> a >> b;
 	std::cout << "Yes" << "\n";
 	std::cout << n - 1 << "\n";
 	LL zs = a, zz = b, zx = a, zy = b;
 	for (int i = 1; i < n; i ++ ) {
 		if (zs > 1 && zz > 1) {
  			zs -- ;
 			zz -- ;
 			std::cout << zs << " " << zz << " " << zx - zs << " " << zy - zz << "\n";

 		}
 		else if (zz > 1 && zx < n) {
 			zz -- ;
 			zx ++ ;
 			std::cout << zx << " " << zz << " " << zs - zx << " " << zy - zz << "\n";
 		}
 		else if (zx < n && zy < n) {
 			zx ++ ;
 			zy ++ ;
 			std::cout << zx << " " << zy << " " << zs - zx << " " << zz - zy << "\n";
 		}
 		else if (zs > 1 && zy < n) {
 			zs -- ;
 			zy ++ ;
 			std::cout << zs << " " << zy << " " << zx - zs << " " << zz - zy << "\n";
 		}
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