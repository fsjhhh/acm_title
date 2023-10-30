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
LL a[N], b[N];
PLL t[N];

void solve()
{
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i ++ ) {
		std::cin >> a[i];
	} 
	for (int i = 1; i <= n; i ++ ) {
		std::cin >> b[i];
		t[i] = {a[i] - b[i], i};
	}
	std::sort(t + 1, t + n + 1);
	LL x = t[n].first;
	std::vector<int> v;
	for (int i = n; i >= 1; i -- ) {
		if (t[i].first == x) {
			v.push_back(t[i].second);
		}
		if (t[i].first < x) {
			break;
		}
	}
	std::sort(v.begin(), v.end());
	std::cout << v.size() << "\n";
	for (auto it : v) {
		std::cout << it << " ";
	}
	std::cout << "\n";
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