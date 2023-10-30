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

const int N = 110;
std::vector<int> v[N];

void solve()
{
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; i ++ ) {
		int x;
		std::cin >> x;
		v[i].push_back(x);
		for (int j = 1; j <= x; j ++ ) {
			int y;
			std::cin >> y;
			v[i].push_back(y);
		}
	}
	int x;
	std::cin >> x;
	std::vector<PII> ans;
	for (int i = 1; i <= n; i ++ ) {
		for (int j = 1; j <= v[i][0]; j ++ ) {
			if (v[i][j] == x) {
				ans.push_back({v[i][0], i});
				break;
			}
		}
	}
	std::sort(ans.begin(), ans.end());
	LL res = 0;
	std::set<int> at;
	for (int i = 0; i < ans.size(); i ++ ) {
		if (ans[i].first == ans[0].first) {
			res ++ ;
			at.insert(ans[i].second);
		}
		else {
			break;
		}
	}
	std::cout << res << "\n";
	for (auto it : at) {
		std::cout << it << " ";
	}
	std::cout << "\n";
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