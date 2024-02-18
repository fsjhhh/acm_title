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
    int l, r;
    int maxx, minn;
    int mx, mi;
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
        res.maxx = std::max(x.maxx, y.maxx);
        res.minn = std::min(x.minn, y.minn);
        if (x.maxx >= y.maxx) {
            res.mx = x.mx;
        } else {
            res.mx = y.mx;
        }
        if (x.minn <= y.minn) {
            res.mi = x.mi;
        } else {
            res.mi = y.mi;
        }
    }

    void push_up(int u) {
        merge_node(tr[u], tr[u << 1], tr[u << 1 | 1]);
    }

    void build(int u, int l, int r, std::vector<int>& w) {
        if (l == r) {
            tr[u].l = tr[u].r = r;
            tr[u].lazy = 0;
            tr[u].maxx = tr[u].minn = w[l];
            tr[u].mx = tr[u].mi = l;
            return ;
        }
        tr[u].l = l;
        tr[u].r = r;
        tr[u].lazy = 0;
        int mid = (l + r) >> 1;
        build(u << 1, l, mid, w);
        build(u << 1 | 1, mid + 1, r, w);
        push_up(u);
    }

    Node query(int u, int l, int r) {
        if (l <= tr[u].l && r >= tr[u].r) {
            return tr[u];
        }
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
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    SegmentTree tr(n);

    tr.build(1, 1, n, a);

    int q;
    std::cin >> q;
    while (q -- ) {
        int l, r;
        std::cin >> l >> r;
        auto ans = tr.query(1, l, r);
        if (ans.maxx == ans.minn) {
            std::cout << -1 << " " << -1 << "\n";
        } else {
            std::cout << ans.mi << " " << ans.mx << "\n";
        }
    }

}

int main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
