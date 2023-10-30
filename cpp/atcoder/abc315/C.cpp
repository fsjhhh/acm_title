// Problem: C - Flavors
// Contest: AtCoder - KEYENCE Programming Contest 2023 Summer（AtCoder Beginner Contest 315） KEYENCE 编程大赛 2023 年夏季（AtCoder 初学者大赛 315）
// URL: https://atcoder.jp/contests/abc315/tasks/abc315_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms

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

void solve()
{
 	int n;
 	std::cin >> n;
 	std::vector<int> v(n + 1, 0);
 	int ans_1 = 0, ans_2 = 0, maxx = 0;
 	for (int i = 1; i <= n; i ++ ) {
 		int f, s;
 		std::cin >> f >> s;
 		if (v[f] == 0) {
 			v[f] = s;
 		}
 		else {
 			int sum = 0;
 			if (v[f] < s) {
 				sum = s + (v[f] / 2);
 				v[f] = s;
 			}
 			else {
 				sum = v[f] + s / 2;
 			}
 			ans_1 = std::max(sum, ans_1);
 		}
 	}   
 	std::vector<int> m;
 	for (int i = 1; i <= n; i ++ ) {
 		if (v[i]) {
 			m.push_back(v[i]);
 		}
 	}
 	std::sort(m.begin(), m.end());
 	ans_2 = m[m.size() - 1] + m[m.size() - 2];
 	std::cout << std::max(ans_2, ans_1) << "\n";
 	
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