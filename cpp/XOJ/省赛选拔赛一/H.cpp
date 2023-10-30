/*
In every life we have some trouble． When you worry you make it double．
Don't worry，be happy．
                 .-~~~~~~~~~-._       _.-~~~~~~~~~-.
             __.'              ~.   .~              `.__
           .'//                  \./                  \`.
         .'//                     |                     \`.
       .'// .-~"""""""~~~~-._     |     _,-~~~~"""""""~-. \`.
     .'//.-"                 `-.  |  .-'                 "-.\`.
   .'//______.============-..   \ | /   ..-============.______\`.
 .'______________________________\|/______________________________`.*/
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
PII a[N];

void solve()
{
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i ++ )
    	std::cin >> a[i].first >> a[i].second;
    std::sort(a + 1, a + n + 1);
    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    LL i = 1, x = -1, ans = 0;
    while (1)
    {
    	while (q.size() && q.top() < x)
    		q.pop();
    	if (q.size())
    	{
    		ans ++ ;
    		q.pop();
    		x ++ ;
    	}
    	else
    	{
    		if (i > n)
    			break;
    		x = a[i].first;
    	}
    	while (i <= n && a[i].first == x)
    	{
    		q.push(a[i].second);
    		i ++ ;
    	}
    }
    std::cout << ans << "\n";
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