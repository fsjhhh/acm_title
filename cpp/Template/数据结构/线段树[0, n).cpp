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
// #include <bits/stdc++.h>
// priority_queue 优先队列
// std::cout.flush(); 交互题
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

struct Node {
    int l, r; // 区间为[l, r)
    LL sum = 0;
    LL lazy = 0;
};

struct SegmentTree {
    std::vector<Node> tr;

    SegmentTree() {}
    SegmentTree(int n) {
        init(n);
    }

    void init(int n) {
        tr.resize(4 * (n + 1));
    }

    void merge_node(Node& res, Node x, Node y) {
        res.sum = x.sum + y.sum;
    }

    void push_up(int u) {
        merge_node(tr[u], tr[u << 1], tr[u << 1 | 1]);
    }

    void build(int u, int l, int r, std::vector<int>& w) { // 建树区间为[l, r)
        tr[u].l = l;
        tr[u].r = r;
        if (r - l == 1) {
            tr[u].lazy = 0;
            tr[u].sum = w[l];
            return ;
        }
        tr[u].lazy = 0;
        int mid = (l + r) >> 1;
        build(u << 1, l, mid, w);
        build(u << 1 | 1, mid, r, w);
        push_up(u);
    }

    void push_down(int u) {
        if (!tr[u].lazy) {
            return ;
        }
        tr[u << 1].lazy += tr[u].lazy;
        tr[u << 1].sum += tr[u].lazy * (tr[u << 1].r - tr[u << 1].l);
        tr[u << 1 | 1].lazy += tr[u].lazy;
        tr[u << 1 | 1].sum += tr[u].lazy * (tr[u << 1 | 1].r - tr[u << 1 | 1].l);
        tr[u].lazy = 0;
    }

    void modify(int u, int l, int r, int x) { // 修改区间为[l, r)
        if (tr[u].l >= r || tr[u].r <= l) {
            return ;
        }
        if (tr[u].l >= l && tr[u].r <= r) {
            tr[u].lazy += x;
            tr[u].sum += x * (tr[u].r - tr[u].l);
            return ;
        }
        push_down(u); // 单点修改可去掉
        modify(u << 1, l, r, x);
        modify(u << 1 | 1, l, r, x);
        push_up(u);
    }

    Node query(int u, int l, int r) { // 查询区间为[l, r)
        if (tr[u].l >= r || tr[u].r <= l) {
            return Node();
        }
        if (l <= tr[u].l && r >= tr[u].r) {
            return tr[u];
        }
        push_down(u); // 单点修改可去掉
        Node ans;
        merge_node(ans, query(u << 1, l, r), query(u << 1 | 1, l, r));
        push_up(u);
        return ans;
    }

};

void solve() {
    int n, m;
    std::cin >> n >> m;
    SegmentTree tr(n + 1);
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    tr.build(1, 0, n, a);

    while (m -- ) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int x, y, k;
            std::cin >> x >> y >> k;
            x -- ;
            tr.modify(1, x, y, k);
        } else {
            int x, y;
            std::cin >> x >> y;
            x -- ;
            Node res = tr.query(1, x, y);
            std::cout << res.sum << "\n";
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

