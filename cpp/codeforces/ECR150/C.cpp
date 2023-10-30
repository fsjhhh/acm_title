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

LL r[6];

LL ans = -INFL;
LL n;
void check(std::string s, int pd)
{
    for (int w = 1; w <= 5; w ++ )
    {
        s[pd] = w + 'A' - 1;
        LL an = 0;
        char ls = s[n - 1];
        for (int i = n - 1; i >= 0; i -- )
        {
            int t = s[i] - 'A' + 1;
            if (s[i] < ls)
                an = (an - r[t]);
            else
            {
                an = (an + r[t]);
                ls = s[i];
            }
        }
        ans = std::max(an, ans);
    }
}

void solve()
{
	r[1] = 1;
	for (int i = 2; i <= 5; i ++ )
		r[i] = r[i - 1] * 10;
    std::string s;
    std::cin >> s;
    n = s.size(); 
    std::vector<int> a(6), b(6);
    bool pda[6], pdb[6];
    memset(pda, 0, sizeof pda);
    memset(pdb, 0, sizeof pdb);
    for (int i = 0; i < n; i ++ )
    {
        int t = s[i] - 'A' + 1;
        if (!pda[t])
        {
            a[t] = i;
            pda[t] = true;
        }
    }
    for (int i = n - 1; i >= 0; i -- )
    {
        int t = s[i] - 'A' + 1;
        if (!pdb[t])
        {
            b[t] = i;
            pdb[t] = true;
        }
    }
    
    for (int i = 1; i <= 5; i ++ )
    {
        check(s, a[i]);
        check(s, b[i]);
    }

    std::cout << ans << "\n";
    ans = -INFL;
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

