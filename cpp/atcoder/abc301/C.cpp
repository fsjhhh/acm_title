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

std::string S, T;
std::string c = "atcoder";

void solve()
{
    std::cin >> S >> T;
    int n = S.size();
    
    std::map<char, int> ms, mt; 

    for (int i = 0; i < n; i ++ )
    {
        ms[S[i]] ++ ;
        mt[T[i]] ++ ;
    }

    int a = 0, b = 0, cnt1 = 0, cnt2 = 0;
    for (auto [ct, num] : ms)
    {
        if (ct == '@')
            a = num;
        else
        {
            if (num > mt[ct])
            {
                bool pd = false;
                for (int i = 0; i < c.size(); i ++ )
                {
                    if (ct == c[i])
                    {
                        pd = true;
                        break;
                    }
                }
                if (!pd)
                {
                    std::cout << "No" << "\n";
                    return ;
                }
                cnt1 += (num - mt[ct]);
            }
        }
    }
    for (auto [ct, num] : mt)
    {
        if (ct == '@')
            b = num;
        else
        {
            if (num > ms[ct])
            {
                bool pd = false;
                for (int i = 0; i < c.size(); i ++ )
                {
                    if (ct == c[i])
                    {
                        pd = true;
                        break;
                    }
                }
                if (!pd)
                {
                    std::cout << "No" << "\n";
                    return ;
                }
                cnt2 += (num - ms[ct]);
            }
        }
    }
    if (a - cnt2 == b - cnt1 && a - cnt2 >= 0)
    {
        std::cout << "Yes" << "\n";  
    }
    else
        std::cout << "No" << "\n";
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

