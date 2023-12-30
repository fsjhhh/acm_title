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

const int N = 2e6 + 10, M = 31 * N;
int ma[M][2], cnt[M], a[N], idx;
LL f[40];

void add(int x) {
	int p = 0;
	for (int i = 30; i >= 0; i--) {
		int u = x >> i & 1;
		if (!ma[p][u]) {
			ma[p][u] = ++ idx;
		}
		p = ma[p][u];
        cnt[p] ++ ;
	}
}

void query(int x) {
    int p = 0;
    for (int i = 30; i >= 0; i--) {
        int u = x >> i & 1;
        if (!ma[p][u]) {
            break;
        }
        p = ma[p][u];
        f[i] += cnt[p];
    }
}

void solve() {
    int n, q;
    std::cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        a[i] ^= a[i - 1];
        for (int j = 30; j >= 0; j--) {
            if (a[i] >> j & 1) {
                break;
            }
            f[j] ++ ;
        }
        query(a[i]);
        add(a[i]);
    }
    
    while (q -- ) {
        int x;
        std::cin >> x;
        std::cout << f[x] << "\n";
    }

}

int main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
