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

std::string s;

void solve()
{
	int k;
	std::cin >> k;
    std::cin >> s;
    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= m; i ++ )
    {
    	int a, b;
    	std::cin >> a >> b; 
    }
    int t = m - (n - 1);
    LL cnt = 0, sum = 1;
    int i = 0;
    while (1)
    {
    	t -- ;
    	if (t < 0)
    	{
    		if (s[i] == '1')
    		{
    			std::cout << 2 << "\n";
    		}
    		else
    		{
    			std::cout << 1 << "\n";
    		}
            return ;
    	}
        
        i = (i + 1) % k;
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