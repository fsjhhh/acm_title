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

// #define int long long

const int N = 5e5 +  10, M = 210;
int sum[M][M][1002], count[M][M][1002], a[N], s[M][M];
struct Node {
    int l, r;
    int cnt, sum;
} tr[N * 30];
int root[N], idx;
int R, C, Q;

void work1() {
    int maxx = 0;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            std::cin >> s[i][j];
            maxx = std::max(maxx, s[i][j]);
        }
    }

    for (int k = 0; k <= maxx; k++) {
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                sum[i][j][k] = sum[i - 1][j][k] + sum[i][j - 1][k] - sum[i - 1][j - 1][k] + (s[i][j] >= k ? s[i][j] : 0);
                count[i][j][k] = count[i - 1][j][k] + count[i][j - 1][k] - count[i - 1][j - 1][k] + (s[i][j] >= k ? 1 : 0);
            }
        }
    }

    while (Q -- ) {
        int x1, y1, x2, y2, H; 
        std::cin >> x1 >> y1 >> x2 >> y2 >> H;
        int z = sum[x2][y2][0] - sum[x2][y1 - 1][0] - sum[x1 - 1][y2][0] + sum[x1 - 1][y1 - 1][0];
        if (z < H) {
            std::cout << "Poor QLW\n";
            continue;
        }
        int ans = -1;
        int l = 0, r = maxx + 1;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            int t = sum[x2][y2][mid] - sum[x1 - 1][y2][mid] - sum[x2][y1 - 1][mid] + sum[x1 - 1][y1 - 1][mid];
            if (t >= H) {
                l = mid;
                ans = mid;
            } else {
                r = mid - 1;
            }
        }

        if (ans == -1) {
            std::cout << "Poor QLW\n";
        } else {
            int t1 = count[x2][y2][ans] - count[x1 - 1][y2][ans] - count[x2][y1 - 1][ans] + count[x1 - 1][y1 - 1][ans];
            int t2 = sum[x2][y2][ans] - sum[x1 - 1][y2][ans] - sum[x2][y1 - 1][ans] + sum[x1 - 1][y1 - 1][ans];
            std::cout << (t1 - (t2 - H) / ans) << "\n";
        }

    }
}

void push_up(int u) {
    tr[u].cnt = tr[tr[u].l].cnt + tr[tr[u].r].cnt;
    tr[u].sum = tr[tr[u].l].sum + tr[tr[u].r].sum;
}

int build(int l, int r) {
    int p = ++ idx;
    if (l == r) {
        tr[p].cnt = 0;
        tr[p].sum = 0;
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
        tr[p].sum += x;
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
        return (x + l - 1) / l;
    }
    int mid = (l + r) >> 1, ans = 0;
    int s = tr[tr[q].r].sum - tr[tr[p].r].sum;
    if (s < x) {
        ans += tr[tr[q].r].cnt - tr[tr[p].r].cnt;
        ans += query(tr[p].l, tr[q].l, l, mid, x - s);
    } else {
        ans += query(tr[p].r, tr[q].r, mid + 1, r, x);
    }
    return ans;
}

void work2() {
    int cn = 0;
    std::vector<int> sum(C + 1);
    for (int i = 1; i <= C; i++) {
        std::cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
        cn = std::max(cn, a[i]);
    }
    
    root[0] = build(1, cn + 1);
    for (int i = 1; i <= C; i++) {
        root[i] = modify(root[i - 1], 1, cn + 1, a[i]);
    }

    while (Q -- ) {
        int x1, y1, x2, y2, H;
        std::cin >> x1 >> y1 >> x2 >> y2 >> H;
        if (sum[y2] - sum[y1 - 1] < H) {
            std::cout << "Poor QLW\n";
        } else if (sum[y2] - sum[y1 - 1] == H) {
            std::cout << y2 - y1 + 1 << "\n";
        } else {
            std::cerr << Q << "\n";
            std::cout << query(root[y1 - 1], root[y2], 1, cn + 1, H) << "\n";;
        }
    }

}


void solve() {
    std::cin >> R >> C >> Q;
    if (R != 1) {
        work1();
    } else {
        work2();
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
