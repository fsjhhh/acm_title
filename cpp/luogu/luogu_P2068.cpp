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

#define int long long

const int N = 5e5 + 10;
int n, q;
int tr[N];

int lowbit(int x) {
    // lowbit返回x二进制最后一个1的位置
    // 树状数组中x + lowbit(x) 是x父节点的位置 
    return x & (-x);
}

void modify(int u, int x) {
    // 修改u以及u的负节点（单点修改）
    for (int i = u; i <= n; i += lowbit(i)) {
        tr[i] += x;
    }
}

int query(int u) {
    int ans = 0;
    // 查询u以及u的子节点
    for (int i = u; i; i -= lowbit(i)) {
        ans += tr[i];
    }
    return ans;
}

void solve() {
    std::cin >> n >> q;
    while (q -- ) {
        char op;
        std::cin >> op;
        if (op == 'x') {
            int l, r;
            std::cin >> l >> r;
            modify(l, r);
            // modify(r + 1, -1);
        } else {
            int x, y;
            std::cin >> x >> y;
            int t = query(y) - query(x - 1);
            std::cout << t << "\n";
        }
    }
}

signed main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}

