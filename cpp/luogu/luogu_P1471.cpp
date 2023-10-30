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
// priority_queue 优先队列
#define IOS                           \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(0);                  \
    std::cout.tie(0);

typedef long long LL;
typedef std::pair<int, int> PII;
typedef std::pair<LL, LL> PLL;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;

const int N = 1e5 + 10;
struct Node
{
    int l, r;
    double sum1, sum2, tags;
} tr[N * 4];

int n, m;
double a[N];

void pushup(int u)
{
    tr[u].sum1 = tr[u << 1].sum1 + tr[u << 1 | 1].sum1;
    tr[u].sum2 = tr[u << 1].sum2 + tr[u << 1 | 1].sum2;
}

void build(int u, int l, int r)
{
    if (l == r)
        tr[u] = {l, r, a[l], a[l] * a[l], 0};
    else
    {
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        tr[u].tags = 0;
        pushup(u);
    }
}

void tag(int u)
{
    int mid = tr[u].l + tr[u].r >> 1;
    tr[u << 1].tags += tr[u].tags;
    tr[u << 1].sum2 += 2 * tr[u].tags * tr[u << 1].sum1 + (mid - tr[u].l + 1) * tr[u].tags * tr[u].tags;
    tr[u << 1].sum1 += (mid - tr[u].l + 1) * tr[u].tags;
    tr[u << 1 | 1].tags += tr[u].tags;
    tr[u << 1 | 1].sum2 += 2 * tr[u].tags * tr[u << 1 | 1].sum1 + (tr[u].r - mid) * tr[u].tags * tr[u].tags;
    tr[u << 1 | 1].sum1 += (tr[u].r - mid) * tr[u].tags;
    tr[u].tags = 0;
}

void modify(int u, int a, int b, double x)
{
    if (tr[u].l >= a && tr[u].r <= b)
    {
        tr[u].tags += x;
        tr[u].sum2 += 2 * x * tr[u].sum1 + (tr[u].r - tr[u].l + 1) * x * x;
        tr[u].sum1 += (tr[u].r - tr[u].l + 1) * x;
        return;
    }
    tag(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if (a <= mid)
        modify(u << 1, a, b, x);
    if (b > mid)
        modify(u << 1 | 1, a, b, x);
    pushup(u);
}

double query1(int u, int a, int b)
{
    if (tr[u].l >= a && tr[u].r <= b)
        return tr[u].sum1;
    tag(u);
    int mid = tr[u].l + tr[u].r >> 1;
    double sum = 0;
    if (a <= mid)
        sum += query1(u << 1, a, b);
    if (b > mid)
        sum += query1(u << 1 | 1, a, b);
    return sum;
}

double query2(int u, int a, int b)
{
    if (tr[u].l >= a && tr[u].r <= b)
        return tr[u].sum2;
    tag(u);
    int mid = tr[u].l + tr[u].r >> 1;
    double sum = 0;
    if (a <= mid)
        sum += query2(u << 1, a, b);
    if (b > mid)
        sum += query2(u << 1 | 1, a, b);
    return sum;
}

void solve()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lf", &a[i]);
    build(1, 1, n);
    while (m--)
    {
        int op;
        scanf("%d", &op);
        if (op == 1)
        {
            int a, b;
            double x;
            scanf("%d%d%lf", &a, &b, &x);
            modify(1, a, b, x);
        }
        if (op == 2)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            double t = query1(1, a, b);
            double x = (t * 1.0) / ((b - a + 1) * 1.0);
            printf("%.4lf\n", x);
        }
        if (op == 3)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            double t2 = query2(1, a, b);
            double t1 = query1(1, a, b);
            double x1 = (t1 * 1.0) / ((b - a + 1) * 1.0);
            double x2 = (t2 * 1.0) / ((b - a + 1) * 1.0);
            double x = x1 * x1 * (-1) + x2;
            printf("%.4lf\n", x);
        }
    }
}

int main()
{
    IOS;
    int t = 1;
    while (t--)
        solve();
    return 0;
}