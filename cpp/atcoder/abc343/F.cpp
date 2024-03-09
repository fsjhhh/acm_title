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
    LL mx1 = 0;
    LL num1 = 0;
    LL mx2 = 0;
    LL num2 = 0;
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
        if (x.mx1 == y.mx1) {
            res.mx1 = x.mx1;
            res.num1 = x.num1 + y.num1;
            if (x.mx2 > y.mx2) {
                res.mx2 = x.mx2;
                res.num2 = x.num2;
            } else if (x.mx2 < y.mx2) {
                res.mx2 = y.mx2;
                res.num2 = y.num2;
            } else {
                res.mx2 = x.mx2;
                res.num2 = x.num2 + y.num2;
            }
        } else if (x.mx1 < y.mx1) {
            res.mx1 = y.mx1;
            res.num1 = y.num1;
            if (x.mx1 > y.mx2) {
                res.mx2 = x.mx1;
                res.num2 = x.num1;
            } else if (x.mx1 < y.mx2) {
                res.mx2 = y.mx2;
                res.num2 = y.num2;
            } else {
                res.mx2 = x.mx1;
                res.num2 = x.num1 + y.num2;
            }
        } else {
            res.mx1 = x.mx1;
            res.num1 = x.num1;
            if (y.mx1 > x.mx2) {
                res.mx2 = y.mx1;
                res.num2 = y.num1;
            } else if (y.mx1 < x.mx2) {
                res.mx2 = x.mx2;
                res.num2 = x.num2;
            } else {
                res.mx2 = y.mx1;
                res.num2 = y.num1 + x.num2;
            }
        }
    }

    void push_up(int u) {
        merge_node(tr[u], tr[u << 1], tr[u << 1 | 1]);
    }

    void build(int u, int l, int r, std::vector<int>& w) { // 建树区间为[l, r)
        tr[u].l = l;
        tr[u].r = r;
        if (r - l == 1) {
            tr[u].mx1 = w[l];
            tr[u].num1 = 1;
            tr[u].mx2 = 0;
            tr[u].num2 = 0;
            return ;
        }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid, w);
        build(u << 1 | 1, mid, r, w);
        push_up(u);
    }

    void modify(int u, int l, int r, int x) { // 修改区间为[l, r)
        if (tr[u].l >= r || tr[u].r <= l) {
            return ;
        }
        if (tr[u].l >= l && tr[u].r <= r) {
            tr[u].mx1 = x;
            tr[u].num1 = 1;
            tr[u].mx2 = 0;
            tr[u].num2 = 0;
            return ;
        }
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
        Node ans;
        merge_node(ans, query(u << 1, l, r), query(u << 1 | 1, l, r));
        push_up(u);
        return ans;
    }

};

void solve() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    SegmentTree sg(n);

    sg.build(1, 0, n, a);

    while (q -- ) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int p, x;
            std::cin >> p >> x;
            p -- ;
            sg.modify(1, p, p + 1, x);
        } else {
            int l, r;
            std::cin >> l >> r;
            l -- ;
            Node ans = sg.query(1, l, r);
            std::cout << ans.num2 << "\n";
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
