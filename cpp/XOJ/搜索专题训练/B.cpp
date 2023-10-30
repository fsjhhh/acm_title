#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
// #include <unordered_map>
#include <set>
// #include <unordered_set>
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

const int N = 10010;
struct que
{
	int q_a, q_b, q_s, rev, ans;
} q[N];
bool st[N][N];
int a, b, c, ha = 0, li = 1;

void print(int x)
{
	if (q[x].rev)
		print(q[x].rev);
	if (q[x].q_s == 1)
		std::cout << "FILL(1)" << "\n";
	if (q[x].q_s == 2)
		std::cout << "FILL(2)" << "\n";
	if (q[x].q_s == 3)
		std::cout << "DROP(1)" << "\n";
	if (q[x].q_s == 4)
		std::cout << "DROP(2)" << "\n";
	if (q[x].q_s == 5)
		std::cout << "POUR(1,2)" << "\n";
	if (q[x].q_s == 6)
		std::cout << "POUR(2,1)" << "\n";
}

void bfs()
{
	q[li] = {0, 0, 0, 0, 0};
	while (ha <= li)
	{
		que t1 = q[++ ha ];
		if (st[t1.q_a][t1.q_b])
			continue;
		st[t1.q_a][t1.q_b] = true;
		if (t1.q_a == c || t1.q_b == c)
		{
			std::cout << t1.ans << "\n";
			print(ha);
			return ;
		}
		for (int i = 1; i <= 6; i ++ )
		{
			que t = q[ha];
			if (i == 1) // a -> a
			{
				if (t.q_a == a)
					continue;
				t.q_a = a;
				t.q_s = i;
				t.rev = ha;
				t.ans ++ ;
			}
			else if (i == 2) // b -> b
			{
				if (t.q_b == b)
					continue;
				t.q_b = b;
				t.q_s = i;
				t.rev = ha;
				t.ans ++ ;
			}
			else if (i == 3) // a -> 0
			{
				if (!t.q_a)
					continue;
				t.q_a = 0;
				t.q_s = i;
				t.rev = ha;
				t.ans ++ ;
			}
			else if (i == 4) // b -> 0
			{
				if (!t.q_b)
					continue;
				t.q_b = 0;
				t.q_s = i;
				t.rev = ha;
				t.ans ++ ;
			}
			else if (i == 5) // a -> b
			{
				if (!t.q_a || t.q_b == b)
					continue;
				if (b - t.q_b >= t.q_a)
				{
					t.q_b = t.q_a + t.q_b;
					t.q_a = 0;
				}
				else
				{
					t.q_a = t.q_a - (b - t.q_b);
					t.q_b = b;
				}
				t.q_s = i;
				t.rev = ha;
				t.ans ++ ;
			}
			else // b -> a
			{
				if (!t.q_b || t.q_a == a)
					continue;
				if (a - t.q_a >= t.q_b)
				{
					t.q_a = t.q_a + t.q_b;
					t.q_b = 0;
				}
				else
				{
					t.q_b = t.q_b - (a - t.q_a);
					t.q_a = a;
				}
				t.q_s = i;
				t.rev = ha;
				t.ans ++ ;
			}
			q[++ li] = t;
		}
		
	}
	std::cout << "impossible" << "\n";
}

void solve()
{
    std::cin >> a >> b >> c;
    bfs();
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

