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

#define int long long

struct Node {
    int l, r;
    int sum;
    int lmn, rmx;
    int lans, rans;
    int segans;
    int ans;
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
        res.lmn = std::min(x.lmn, x.sum + y.lmn);
        res.rmx = std::max(x.rmx + y.sum, y.rmx);
        res.lans = std::max({x.lans, x.sum - y.lmn, x.segans - y.lmn, x.sum + y.lans});
        res.rans = std::max({y.rans, x.rmx - y.sum, x.rmx + y.segans, x.rans - y.sum});
        res.segans = std::max({x.sum - y.sum, x.segans - y.sum, x.sum + y.segans});
        res.ans = std::max({x.rans - y.lmn, x.rmx + y.lans, x.ans, y.ans, x.rmx - y.lmn});
    }

    void push_up(int u) {
        merge_node(tr[u], tr[u << 1], tr[u << 1 | 1]);
    }

    void build(int u, int l, int r, std::vector<int>& w) {
        if (l == r) {
            tr[u].l = tr[u].r = r;
            tr[u].sum = tr[u].lmn = tr[u].rmx = w[l];
            tr[u].lans = tr[u].rans = tr[u].segans = tr[u].ans = -INFL;
            return ;
        }
        tr[u].l = l;
        tr[u].r = r;
        int mid = (l + r) >> 1;
        build(u << 1, l, mid, w);
        build(u << 1 | 1, mid + 1, r, w);
        push_up(u);
    }

    void modify(int u, int l, int r, int x) {
        if (l <= tr[u].l && r >= tr[u].r) {
            tr[u].sum = tr[u].lmn = tr[u].rmx = x;
            tr[u].lans = tr[u].rans = tr[u].segans = tr[u].ans = -INFL;
            return ;
        }
        // push_down(u); // 单点修改可去掉
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (l <= mid) {
            modify(u << 1, l, r, x);
        }
        if (r > mid) {
            modify(u << 1 | 1, l, r, x);
        }
        push_up(u);
    }

    Node query(int u, int l, int r) {
        if (l <= tr[u].l && r >= tr[u].r) {
            return tr[u];
        }
        // push_down(u); /// 单点修改可去掉
        bool ok = false;
        int mid = (tr[u].l + tr[u].r) >> 1;
        Node ans;
        if (l <= mid) {
            ok = true;
            ans = query(u << 1, l, r);
        }
        if (r > mid) {
            if (!ok) {
                ans = query(u << 1 | 1, l, r);
            } else {
                Node res = query(u << 1 | 1, l, r);
                merge_node(ans, ans, res);
            }
        }
        push_up(u);
        return ans;
    }

};


void solve() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    SegmentTree tr(n + 1);
    tr.build(1, 1, n, a);
    while (q -- ) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int x, y;
            std::cin >> x >> y;
            tr.modify(1, x, x, y);
        } else {
            int l, r;
            std::cin >> l >> r;
            Node res = tr.query(1, l, r);
            std::cout << res.ans << "\n";
        }
    }
}

signed main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
