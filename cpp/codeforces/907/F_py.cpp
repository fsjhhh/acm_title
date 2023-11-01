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

const int N = 1e5+5;
 
int n, cnt, b[N];

std::vector<int> e[N];

struct Node{
    int t, i, a;
} a[N * 4];

struct node{
    int l, r, sum, add;
} t[N * 4];

int dfn[N], sz[N], id;

void dfs(int u) {
    dfn[u] = ++id;
    sz[u] = 1;
    for(int i : e[u]) {
        if(!sz[i]) {
            dfs(i);
            sz[u] += sz[i];
        }
    }
}

void build(int u, int l, int r) {
    if(l==r) {
        t[u]={l, r};
    }
    else {
        t[u] = {l, r};
        int mid= l + r >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
    }
}
 
void pushdown(int u) {
    int k = t[u].add;
    t[u].add = 0;
    t[u<<1].sum += k;
    t[u<<1].add += k;
    t[u<<1|1].sum += k;
    t[u<<1|1].add += k;
}
 
int query(int u,int x) {
    if(t[u].l == x && t[u].r == x) {
        return t[u].sum;
    }
    pushdown(u);
    int mid = t[u].l + t[u].r >> 1;
    if(x <= mid) {
        return query(u << 1, x);
    }
    else {
        return query(u << 1 | 1, x);
    }
}
 
void add(int u,int l,int r,int x) {
    if(t[u].l >= l && t[u].r <= r) {
        t[u].sum += x;
        t[u].add += x;
    }
    else {
        pushdown(u);
        int mid = t[u].l + t[u].r >> 1;
        if(l <= mid) add(u << 1, l, r, x);
        if(r > mid) add(u << 1 | 1, l, r, x);
    }
}

void solve() {
    std::cin >> n;
    cnt = 1;
    for(int j = 1; j <= n; j++) {
        int t, i, x;
        std::cin >> t >> i;
        i++;
        if (t == 1) {
            a[j] = {t, i, ++cnt}, e[i].push_back(cnt), e[cnt].push_back(i);
        }
        else if (t == 2) {
            std::cin >> x, a[j] = {t, i, x};
        }
        else {
            a[j] = {t,i};
        }
    }
    dfs(1);
    build(1, 1, cnt);
    for(int i = 1; i <= n; i++) {
        int t = a[i].t, k = a[i].i;
        if(t == 1) {
            b[a[i].a] = query(1,dfn[a[i].a]);
        }
        else if(t == 2) {
            int x = a[i].a;
            add(1, dfn[k], dfn[k] + sz[k] - 1, x);
        }
    }
    for (int i = 1; i <= n; i++) {
        std::cout << query(1, dfn[i]) - b[i] << " \n"[i == n];
    }
}

int main() {
    IOS;
    int _ = 1;
    std::cin >> _;
    while (_ -- )
        solve();
    return 0;
}
