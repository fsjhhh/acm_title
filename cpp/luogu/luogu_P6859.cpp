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

const int N = 2e6 + 10;
int tr1[N], tr2[N], a[N];
int n, q;

inline int read(){
	int s = 0, w = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') w = -1;
	for (; isdigit(c); c = getchar()) s = (s << 1) + (s << 3) + (c ^ 48);
	return s * w;
}

int lowbit(int x) {
    return x & (-x);
}

void modify1(int u, int x) {
    for (int i = u; i <= n; i += lowbit(i)) {
        tr1[i] += x;
    }
}

void modify2(int u, int x) {
    for (int i = u; i <= n; i += lowbit(i)) {
        tr2[i] += x;
    }
}

int query1(int u) {
    int ans = 0;
    for (int i = u; i; i -= lowbit(i)) {
        ans += tr1[i];
    }
    return ans;
}

int query2(int u) {
    int ans = 0;
    for (int i = u; i; i -= lowbit(i)) {
        ans += tr2[i];
    }
    return ans;
}

int find1(int x) {
    int l = 1, r = n;
    int ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (query1(mid) <= x) {
            ans = mid;
            l = mid + 1; 
        } else {
            r = mid - 1;
        }
    }
    return ans;
}

int find2(int x) {
    int l = 1, r = n;
    int ans = -1, s = query2(x - 1);
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (query2(mid) > s) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}

void solve() {
    n = read(), q = read();
    for (int i = 1; i <= n; i++) {
        a[i] = read();
        modify1(i, a[i]);
        modify2(i, a[i] == 1);
    }

    int p1 = find2(1);
    while (q -- ) {
        char op = getchar();
		for (; op != 'C' && op != 'A'; op = getchar());
        if (op == 'A') {
            int s;
            s = read();
            if (s == 1) {
                if (p1 == -1) {
                    printf("none\n");
                } else {
                    printf("%d %d\n", p1, p1);
                }
                continue;
            }
            if (query1(n) < s) {
                printf("none\n");
                continue;
            }
            int pos = find1(s);
            if (pos < 1) {
                printf("none\n");
                continue;
            } else if (query1(pos) == s) {
                printf("%d %d\n", 1, pos);
                continue;
            }
            int p2 = find2(pos + 1);
            if (p1 == -1) {
                printf("none\n");
                continue;
            }
            if (p2 == -1) {
                if (n - pos <= p1 - 1) {
                    printf("none\n");
                    continue;
                } else {
                    printf("%d %d\n", p1 + 1, pos + p1);
                    continue;
                }
            }
            int l1 = p1 - 1, l2 = p2 - pos - 1;
            if (l1 < l2) {
                printf("%d %d\n", p1 + 1, pos + p1);
            } else if (l1 == l2) {
                printf("%d %d\n", p1, p2);
            } else {
                printf("%d %d\n", l2 + 1, p2);
            }
        } else {
            int i = read(), v = read();
            if (a[i] != v) {
                modify1(i, -a[i] + v);
                if (v == 2) {
                    modify2(i, -1);
                } else {
                    modify2(i, 1);
                }
                a[i] = v;
                p1 = find2(1);
            }
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
