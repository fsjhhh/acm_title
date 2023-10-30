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
std::set<std::string> s;
bool f[N];

void solve()
{
    std::string str;
    int m = 0;
    while (1)
    {
    	std::cin >> str;
    	if (str == ".")
    		break;
    	s.insert(str);
        m = std::max(m, (int)(str.size()));
    }

    std::string n = " ";
    char c;
    while (std::cin >> c)
     	n += c;
    // for (int i = 1; i <= 12; i ++ )
    // {
    //     std::cin >> c;
    //     n += c;
    // }

    int ans = 0;
    f[0] = true;
    for (int i = 1; i < n.size(); i ++ )
    {
    	for (int j = std::min(i, m); j >= 1; j -- )
    	{
    		// std::string a = n.substr(i - j + 1, j);
            std::string a;
            for (int k = i - j + 1; k <= i; k ++ )
                a += n[k];
            // std::cout << a << "\n";
    		if (s.find(a) != s.end() && f[i - j])
    		{
    			ans = i;
    			f[i] = true;
    			break;
    		}
    	}
    }

    std::cout << ans << "\n";

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

