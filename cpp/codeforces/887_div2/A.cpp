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

const int N = 510;
LL a[N], b[N];

void solve()
{
    LL n, minn = INFL;
    std::cin >> n;
    for (int i = 1; i <= n; i ++ )
    	std::cin >> a[i];
    for (int i = 2; i <= n; i ++ )
    {
    	if (a[i] - a[i - 1] >= 0)
    		minn = std::min(minn, a[i] - a[i - 1]);
    	else
    	{
    		std::cout << 0 << "\n";
    		return ;
    	}
    }
    std::cout << minn / 2 + 1 << "\n";
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