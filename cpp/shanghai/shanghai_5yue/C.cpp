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
int a[N], b[N], c[N];

void solve()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
    }
    std::priority_queue<int> q;
    int ans = 0, res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (res + c[i] >= a[i])
        {
            ans++;
            res += c[i];
            res -= a[i];
            q.push(b[i] - c[i]);
        }
        else
        {
            q.push(b[i] - c[i]);
            res += c[i];
            ans ++ ;
            auto t = q.top();
            q.pop();
            while (q.size() && res + t < a[i])
            {
                res = res + t;
                ans--;
                t = q.top();
                q.pop();
            }
            if (res + t < a[i])
            {
                printf("-1\n");
                return;
            }
            else
            {
                res = res + t;
                res -= a[i];
                ans -- ;
            }
        }
    }
    printf("%d\n", ans);
}

int main()
{
    IOS;
    int t = 1;
    while (t--)
        solve();
    return 0;
}