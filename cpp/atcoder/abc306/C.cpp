// Problem: C - Centers
// Contest: AtCoder - Toyota Programming Contest 2023#3（AtCoder Beginner Contest 306）
// URL: https://atcoder.jp/contests/abc306/tasks/abc306_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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

const int N = 1e5 + 10;
int a[3 * N], b[N];
PII c[N];

void solve()
{
	int n;
	std::cin >> n;
	for (int i = 1; i <= 3 * n; i ++ ) {
		std::cin >> a[i];
		b[a[i]] ++ ;
		if (b[a[i]] == 2) {
			c[a[i]] = {i, a[i]};
		}
	}
	
	std::sort(c + 1, c + n + 1);
	
	for (int i = 1; i <= n; i ++ ) {
		std::cout << c[i].second << " \n"[i == n];
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