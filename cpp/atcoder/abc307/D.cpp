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

std::string s;

const int N = 2e5 + 10;
char str[N];
int a[N], cnt, idx;

void solve()
{
	int n;
	std::cin >> n >> s;
	for (int i = 0; i < s.size(); i ++ )
	{
		str[idx ++ ] = s[i];
		if (s[i] == '(')
			a[cnt ++ ] = idx;
		if (s[i] == ')')
		{
			if (cnt == 0)
				continue;
			idx = a[cnt - 1] - 1;
			cnt -- ;
		}
	}
	for (int i = 0; i < idx; i ++ )
		std::cout << str[i];
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

