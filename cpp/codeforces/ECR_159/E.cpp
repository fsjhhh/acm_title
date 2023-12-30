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
#include <iomanip> // std::fixed std::setprecision(x) 保留x位小数
#include <array>
#include <bitset>
#include <functional>
#include <ranges>
//#include <bits/stdc++.h>
//priority_queue 优先队列
#define IOS                           \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(0);                  \
    std::cout.tie(0);

typedef long long LL;
typedef __int128 i128;
typedef std::pair<int, int> PII;
typedef std::pair<LL, LL> PLL;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;

const int N = 1e6 + 10;
int ma[N][26], cnt[N], idx;

void add_s(std::string str) {
	int p = 0;
	for (int i = 0; i < (int)str.size(); i++) {
		int u = str[i] - 'a';
		if (!ma[p][u]) {
			ma[p][u] = ++ idx;
		}
		p = ma[p][u];
        cnt[p] ++ ;
	}
}

LL find_s(std::string str) {
    std::reverse(str.begin(), str.end());
    int p = 0;
    LL ans = 0;
    for (int i = 0; i < (int)str.size(); i++) {
        int u = str[i] - 'a';
        if (!ma[p][u]) {
            return ans * 2;
        }
        p = ma[p][u];
        ans += cnt[p];
    }
    return ans * 2;
}


void solve() {
    int n;
    std::cin >> n;
    std::vector<std::string> s(n);
    LL sum = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
        sum += s[i].size();
        add_s(s[i]);
    }
   
    LL ans = 0;
    for (int i = 0; i < n; i++) {
        LL k = find_s(s[i]);
        LL w = sum + s[i].size() * n;
        ans += (w - k);
    }
    std::cout << ans << "\n";


}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
