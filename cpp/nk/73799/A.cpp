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
#include <iomanip> // std::fixed std::setprecision(x) 保留x位小数
#include <array>
#include <bitset>
#include <functional>
#include <ranges>
// #include <bits/stdc++.h>
// priority_queue 优先队列
// std::cout.flush(); 交互题
#define IOS                           \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(0);                  \
    std::cout.tie(0);

typedef long long LL;
typedef __int128 i128;
typedef std::pair<int, int> PII;
typedef std::pair<LL, LL> PLL;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;

#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 4010;
int h[N], e[N], ne[N], w[N], idx; // 邻接表
LL dist[N];
bool st[N];
int n, p, c, a[N];

struct node {
    int d, p;
    
    bool operator<(const node a) const {
        if (this -> d == a.d) {
            return this -> p > a.p;
        }
        return this -> d > a.d;
    }
    
};

void add(int a, int b, int c) // 邻接表加边
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

void dijkstra(int x)
{
    memset(dist, 0x3f, sizeof dist); // 初始化距离为正无穷
    memset(st, 0, sizeof st);
    dist[x] = 0;
    priority_queue<node> q; // 定义小根堆存储距离与点(优先队列)
    q.push({0, x});
    
    while (q.size())
    {
        auto t = q.top(); // 取出堆顶 
        q.pop();
        int di = t.d, ver = t.p; // 取出距离与点
        
        if (st[ver]) continue;
        st[ver] = true;
        
        for (int i = h[ver]; i != -1; i = ne[i]) // 遍历邻接表
        {
            int j = e[i];
            if (dist[j] > di + w[i])
            {
                dist[j] = di + w[i];
                q.push({dist[j], j});
            }
        }
        
    }
    
}

void solve() {
	memset(h, -1, sizeof h);
	std::cin >> n >> p >> c;
	for (int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		a[x] ++ ;
	}
	for (int i = 0; i < c; i++) {
		int a, b, c;
		std::cin >> a >> b >> c;
		add(a, b, c);
		add(b, a, c);
	}

	LL ans = INFL;
	for (int i = 1; i <= p; i++) {
		dijkstra(i);
		LL sum = 0;
		for (int j = 1; j <= p; j++) {
			sum += a[j] * dist[j];
		}
		ans = std::min(ans, sum);
	}

	std::cout << ans << "\n";

}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}