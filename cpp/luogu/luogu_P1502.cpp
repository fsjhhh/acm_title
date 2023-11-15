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

#define int long long

typedef long long LL;
typedef __int128 i128;
typedef std::pair<int, int> PII;
typedef std::pair<LL, LL> PLL;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;

const int N = 1e5 + 10;

int n, W, H;
struct matrix {
    int l, r, h;
    int val;
} mat[N << 2];

struct node {
    int l, r;
    int lazy;
    int maxx;
} tr[N << 2];

std::vector<int> all;

void init() {
    all.clear();
    memset(mat, 0, sizeof mat);
    memset(tr, 0, sizeof tr);
}

int find(int x) {
    int l = 0, r = all.size() - 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (all[mid] >= x) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return r + 1;
}

void push_up(int u) {
    tr[u].maxx = std::max(tr[u << 1].maxx, tr[u << 1 | 1].maxx);
}

void build(int u, int l, int r) {
    if (l == r) {
        tr[u].l = l, tr[u].r = r;
        tr[u].lazy = 0;
        tr[u].maxx = 0;
        return ;
    }

    tr[u].l = l, tr[u].r = r;
    tr[u].lazy = 0;

    int mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    push_up(u);
}

void push_down(int u) {
    tr[u << 1].maxx += tr[u].lazy;
    tr[u << 1 | 1].maxx += tr[u].lazy;
    tr[u << 1].lazy += tr[u].lazy;
    tr[u << 1 | 1].lazy += tr[u].lazy;
    tr[u].lazy = 0;
}

void modify(int u, int l, int r, int w) {
    if (tr[u].l >= l && tr[u].r <= r) {
        tr[u].maxx += w;
        tr[u].lazy += w;
        return ;
    }
    push_down(u);

    int mid = (tr[u].l + tr[u].r) >> 1;
    if (l <= mid) {
        modify(u << 1, l, r, w);
    }
    if (r > mid) {
        modify(u << 1 | 1, l, r, w);
    }

    push_up(u);

}


void solve() {
    init();

    std::cin >> n >> H >> W;

    for (int i = 1; i <= n; i++) {
        int x, y, l;
        std::cin >> x >> y >> l;
        mat[(i << 1) - 1] = {y, y + W - 1, x, l};
        mat[(i << 1)] = {y, y + W - 1, x + H - 1, -l};
        all.push_back(y);
        all.push_back(y + W - 1);
    }

    n <<= 1;

    std::sort(all.begin(), all.end());
    std::sort(mat + 1, mat + n + 1, [&](matrix a, matrix b) -> bool {
        if (a.h == b.h) {
            return a.val > b.val;
        }
        return a.h < b.h;
    });
    all.erase(std::unique(all.begin(), all.end()), all.end());

    for (int i = 1; i <= n; i++) {
        int l1 = find(mat[i].l);
        int r1 = find(mat[i].r);
        std::cerr << l1 << " " << r1 << "\n";
        mat[i].l = l1;
        mat[i].r = r1;
    }
    std::cerr << "\n";

    build(1, 1, all.size());
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        modify(1, mat[i].l, mat[i].r, mat[i].val);
        ans = std::max(ans, tr[1].maxx);
    }

    std::cout << ans << "\n";

}

signed main() {
    IOS;
    int t = 1;
    std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
