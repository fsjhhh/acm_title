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

const int N = 3e5 + 10;
LL ans = 0;
std::vector<std::vector<int>> edges(N);  
std::vector<int> d(N, 0);
int n, q;

void add(int x)
{
	if (d[x] == 0)
		ans -- ;
	d[x] ++ ;
}

void modify(int x)
{
	if (d[x] == 1)
		ans ++ ;
	d[x] -- ;
}

void solve()
{
    std::cin >> n >> q;
    ans = n;
    std::set<PII> s;
    while (q -- )
    {
    	int op;
    	std::cin >> op;
    	if (op == 1)
    	{
    		int u, v;
    		std::cin >> u >> v;
    		edges[u].push_back(v);
    		edges[v].push_back(u);
    		add(u);
    		add(v);
    		int minn = std::min(u, v);
    		int maxx = std::max(u, v);
    		s.insert({minn, maxx});
    	}
    	else
    	{
    		int u;
    		std::cin >> u;
    		for (auto v : edges[u])
    		{
    			int minn = std::min(u, v);
    			int maxx = std::max(u, v);
                auto it = s.find({minn, maxx});
    			if (it != s.end())
    			{
                    s.erase(it);
    				modify(u);
    				modify(v);
    			}
    		}
            edges[u].clear();
    	}
    	std::cout << ans << "\n";
    }
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

