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
const int mod = 1e9 + 7;

struct Node {
    int l, r;
    int l_z, r_z;
    int ans;
    int lazy;
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
        res.lazy = 0;
        res.ans = (x.ans + y.ans) % mod;
        res.l_z = x.l_z;
        res.r_z = y.r_z;
        if (x.l_z == x.ans) {
            res.l_z = (res.l_z + y.l_z) % mod;
        }
        if (y.r_z == y.ans && y.l_z) {
            res.r_z = (res.r_z + x.r_z) % mod;
        }
        if (x.lazy) {
            res.lazy = (res.lazy + x.lazy) % mod;
        }
        if (y.lazy) {
            res.ans = (x.ans + y.ans + x.r_z * y.lazy % mod) % mod;
            if (x.l_z == x.ans) {
                res.lazy = (res.lazy + y.lazy + x.lazy * y.lazy % mod) % mod;
                res.l_z = (res.l_z + x.ans * y.lazy % mod) % mod;
            }
            if (y.r_z == y.ans) {
                res.r_z = (res.r_z + x.r_z * y.lazy % mod) % mod;
            }
        }
    }

    void push_up(int u) {
        merge_node(tr[u], tr[u << 1], tr[u << 1 | 1]);
    }

    void build(int u, int l, int r, std::vector<int>& w) {
        if (l == r) {
            tr[u].l = tr[u].r = r;
            tr[u].ans = 1;
            tr[u].lazy = 0;
            if (w[l] == (int)'Y') {
                tr[u].l_z = 1;
                tr[u].r_z = 1;
            } else if (w[l] == (int)'B') {
                tr[u].l_z = 0;
                tr[u].r_z = 1;
            } else {
                tr[u].l_z = 1;
                tr[u].r_z = 1;
                tr[u].lazy = 1;
            }
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
            if (x == (int)'Y') {
                tr[u].lazy = 0;
                tr[u].l_z = 1;
                tr[u].r_z = 1;
            } else if (x == (int)'B') {
                tr[u].lazy = 0;
                tr[u].l_z = 0;
                tr[u].r_z = 1;
            } else {
                tr[u].l_z = 1;
                tr[u].r_z = 1;
                tr[u].lazy = 1;
            }
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
    std::string s;
    std::cin >> s;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = s[i - 1];
    }
    SegmentTree sg(n);
    sg.build(1, 1, n, a);

    while (q -- ) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int p;
            char c;
            std::cin >> p >> c;
            sg.modify(1, p, p, (int)c);
        } else {
            int l, r;
            std::cin >> l >> r;
            std::cout << sg.query(1, l, r).ans << "\n";
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
