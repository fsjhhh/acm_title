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

template<class T>inline void read(T &res)
{
	char c;
	T flag=1;
	while((c=getchar())<'0'||c>'9')
		if(c=='-')
			flag=-1;res=c-'0';
	while((c=getchar())>='0'&&c<='9')
		res=res*10+c-'0';
	res*=flag;
}

const int N = 3010;
int a[N][N];
LL f[N][N];

void solve()
{
    int n, m;
    read(n);
    read(m);
    for (int i = 1; i <= n; i ++ )
    	for (int j = 1; j <= m; j ++ )
    		read(a[i][j]);

    f[n][1] = 1;
    for (int i = n; i >= 1; i -- )
    	for (int j = 1; j <= m; j ++ )
    	{
    		if (i == n && j == 1)
    			continue;
            if (a[i][j] == 1)
                continue;
    		f[i][j] = (f[i + 1][j] + f[i][j - 1]) % 2333;
    	}
        
    std::cout << f[1][m] << "\n";

}

int main()
{
    IOS;
    int t = 1;
    while (t -- )
        solve();
    return 0;
}
