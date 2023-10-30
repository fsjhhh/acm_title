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

const int N = 2e5 + 10;
int a[N], ans;
bool st[N];
int d[N];

void dfs(int u)
{
	if (ans != 0)
		return ;
	if (st[u])
	{
		ans = u;
		return ;
	}
    st[u] = true;
	dfs(a[u]);
}

void solve()
{
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i ++ )
    	std::cin >> a[i];
  	dfs(1);
    // std::cout << ans << "\n";
  	int t = a[ans];
  	int res = 1;
    d[0] = ans;
  	while (t != ans)
  	{
  		d[res ++ ] = t;
  		t = a[t];
  	}
  	std::cout << res << "\n";
  	for (int i = 0; i < res; i ++ )
  		std::cout << d[i] << " \n"[i == res - 1];
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