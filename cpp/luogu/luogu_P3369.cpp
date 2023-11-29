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

const int N = 1e6 + 10, range = 1e7 + 5;

struct Node {
    int l = 0, r = 0;
    int cnt = 0;
} tr[N * 30];
int root[N], idx = 2;

void push_down(int u) {
    if (!tr[u].l) {
        tr[u].l = idx ++ ;
    }
    if (!tr[u].r) {
        tr[u].r = idx ++ ;
    }
}

void push_up(int u) {
    tr[u].cnt = tr[tr[u].l].cnt + tr[tr[u].r].cnt;
}

void modify(int u, int l, int r, int pos, int value) {
    if (l == r) {
        tr[u].cnt += value;
        return ;
    }
    int mid = (l + r) >> 1;
    push_down(u);
    if (pos <= mid) {
        modify(tr[u].l, l, mid, pos, value);
    } else {
        modify(tr[u].r, mid + 1, r, pos, value);
    }
    push_up(u);
}

void add(int pos, int value) {
    modify(1, -range, range, pos, value);
}

void insert(int x) {
    add(x, 1);
}

void remove(int x) {
    add(x, -1);
}

int query1(int u, int l, int r, int L, int R) {
    if (L <= l && R >= r) {
        return tr[u].cnt;
    }
    if (l > R || r < L) {
        return 0;
    }
    push_down(u);
    int mid = (l + r) >> 1;
    return query1(tr[u].l, l, mid, L, R) + query1(tr[u].r, mid + 1, r, L, R);
}

int query2(int u, int l, int r, int x) {
    if (l == r) {
        return l;
    }
    int mid = (l + r) >> 1;
    if (x <= tr[tr[u].l].cnt) {
        return query2(tr[u].l, l, mid, x);
    } else {
        return query2(tr[u].r, mid + 1, r, x - tr[tr[u].l].cnt);
    }
}

int query3(int x) {
    int t = query1(1, -range, range, -range, x - 1);
    return query2(1, -range, range, t); 
}

int query4(int x) {
    int t = query1(1, -range, range, -range, x) + 1;
    return query2(1, -range, range, t);
}

void solve() {
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        int op, x;
        std::cin >> op >> x;
        if (op == 1) {
            insert(x);
        } else if(op == 2) {
            remove(x);
        } else if (op == 3) {
            std::cout << query1(1, -range, range, -range, x - 1) + 1 << "\n";
        } else if (op == 4) {
            std::cout << query2(1, -range, range, x) << "\n";
        } else if (op == 5) {
            std::cout << query3(x) << "\n";
        } else {
            std::cout << query4(x) << "\n";
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
