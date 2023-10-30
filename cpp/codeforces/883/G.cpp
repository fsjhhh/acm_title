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

const int N = 1e3 + 10;

struct node
{
    int w;
    std::string good, bad;
} a[N];

struct dist
{
    int d;
    std::string s;
    bool operator<(const dist& a) const
    {
        return d > a.d;
    }
};

void solve()
{
    std::map<std::string, int> ma;
    int n, m;
    std::cin >> n >> m;
    std::string str;
    std::cin >> str;
    for (int i = 1; i <= m; i ++ )
        std::cin >> a[i].w >> a[i].good >> a[i].bad;
    std::priority_queue<dist> q;
    std::string ans;
    for (int i = 0; i < n; i ++ )
        ans += '0';
    q.push({0, str});
    while (q.size())
    {
        auto t = q.top();
        int dis = t.d;
        std::string now = t.s;
        q.pop();
        if (now == ans)
        {
            std::cout << dis << "\n";
            return ;
        }
        for (int i = 1; i <= m; i ++ )
        {
            std::string cop;
            for (int j = 0; j < n; j ++ )
            {
                if (a[i].good[j] == '1')
                    cop += '0';
                else if (a[i].bad[j] == '1' || now[j] == '1')
                    cop += '1';
                else
                    cop += '0';
            }
            if (ma.find(cop) == ma.end())
            {
                q.push({dis + a[i].w, cop});
                ma[cop] = dis + a[i].w;
            }
            else
            {
                if (ma[cop] > dis + a[i].w)
                {
                    ma[cop] = dis + a[i].w;
                    q.push({dis + a[i].w, cop});
                }
            }
        }
    }
    std::cout << -1 << "\n";
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