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
//priority_queue 优先队列
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
int a[N], b[N];
int f[N];
std::map<int, int> mp;
int v[N], w[N], cnt;

void solve()
{
    int n;
    scanf("%d", &n);
    //memset(b, 0, sizeof b);
    for (int i = 1; i <= n; i ++ ) {
    	scanf("%d", &a[i]);
    }
    for (int i = 1, j = 1; i <= n; i ++ ) {
        j = i + 1;
    	while (j <= n && a[j] < a[i]) {
    		j ++ ;
    	}
    	b[i] = j - i;
        mp[b[i]] ++ ;
    	i = j - 1;
    }

    cnt = 0;
    for (auto [a, b] : mp) {
        int k = 1, s = b;
        while(k < s)
        {
            cnt ++ ;
            v[cnt] = a * k;
            w[cnt] = a * k;
            s -= k;
            k *= 2;
        }
        if(s > 0)
        {
            cnt ++ ;
            v[cnt] = a * s;
            w[cnt] = a * s;
        }
    }

    memset(f, 0, sizeof f);
    for (int i = 1; i <= cnt; i ++ ) {
        for (int j = n / 2; j >= v[i]; j -- ) {
            f[j] = std::max(f[j], f[j - v[i]] + w[i]);
        }
    }

    if (f[n / 2] == n / 2) {
        std::cout << "Yes" << "\n";
    }
    else {
        std::cout << "No" << "\n";
    }

    mp.clear();
}

int main()
{
    IOS;
    int t = 1;
    scanf("%d", &t);
    while (t -- )
        solve();
    return 0;
}