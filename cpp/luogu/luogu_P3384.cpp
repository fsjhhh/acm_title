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

struct HLD {
    int n;
    std::vector<int> siz, top, dep, parent, in, out, seq;
    std::vector<std::vector<int>> adj;
    int cur;
    
    HLD() {}
    HLD(int n) {
        init(n);
    }
    void init(int n) {
        this->n = n;
        siz.resize(n);
        top.resize(n);
        dep.resize(n);
        parent.resize(n);
        in.resize(n);
        out.resize(n);
        seq.resize(n);
        cur = 0;
        adj.assign(n, {});
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void work(int root = 0) {
        top[root] = root;
        dep[root] = 0;
        parent[root] = -1;
        dfs1(root);
        dfs2(root);
    }
    void dfs1(int u) {
        if (parent[u] != -1) {
            adj[u].erase(std::find(adj[u].begin(), adj[u].end(), parent[u]));
        }
        
        siz[u] = 1;
        for (auto &v : adj[u]) {
            parent[v] = u;
            dep[v] = dep[u] + 1;
            dfs1(v);
            siz[u] += siz[v];
            if (siz[v] > siz[adj[u][0]]) {
                std::swap(v, adj[u][0]);
            }
        }
    }
    void dfs2(int u) {
        in[u] = cur++;
        seq[in[u]] = u;
        for (auto v : adj[u]) {
            top[v] = v == adj[u][0] ? top[u] : v;
            dfs2(v);
        }
        out[u] = cur;
    }
    int lca(int u, int v) {
        while (top[u] != top[v]) {
            if (dep[top[u]] > dep[top[v]]) {
                u = parent[top[u]];
            } else {
                v = parent[top[v]];
            }
        }
        return dep[u] < dep[v] ? u : v;
    }
    
    int dist(int u, int v) {
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    }
    
    int jump(int u, int k) {
        if (dep[u] < k) {
            return -1;
        }
        
        int d = dep[u] - k;
        
        while (dep[top[u]] > d) {
            u = parent[top[u]];
        }
        
        return seq[in[u] - dep[u] + d];
    }
    
    bool isAncester(int u, int v) {
        return in[u] <= in[v] && in[v] < out[u];
    }
    
    int rootedParent(int u, int v) {
        std::swap(u, v);
        if (u == v) {
            return u;
        }
        if (!isAncester(u, v)) {
            return parent[u];
        }
        auto it = std::upper_bound(adj[u].begin(), adj[u].end(), v, [&](int x, int y) {
            return in[x] < in[y];
        }) - 1;
        return *it;
    }
    
    int rootedSize(int u, int v) {
        if (u == v) {
            return n;
        }
        if (!isAncester(v, u)) {
            return siz[v];
        }
        return n - siz[rootedParent(u, v)];
    }
    
    int rootedLca(int a, int b, int c) {
        return lca(a, b) ^ lca(b, c) ^ lca(c, a);
    }
};

struct Node {
    int l, r; // 区间为[l, r)
    LL sum = 0;
    LL lazy = 0;
};

struct SegmentTree {
    LL P;
    std::vector<Node> tr;

    SegmentTree() {}
    SegmentTree(int n, LL p) {
        P = p;
        init(n);
    }

    void init(int n) {
        tr.resize(4 * (n + 1));
    }

    void merge_node(Node& res, Node x, Node y) {
        res.sum = (x.sum + y.sum) % P;
    }

    void push_up(int u) {
        merge_node(tr[u], tr[u << 1], tr[u << 1 | 1]);
    }

    void build(int u, int l, int r, std::vector<LL>& w, HLD& hld) { // 建树区间为[l, r)
        tr[u].l = l;
        tr[u].r = r;
        if (r - l == 1) {
            tr[u].lazy = 0;
            tr[u].sum = w[hld.seq[l]];
            return ;
        }
        tr[u].lazy = 0;
        int mid = (l + r) >> 1;
        build(u << 1, l, mid, w, hld);
        build(u << 1 | 1, mid, r, w, hld);
        push_up(u);
    }

    void push_down(int u) {
        if (!tr[u].lazy) {
            return ;
        }
        (tr[u << 1].lazy += tr[u].lazy) %= P;
        (tr[u << 1].sum += tr[u].lazy * (tr[u << 1].r - tr[u << 1].l) % P) %= P;
        (tr[u << 1 | 1].lazy += tr[u].lazy) %= P;
        (tr[u << 1 | 1].sum += tr[u].lazy * (tr[u << 1 | 1].r - tr[u << 1 | 1].l) % P) %= P;
        tr[u].lazy = 0;
    }

    void modify(int u, int l, int r, int x) { // 修改区间为[l, r)
        if (tr[u].l >= r || tr[u].r <= l) {
            return ;
        }
        if (tr[u].l >= l && tr[u].r <= r) {
            (tr[u].lazy += x) %= P;
            (tr[u].sum += x * (tr[u].r - tr[u].l) % P) %= P;
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
        Node ans;
        push_down(u); // 单点修改可去掉
        merge_node(ans, query(u << 1, l, r), query(u << 1 | 1, l, r));
        push_up(u);
        return ans;
    }

};

void solve() {
    int n, m, r, p;
    std::cin >> n >> m >> r >> p;
    r -- ;

    std::vector<LL> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i] %= p;
    }

    HLD hld(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        u -- ;
        v -- ;
        hld.addEdge(u, v);
    }

    hld.work(r);

    SegmentTree sg(n, p);

    sg.build(1, 0, n, a, hld);

    while (m -- ) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int x, y;
            LL z;
            std::cin >> x >> y >> z;
            x -- , y -- ;
            z %= p;
            while (hld.top[x] != hld.top[y]) {
                if (hld.dep[hld.top[x]] < hld.dep[hld.top[y]]) {
                    std::swap(x, y);
                }
                sg.modify(1, hld.in[hld.top[x]], hld.in[x] + 1, z);
                x = hld.parent[hld.top[x]];
            }
            if (hld.dep[x] > hld.dep[y]) {
                std::swap(x, y);
            }
            sg.modify(1, hld.in[x], hld.in[y] + 1, z);
        } else if (op == 2) {
            int x, y;
            std::cin >> x >> y;
            x -- , y -- ;
            Node ans;
            while (hld.top[x] != hld.top[y]) {
                if (hld.dep[hld.top[x]] < hld.dep[hld.top[y]]) {
                    std::swap(x, y);
                }
                // Node res = sg.query(1, hld.in[hld.top[x]], hld.in[x] + 1);
                sg.merge_node(ans, ans, sg.query(1, hld.in[hld.top[x]], hld.in[x] + 1));
                x = hld.parent[hld.top[x]];
            }
            if (hld.dep[x] > hld.dep[y]) {
                std::swap(x, y);
            }
            // Node res = sg.query(1, hld.in[x], hld.in[y] + 1);
            sg.merge_node(ans, ans, sg.query(1, hld.in[x], hld.in[y] + 1));
            std::cout << ans.sum << "\n";
        } else if (op == 3) {
            int x;
            LL z;
            std::cin >> x >> z;
            z %= p;
            x -- ;
            sg.modify(1, hld.in[x], hld.out[x], z);
        } else {
            int x;
            std::cin >> x;
            x -- ;
            Node ans = sg.query(1, hld.in[x], hld.out[x]);
            std::cout << ans.sum << "\n";
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
