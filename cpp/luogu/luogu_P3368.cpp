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

const int N = 5e5 + 10;
int n;
int tr[N];

int lowbit(int x) {
    return x & (-x);
}

void modify(int u, int x) {
    for (int i = u; i <= n; i += lowbit(i)) {
        tr[i] += x;
    }
}

int query(int u) {
    int ans = 0;
    for (int i = u; i; i -= lowbit(i)) {
        ans += tr[i];
    }
    return ans;
}

void solve() {
    int q;
    std::cin >> n >> q;
    std::vector<int> a(n + 1);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        // modify(i + 1, a);
    }

    while (q -- ) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int l, r, x;
            std::cin >> l >> r >> x;
            modify(l, x);
            modify(r + 1, -x);
        } else {
            int x;
            std::cin >> x;
            std::cout << query(x) + a[x - 1] << "\n";
        }
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
