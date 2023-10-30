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
    memset(a, 0, sizeof a);
    int n;
    std::cin >> n;
    a[1] = 3, a[n] = 2;
    if (n % 2)
    	a[n / 2 + 1] = 1;
    else
    	a[n / 2] = 1;
    int x = n;
    for (int i = 1; i <= n; i ++ )
    {
    	if (!a[i])
    		a[i] = x -- ;
    } 
    for (int i = 1; i <= n; i ++ )
    	std::cout << a[i] << " \n"[i == n];
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

