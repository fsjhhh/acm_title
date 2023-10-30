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
// priority_queue 优先队列
using namespace std;
#define IOS                           \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(0);                  \
    std::cout.tie(0);

typedef long long LL;
typedef std::pair<int, int> PII;
typedef std::pair<LL, LL> PLL;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;

LL t, ans, a[4];
string str, mp[4] = {"GB", "MB", "KB", "B"};

void solve()
{
    cin >> t;
    getchar();
    while (t--)
    {
        getline(cin, str);
        if (str[0] == 'i' || str[0] == 'l')
        {
            bool pd = true;
            LL m = 0, num = 0;
            if (str[0] == 'i')
                m = 4;
            if (str[0] == 'l')
                m = 8;
            for (LL i = 0; i < str.size(); i++)
            {
                if (str[i] == '[')
                {
                    pd = false;
                    LL con = 0;
                    for (LL j = i + 1; str[j] != ']'; j++)
                        con = con * 10 + str[j] - '0';
                    ans += con * m;
                }
                if (str[i] == '=')
                    num++;
            }
            if (pd)
                ans += num * m;
        }
        else
        {
            for (LL i = 0; i < str.size(); i++)
            {
                if (str[i] == '"' && str[i - 1] == '=')
                    for (LL j = i + 1; str[j] != '"'; j++)
                        ans++;
            }
        }
    }
    LL cur = 4;
    while (ans)
    {
        a[--cur] = ans % 1024;
        ans /= 1024;
    }
    for (LL i = 0; i < 4; i++)
    {
        if (a[i])
            cout << a[i] << mp[i];
    }
}

int main()
{
    // IOS;
    int t = 1;
    while (t--)
        solve();
    return 0;
}