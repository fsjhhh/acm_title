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
    int n;
    std::cin >> n >> s;
    int t = 0, a = 0, pd = 0;
    for (int i = 0; i < s.size(); i ++ )
    {
    	if (s[i] == 'T')
    		t ++ ;
    	else
    		a ++ ;
    }
    if (t == a)
    {
    	if (s[n - 1] == 'A')
    		std::cout << 'T' << "\n";
    	else
            std::cout << 'A' << "\n";
    		std::cout << 'A' << "\n";
    }
    else
    {
    	if (t > a)
    		std::cout << 'T' << "\n";
    	else
    		std::cout << 'A' << "\n";
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

