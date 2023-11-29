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

const int N = 2e5 + 10;
struct Node {
    int l, r;
    int cnt;
} tr[N * 30];

int root[N], idx;

std::vector<int> nums;
int n, m;
int a[N];

int find(int x) {
    return std::lower_bound(nums.begin(), nums.end(), x) - nums.begin();
}

void push_up(int u) {
    tr[u].cnt = tr[tr[u].l].cnt + tr[tr[u].r].cnt;
}

int build(int l, int r) {
    int p = ++ idx;
    if (l == r) {
        tr[p].cnt = 0;
        return p;
    }
    int mid = (l + r) >> 1;
    tr[p].l = build(l, mid);
    tr[p].r = build(mid + 1, r);
    push_up(p);
    return p;
}

int modify(int u, int l, int r, int x) {
    int p = ++ idx;
    tr[p] = tr[u];
    if (l == r) {
        tr[p].cnt ++ ;
        return p;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) {
        tr[p].l = modify(tr[u].l, l, mid, x);
    } else {
        tr[p].r = modify(tr[u].r, mid + 1, r, x);
    }
    push_up(p);
    return p;
}

int query(int p, int q, int l, int r, int x) {
    if (l == r) {
        return l;
    }
    int mid = (l + r) >> 1;
    int count = tr[tr[q].l].cnt - tr[tr[p].l].cnt;
    if (x <= count) {
        return query(tr[p].l, tr[q].l, l, mid, x);
    } else {
        return query(tr[p].r, tr[q].r, mid + 1, r, x - count);
    }
}

void solve() {
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        nums.push_back(a[i]);
    }

    std::sort(nums.begin(), nums.end());
    nums.erase(std::unique(nums.begin(), nums.end()), nums.end());

    int cn = nums.size() - 1;

    root[0] = build(0, cn);
    for (int i = 1; i <= n; i++) {
        root[i] = modify(root[i - 1], 0, cn, find(a[i]));
    }

    while (m -- ) {
        int l, r, k;
        std::cin >> l >> r >> k;
        std::cout << nums[query(root[l - 1], root[r], 0, cn, k)] << "\n";
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
