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
    std::string s[2];
    std::cin >> s[0] >> s[1];
    int t, q;
    std::cin >> t >> q;
    std::vector<int> a(q + 1);
    int cnt = 0;
    for (int i = 0; i < s[0].size(); i ++ )
        cnt += (s[0][i] != s[1][i]);
    for (int i = 1; i <= q; i ++ )
    {
        int op;
        std::cin >> op;
        cnt += a[i];
        if (op == 1)
        {
            int pos;
            std::cin >> pos;
            pos -- ;
            if (s[0][pos] != s[1][pos])
            {
                cnt -- ;
                if (i + t <= q)
                    a[i + t] ++ ;
            }
        }
        else if (op == 2)
        {
            int x1, y1, x2, y2;
            std::cin >> x1 >> y1 >> x2 >> y2;
            x1 -- , y1 -- , x2 -- , y2 -- ;
            cnt -= (s[0][y1] != s[1][y1]);
            cnt -= (s[0][y2] != s[1][y2]);
            std::swap(s[x1][y1], s[x2][y2]);
            cnt += (s[0][y1] != s[1][y1]);
            cnt += (s[0][y2] != s[1][y2]);
        }
        else
        {
            std::cout << (!cnt ? "Yes" : "No") << "\n";
        }
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

