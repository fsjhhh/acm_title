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

const int N = 5e5 + 10;
int n, a[N], b[N];

LL m_sort(int l, int r)
{
    if (l >= r)
        return 0;

    int mid = l + r >> 1;
    LL count = m_sort(l, mid) + m_sort(mid + 1, r);
    int k = 1, i = l, j = mid + 1;
    while (i <= mid && j <= r)
    {
        if (a[i] <= a[j])
            b[k++] = a[i++];
        else
        {
            b[k++] = a[j++];
            count += mid - i + 1;
        }
    }
    while (i <= mid)
        b[k++] = a[i++];
    while (j <= r)
        b[k++] = a[j++];
    for (i = l, j = 1; i <= r; i++, j++)
        a[i] = b[j];
    return count;
}

void solve()
{
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    std::cout << m_sort(1, n) << std::endl;
}

int main()
{
    IOS;
    int t = 1;
    while (t--)
        solve();
    return 0;
}