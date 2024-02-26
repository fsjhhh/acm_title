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

struct HLD {
    int n;
    std::vector<int> siz, top, dep, parent, in, out, seq, w;
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
        w.resize(n);
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
    int lca(int u, int v) { // 最近公共祖先
        while (top[u] != top[v]) {
            if (dep[top[u]] > dep[top[v]]) {
                u = parent[top[u]];
            } else {
                v = parent[top[v]];
            }
        }
        return dep[u] < dep[v] ? u : v;
    }
    
    int dist(int u, int v) { // 两点间的距离
        return dep[u] + dep[v] - 2 * dep[lca(u, v)];
    }
    
    int jump(int u, int k) { // u点向上跳k步到达的点
        if (dep[u] < k) {
            return -1;
        }
        
        int d = dep[u] - k;
        
        while (dep[top[u]] > d) {
            u = parent[top[u]];
        }
        
        return seq[in[u] - dep[u] + d];
    }
    
    bool isAncester(int u, int v) { // u是否是v的祖先节点
        return in[u] <= in[v] && in[v] < out[u];
    }
    
    int rootedParent(int u, int v) { // 以v为跟的树中u节点的父节点
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
    
    int rootedSize(int u, int v) { // 以u为根的树中v子树的大小
        if (u == v) {
            return n;
        }
        if (!isAncester(v, u)) {
            return siz[v];
        }
        return n - siz[rootedParent(u, v)];
    }
    
    int rootedLca(int a, int b, int c) { // (a, b, c)的最近公共祖先
        return lca(a, b) ^ lca(b, c) ^ lca(c, a);
    }
};

struct Node {
    int l, r; // 区间为[l, r)
    LL mx = 0;
    LL lazy1 = -1;
    LL lazy2 = 0;
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
        res.mx = std::max(x.mx, y.mx);
    }

    void push_up(int u) {
        merge_node(tr[u], tr[u << 1], tr[u << 1 | 1]);
    }

    void build(int u, int l, int r, HLD& hld) { // 建树区间为[l, r)
        tr[u].l = l;
        tr[u].r = r;
        if (r - l == 1) {
            tr[u].lazy1 = -1;
            tr[u].lazy2 = 0;
            tr[u].mx = hld.w[hld.seq[l]];
            return ;
        }
        tr[u].lazy1 = -1;
        tr[u].lazy2 = 0;
        int mid = (l + r) >> 1;
        build(u << 1, l, mid, hld);
        build(u << 1 | 1, mid, r, hld);
        push_up(u);
    }

    void push_down(int u) {
        if (tr[u].lazy1 != -1) {
            tr[u << 1].lazy2 = tr[u << 1 | 1].lazy2 = 0;
            tr[u << 1].lazy1 = tr[u].lazy1;
            tr[u << 1].mx = tr[u].lazy1;
            tr[u << 1 | 1].lazy1 = tr[u].lazy1;
            tr[u << 1 | 1].mx = tr[u].lazy1;
            tr[u].lazy1 = -1;
        }
        if (tr[u].lazy2) {
            tr[u << 1].lazy2 += tr[u].lazy2;
            tr[u << 1].mx += tr[u].lazy2;
            tr[u << 1 | 1].lazy2 += tr[u].lazy2;
            tr[u << 1 | 1].mx += tr[u].lazy2;
            tr[u].lazy2 = 0;
        }
    }

    void modify1(int u, int l, int r, int x) { // 修改区间为[l, r)
        if (tr[u].l >= r || tr[u].r <= l) {
            return ;
        }
        if (tr[u].l >= l && tr[u].r <= r) {
            tr[u].lazy2 += x;
            tr[u].mx += x;
            return ;
        }
        push_down(u); // 单点修改可去掉
        modify1(u << 1, l, r, x);
        modify1(u << 1 | 1, l, r, x);
        push_up(u);
    }

    void modify2(int u, int l, int r, int x) {
        if (tr[u].l >= r || tr[u].r <= l) {
            return ;
        }
        if (tr[u].l >= l && tr[u].r <= r) {
            tr[u].lazy1 = x;
            tr[u].lazy2 = 0;
            tr[u].mx = x;
            return ;
        }
        push_down(u);
        modify2(u << 1, l, r, x);
        modify2(u << 1 | 1, l, r, x);
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
    int n;
    std::cin >> n;

    HLD hld(n);
    std::vector<int> cn(n);
    std::vector<std::vector<std::array<int, 3>>> edges(n);
    for (int i = 1; i < n; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u --, v -- ;
        hld.addEdge(u, v);
        edges[u].push_back({v, w, i});
        edges[v].push_back({u, w, i});
    }

    auto dfs = [&](auto self, int u, int fa) -> void {
        for (auto it : edges[u]) {
            int v = it[0], x = it[1], i = it[2];
            if (v == fa) {
                continue;
            }
            hld.w[v] = x;
            cn[i] = v;
            self(self, v, u);
        }
    };
    dfs(dfs, 0, -1);

    hld.work();

    SegmentTree sg(n);
    sg.build(1, 0, n, hld);

    while (1) {
        std::string s;
        std::cin >> s;
        if (s == "Stop") {
            break;
        }
        if (s == "Change") {
            int k, w;
            std::cin >> k >> w;
            sg.modify2(1, hld.in[cn[k]], hld.in[cn[k]] + 1, w);
        } else if (s == "Cover") {
            int x, y, w;
            std::cin >> x >> y >> w;
            x -- ;
            y -- ;
            int z = hld.lca(x, y);
            while (hld.top[x] != hld.top[y]) {
                if (hld.dep[hld.top[x]] < hld.dep[hld.top[y]]) {
                    std::swap(x, y);
                }
                sg.modify2(1, hld.in[hld.top[x]] + (hld.top[x] != z ? 0 : 1), hld.in[x] + 1, w);
                x = hld.parent[hld.top[x]];
            }
            if (hld.dep[x] > hld.dep[y]) {
                std::swap(x, y);
            }
            sg.modify2(1, hld.in[x] + (x != z ? 0 : 1), hld.in[y] + 1, w);
        } else if (s == "Add") {
            int x, y, w;
            std::cin >> x >> y >> w;
            x -- ;
            y -- ;
            int z = hld.lca(x, y);
            while (hld.top[x] != hld.top[y]) {
                if (hld.dep[hld.top[x]] < hld.dep[hld.top[y]]) {
                    std::swap(x, y);
                }
                sg.modify1(1, hld.in[hld.top[x]] + (hld.top[x] != z ? 0 : 1), hld.in[x] + 1, w);
                x = hld.parent[hld.top[x]];
            }
            if (hld.dep[x] > hld.dep[y]) {
                std::swap(x, y);
            }
            sg.modify1(1, hld.in[x] + (x != z ? 0 : 1), hld.in[y] + 1, w);
        } else {
            int x, y;
            std::cin >> x >> y;
            x -- ;
            y -- ;
            int z = hld.lca(x, y);
            Node ans;
            while (hld.top[x] != hld.top[y]) {
                if (hld.dep[hld.top[x]] < hld.dep[hld.top[y]]) {
                    std::swap(x, y);
                }
                sg.merge_node(ans, ans, sg.query(1, hld.in[hld.top[x]] + (hld.top[x] != z ? 0 : 1), hld.in[x] + 1));
                x = hld.parent[hld.top[x]];
            }
            if (hld.dep[x] > hld.dep[y]) {
                std::swap(x, y);
            }
            sg.merge_node(ans, ans, sg.query(1, hld.in[x] + (x != z ? 0 : 1), hld.in[y] + 1));
            std::cout << ans.mx << "\n";
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
