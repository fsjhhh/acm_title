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

const int N = 1e4 + 10;
std::vector<int> dy[N];
LL d1[N], d2[N], st[N];
LL n, m;
LL dist[N];

void init()
{
    memset(d1, 0, sizeof d1);
    memset(d2, 0, sizeof d2);
    memset(st, 0, sizeof st);
}

bool bfs(int u)
{
    std::queue<LL> q;
    q.push(u);
    st[u] = u;
    while (q.size())
    {
        LL t = q.front();
        q.pop();
        for (auto it : dy[t])
        {
            if (it == u)
                return false;
            if (st[it] == u)
                continue;
            st[it] = u;
            q.push(it);
            d1[it] ++ ;
            d2[u] ++ ;
        }
    }
    return true;
}

void solve()
{
	init();
    std::cin >> n >> m;    
    for (int i = 1; i <= n; i ++ )
    {
        dy[i].clear();
    }
    for (int i = 1; i <= m; i ++ )
    {
    	int a, b;
    	std::cin >> a >> b;
    	dy[a].push_back(b);
    }

    for (int i = 1; i <= n; i ++ )
    {
        if (!bfs(i))
        {
            for (int j = 1; j <= n; j ++ )
                std::cout << "0";
            std::cout << "\n";
            return ;
        }
    }

    // for (int i = 1; i <= n; i ++ )
    //     std::cout << d1[i] << " " << d2[i] << "\n";

    std::string s = "";
    for (int i = 1; i <= n; i ++ )
    {
        if (d1[i] <= n / 2 && d2[i] <= n / 2)
            s += "1";
        else
            s += "0";
    }
    std::cout << s << "\n";

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