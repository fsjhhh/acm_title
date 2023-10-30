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
#include <stack>
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
std::string s;
int a[N];

void solve()
{
	int n;
	std::cin >> n >> s;
    int num = 0;
    for (int i = 0; i < n; i ++ )
        if (s[i] == '(')
            num ++ ;
    if (2 * num != n)
    {
        std::cout << -1 << "\n";
        return ;
    }

    std::stack<std::pair<char, int>> sta;
    for (int i = 0; i < n; i ++ )
    {
        if (s[i] == s[0])
            sta.push({s[i], i});
        else
        {
            if (!sta.size())
                a[i] = 2;
            else
            {
                auto t = sta.top();
                sta.pop();
                a[t.second] = 1;
                a[i] = 1;
            }
        }
    }

    while (sta.size())
    {
        auto t = sta.top();
        sta.pop();
        a[t.second] = 2;
    }

    int ans = 0;
    for (int i = 0; i < n; i ++ )
        ans += a[i];

    if (ans == n || ans == 2 * n)
    {
        std::cout << 1 << "\n";
        for (int i = 0; i < n; i ++ )
            std::cout << 1 << " \n"[i == n - 1];
    }
    else
    {
        std::cout << 2 << "\n";
        for (int i = 0; i < n; i ++ )
            std::cout << a[i] << " \n"[i == n - 1];
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

