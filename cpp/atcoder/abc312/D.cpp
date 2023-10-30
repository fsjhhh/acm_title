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

const int N = 3010, mod = 998244353;
LL f[N][N];

void solve()
{
   	std::string s;
   	std::cin >> s;
   	s = " " + s;
   	f[0][0] = 1;
   	for (int i = 1; i < s.size(); i ++ ) {
   		for (int j = 0; j < s.size(); j ++ ) {
   			if (s[i] == '(') {
   				if (j == 0) {
   					continue;
   				}
   				else {
   					f[i][j] = f[i - 1][j - 1];
   				}
   			}
   			if (s[i] == ')') {
   				if (j == s.size() - 1) {
   					continue;
   				}
   				else {
   					f[i][j] = f[i - 1][j + 1];
   				}
   			}
   			if (s[i] == '?') {
   				if (j) {
   					f[i][j] = (f[i][j] + f[i - 1][j - 1]) % mod;
   				}
   				if (j != s.size() - 1) {
   					f[i][j] = (f[i][j] + f[i - 1][j + 1]) % mod;
   				}
   			}
   		}
   	}

   	std::cout << f[s.size() - 1][0] << "\n";
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