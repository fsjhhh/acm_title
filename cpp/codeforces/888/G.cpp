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

const int N = 2e5 + 10;
int p[N];
PII h[N];
std::vector<int> tr[N];
bool pd[N];

int find(int u)
{
    if (u != p[u])
        p[u] = find(p[u]);
    return p[u];
}

void add(int a, int b)
{
    int fa = find(a), fb = find(b);
    if (fa == fb)
        return ;
    p[fb] = fa;
}

void solve()
{
    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i ++ )
    {
        std::cin >> h[i].first;
        h[i].second = i;
        p[i] = i;
        tr[i].clear();
    }

    for (int i = 1; i <= m; i ++ )
    {
        int u, v;
        std::cin >> u >> v;
        if (h[u].first < h[v].first) std::swap(u, v);
        tr[u].push_back(v);
    } 

    int q;
    std::cin >> q;
    std::vector<std::pair<PII, PII>> ha(q + 1);
    for (int i = 1; i <= q; i ++ )
    {
        std::cin >> ha[i].second.first >> ha[i].second.second >> ha[i].first.first;
        ha[i].first.first += h[ha[i].second.first].first;
    }
    
    for (int i = 1; i <= q; i ++ )
    {
        ha[i].first.second = i;
    }

    std::sort(h + 1, h + n + 1);
    std::sort(ha.begin() + 1, ha.end());

    int j = 0;

    // for (int i = 1; i <= q; i ++ )
    //     std::cout << ha[i].first.first << " " << ha[i].first.second << " " << ha[i].second.first << " " << ha[i].second.second << "\n";

    // for (int i = 1; i <= n; i ++ )
    //     std::cout << h[i].first << " " << h[i].second << "\n";

    for (auto e : ha)
    {
        while (j <= n && h[j].first <= e.first.first)
        {
            for (auto it : tr[h[j].second])
                add(h[j].second, it);
            j ++ ;
        }
        if (find(e.second.first) == find(e.second.second))
            pd[e.first.second] = true;
        else
            pd[e.first.second] = false;
    }

    for (int i = 1; i <= q; i ++ )
        std::cout << (pd[i] ? "Yes" : "No") << "\n";
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