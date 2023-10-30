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
int n;

void solve()
{
    std::cin >> n >> s;
    std::string a = "";
    char ls = s[0];
    a += ls;
    for (int i = 1; i < n; i ++ )
    {
    	if (s[i] == ls)
    	{
            if (i + 1 < n)
            {
        		ls = s[i + 1];
        		a += ls;
                i ++ ;
            }
    	}
    }
    std::cout << a << "\n";
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

