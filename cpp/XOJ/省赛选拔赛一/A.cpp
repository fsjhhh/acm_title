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

const int N = 5;
std::map<std::string, int> mp = {{"Monday", 1}, {"Tuesday", 2}, {"Wednesday", 3}, {"Thursday", 4}, {"Friday", 5}};
std::map<int, std::string> m = {{0, "Monday"}, {1, "Tuesday"}, {2, "Wednesday"}, {3, "Thursday"}, {4, "Friday"}};

void solve()
{
    LL y1, m1, d1, y2, m2, d2;
    std::string s;
    std::cin >> y1 >> m1 >> d1 >> s;
    std::cin >> y2 >> m2 >> d2;
    LL day1 = (y1 * 12 + m1) * 30 + d1;
    LL day2 = (y2 * 12 + m2) * 30 + d2;
    if (day1 > day2)
    {
        LL de = day1 - day2;
        if (de <= mp[s])
        {
            de = mp[s] - de;
            if (de == 0)
                de = 4;
            else
                de = de - 1;
            std::cout << m[de] << "\n";
        }
        else
        {
            de -= mp[s];
            de %= 5;
            de = 5 - de;
            if (de == 0)
                de = 4;
            else
                de = de - 1;
            std::cout << m[de] << "\n";
        }
    }
    else
    {
        LL de = day2 - day1;
        de = (de + mp[s]) % 5;
        if (de == 0)
            de = 4;
        else
            de = de - 1;
        std::cout << m[de] << "\n";
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