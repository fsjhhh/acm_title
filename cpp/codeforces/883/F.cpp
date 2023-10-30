// Problem: F. Rudolph and Mimic F.鲁道夫和模仿者
// Contest: Codeforces - Codeforces Round 883 (Div. 3)Codeforces 第 883 轮（第 3 部分）
// URL: https://codeforces.com/contest/1846/problem/F
// Memory Limit: 256 MB
// Time Limit: 1000 ms

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

const int N = 210;

void solve()
{
 	int n;
 	std::cin >> n;
 	std::vector<int> cnt(10);
 	std::vector<int> a(n + 1);
 	for (int i = 1; i <= n; i ++ ) {
 		std::cin >> a[i];
 		cnt[a[i]] ++ ;
 	}
 	
 	int inv = -1;
 	while (1) {
 		std::cout << "- 0" << "\n";
 		std::cout.flush();
 		std::vector<int> cnt2(10);
 		for (int i = 1; i <= n; i ++ ) {
 			std::cin >> a[i];
 			cnt2[a[i]] ++ ;
 		}
 		
 		for (int i = 1; i <= 9; i ++ ) {
 			if (cnt2[i] > cnt[i]) {
 				inv = i;
 				break;		
 			}
 		}
 		if (inv != -1) {
 			break;
 		}
 	}
 	
 	std::vector<int> v;
 	std::vector<int> v1;
 	for (int i = 1; i <= n; i ++ ) {
 		if (a[i] != inv) {
 			v.push_back(i);
 		}
 		else {
 			v1.push_back(a[i]);
 		}
 	}
 	
 	std::cout << "- " << v.size();
 	for (auto u : v) {
 		std::cout << " " << u;
 	}
 	std::cout << "\n";
 	std::cout.flush();
 	
 	n -= v.size();
 	while (1) {
 		for (auto &t : v1) {
 			std::cin >> t;
 		}
 		
 		if (n == 1) {
 			std::cout << "! 1" << "\n";
 			std::cout.flush();
 			return ;
 		}
 		
 		for (int i = 0; i < v1.size(); i ++ ) {
 			if (v1[i] != inv) {
 				std::cout << "! " << i + 1 << "\n";
 				std::cout.flush();
 				return ;
 			}
 		}
 		std::cout << "- 0" << "\n";
 		std::cout.flush();
 	}
 	
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