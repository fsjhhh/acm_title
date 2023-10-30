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

LL a, p;
LL ans = 0;

LL power(LL a, LL b)
{
    LL res = 1;
    while (b)
    {
        if (b & 1) res = res * a % (1 << p);
        a = a * a % (1 << p);
        b >>= 1;
    }
    return res;
}

void solve()
{
    ans = 0;
    std::cin >> a >> p;
    if (a % 2)
    {
        std::cout << 1 << "\n";
        return ;
    }
    LL l = p, r = (1 << p);
    for (int i = 1; i < p; i ++ )
    {
        if (power(a, i) == power(i, a))
        {
            ans ++ ;
        }
    }
    LL k = (p + a - 1) / a;
    ans += ((1 << (p - k)) - (p - 1) / (1 << k));
    std::cout << ans << "\n";
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