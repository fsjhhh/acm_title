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

const int N = 110;
std::string s[N];

void solve()
{
	int n, d;
	std::cin >> n >> d;
	for (int i = 1; i <= n; i ++ )
		std::cin >> s[i];
	int ans = 0, res = 0;
	for (int i = 0; i < d; i ++ )
	{
		bool pd = false;
		for (int j = 1; j <= n; j ++ )
		{
			if (s[j][i] == 'x')
			{
				pd = true;
				break;
			}
		}
		if (pd)
			ans = 0;
		else
			ans ++ ;
		res = std::max(res, ans);
	}
	std::cout << res << "\n";
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