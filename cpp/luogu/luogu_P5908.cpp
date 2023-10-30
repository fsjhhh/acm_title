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
#define IOS                           \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(0);                  \
    std::cout.tie(0);

typedef long long LL;
typedef std::pair<int, int> PII;
typedef std::pair<LL, LL> PLL;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;

const int N = 1e5 + 10, M = 2e5 + 10;
int h[N], e[M], ne[M], idx;
int dist[N];
bool st[N];
int n, d;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void bfs()
{
    std::queue<int> q;
    q.push(1);
    dist[1] = 0;
    st[1] = true;
    int ans = 0, res = 0;
    while (1)
    {
        res++;
        int m = q.size();
        if (m == 0)
            break;
        for (int i = 0; i < m; i++)
        {
            int t = q.front();
            q.pop();
            for (int i = h[t]; i != -1; i = ne[i])
            {
                int x = e[i];
                if (!st[x])
                {
                    dist[x] = dist[t] + 1;
                    st[x] = true;
                    ans++;
                    q.push(x);
                }
            }
        }
        if (res == d)
            break;
    }
    std::cout << ans << std::endl;
}

void solve()
{
    memset(h, -1, sizeof h);
    std::cin >> n >> d;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        std::cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    bfs();
}

int main()
{
    IOS;
    int t = 1;
    while (t--)
        solve();
    return 0;
}