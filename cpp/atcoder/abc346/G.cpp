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

const int N = 2e5 + 10;

int n, W, H;
struct matrix {
    int l, r, h;
    int val;
} mat[N << 2];

struct node {
    int l, r;
    int cnt;
    int len;
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
    if (tr[u].cnt) {
        tr[u].len = tr[u].r - tr[u].l + 1;
    } else if (tr[u].l != tr[u].r) {
        tr[u].len = tr[u << 1].len + tr[u << 1 | 1].len;
    } else {
        tr[u].len = 0;
    }
}

void build(int u, int l, int r) {
    if (l == r) {
        tr[u].l = l, tr[u].r = r;
        tr[u].cnt = 0;
        tr[u].len = 0;
        return ;
    }

    tr[u].l = l, tr[u].r = r;
    tr[u].cnt = 0;
    tr[u].len = 0;

    int mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    push_up(u);
}

void modify(int u, int l, int r, int w) {
    if (tr[u].l >= l && tr[u].r <= r) {
        tr[u].cnt += w;
        push_up(u);
        return ;
    }

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
    int n;
    std::cin >> n;
    std::vector<LL> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> q(n + 1, 0), h(n + 1, n + 1), w(n + 1);
    for (int i = 1; i <= n; i++) {
        w[i] = q[a[i]] + 1;
        q[a[i]] = i;
    }

    for (int i = n; i >= 1; i--) {
        mat[(i << 1) - 1].l = i;
        mat[(i << 1) - 1].r = h[a[i]] - 1;
        mat[(i << 1) - 1].h = w[i];
        mat[(i << 1) - 1].val = 1;
        mat[(i << 1)].l = i;
        mat[(i << 1)].r = h[a[i]] - 1;
        mat[(i << 1)].h = i;
        mat[(i << 1)].val = -1;
        h[a[i]] = i;
    }

    build(1, 1, n);

    int m = n;
    n <<= 1;
    std::sort(mat + 1, mat + n + 1, [&](matrix a, matrix b) -> bool {
        if (a.h == b.h) {
            return a.val > b.val;
        }
        return a.h < b.h;
    });

    // for (int i = 1; i <= n; i++) {
    //     std::cout << mat[i].l << " " << mat[i].r << " " << mat[i].h << " " << mat[i].val << "\n";
    // }

    int ans = 0;
    for (int i = 1, j = 1; i <= m && j <= n; i = mat[j].h) {
        while (j <= n && mat[j].h == i && mat[j].val == 1) {
            modify(1, mat[j].l, mat[j].r, mat[j].val);
            j ++ ;
        }
        ans += tr[1].len;
        while (j <= n && mat[j].h == i && mat[j].val == -1) {
            modify(1, mat[j].l, mat[j].r, mat[j].val);
            j ++ ;
        }
    }
    
    // for (int i = 1; i <= n; i++) {
    //     if (i != 1) {
    //         std::cout << tr[1].len << " " << mat[i].h << " " << mat[i - 1].h << "\n";
    //         ans += tr[1].len * (mat[i].h - mat[i - 1].h);
    //     }
    //     modify(1, mat[i].l, mat[i].r, mat[i].val);
    // }

    std::cout << ans << "\n";

}

signed main() {
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}
