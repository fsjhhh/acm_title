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

const int N = 1e5 + 10;
struct Node {
    int l, r;
    int sum, tag; 
    int minn, maxx;
} tr[N * 4];
int n, m;
int a[N];

void push_up(int u) {
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
    tr[u].maxx = std::max(tr[u << 1].maxx, tr[u << 1 | 1].maxx);
    tr[u].minn = std::min(tr[u << 1].minn, tr[u << 1 | 1].minn);
}

void build(int u, int l, int r) {
    if (l == r) {
        tr[u].sum = a[l];
        tr[u].tag = -1;
        tr[u].minn = tr[u].maxx = a[l];
        tr[u].l = tr[u].r = l;
        return ;
    }
    tr[u].l = l;
    tr[u].r = r;
    tr[u].tag = -1;
    int mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    push_up(u);
}

void push_down(int u) {
    if (tr[u].tag == -1) {
        return ;
    }
    tr[u << 1].sum = tr[u].tag * (tr[u << 1].r - tr[u << 1].l + 1);
    tr[u << 1].maxx = tr[u << 1].minn = tr[u].tag;
    tr[u << 1 | 1].sum = tr[u].tag * (tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1);
    tr[u << 1 | 1].maxx = tr[u << 1 | 1].minn = tr[u].tag;
    tr[u << 1].tag = tr[u << 1 | 1].tag = tr[u].tag;
    tr[u].tag = -1;
}

void modify1(int u, int l, int r) {
    if (l <= tr[u].l && r >= tr[u].r && tr[u].maxx == tr[u].minn) {
        int ans = tr[u].maxx, c = 1;
        while (1) {
            int d = tr[u].maxx / (c * 10), z = tr[u].maxx % c;
            int res = d * c + z;
            ans = std::min(ans, res);
            c *= 10;
            if (d == 0) {
                break;
            }
        }
        tr[u].minn = tr[u].maxx = ans;
        tr[u].sum = ans * (tr[u].r - tr[u].l + 1);
        tr[u].tag = ans;
        return ;
    }
    push_down(u);
    int mid = (tr[u].l + tr[u].r) >> 1;
    if (l <= mid) {
        modify1(u << 1, l, r);
    }
    if (r > mid) {
        modify1(u << 1 | 1, l, r);
    }
    push_up(u);
}

void modify2(int u, int l, int r, int x) {
    if (l <= tr[u].l && r >= tr[u].r) {
        tr[u].minn = x;
        tr[u].maxx = x;
        tr[u].sum = x * (tr[u].r - tr[u].l + 1);
        tr[u].tag = x;
        return ;
    }
    push_down(u);
    int mid = (tr[u].l + tr[u].r) >> 1;
    if (l <= mid) {
        modify2(u << 1, l, r, x);
    }
    if (r > mid) {
        modify2(u << 1 | 1, l, r, x);
    }
    push_up(u);
}

int query(int u, int l, int r) {
    if (l <= tr[u].l && r >= tr[u].r) {
        return tr[u].sum;
    }
    push_down(u);
    int mid = (tr[u].l + tr[u].r) >> 1, res = 0;
    if (l <= mid) {
        res += query(u << 1, l, r);
    }
    if (r > mid) {
        res += query(u << 1 | 1, l, r);
    }
    push_up(u);
    return res;

}

void solve() {
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    build(1, 1, n);

    while (m -- ) {
        int op, l, r;
        std::cin >> op >> l >> r;
        if (op == 1) {
            modify1(1, l, r);
        } else if (op == 2) {
            int x;
            std::cin >> x;
            modify2(1, l, r, x);
        } else {
            std::cout << query(1, l, r) << "\n";
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
