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

const int N = 2e5 + 10;
std::vector<std::array<int, 3>> a(N);
std::map<int, int> mpl, mpr;
int n;
bool pd;

bool cmp1(std::array<int, 3> x, std::array<int, 3> y)
{
	return x[0] < y[0];
}

bool cmp2(std::array<int, 3> x, std::array<int, 3> y)
{
	return x[1] < y[1];
}

void CDQ(int l, int r)
{
	if (l >= r - 1)
		return ;
	int mid = mpl[a[(l + r) >> 1][0]];
	if (mid <= l)
		mid = mpr[a[(l + r) >> 1][0]] + 1;
	if (mid >= r)
		return ;

	CDQ(l, mid);
	CDQ(mid, r);

	std::sort(a.begin() + l, a.begin() + mid, cmp2);
	std::sort(a.begin() + mid, a.begin() + r, cmp2);

	std::vector<int> suf(r - l);
	for (int i = r - 1; i >= l; i -- )
	{
		suf[i - l] = a[i][2];
		if (i < r - 1)
		{
			suf[i - l] = std::max(suf[i - l], suf[i - l + 1]);
		}
	}

	int pos = mid;
	for (int i = l; i < mid; i ++ )
	{
		while (pos < r && a[pos][1] <= a[i][1])
		{
			pos ++ ;
		}
		if (pos == r)
			break;
		if (suf[pos - l] > a[i][2])
			pd = 1;
	}

}

void solve()
{
    std::cin >> n;
    for (int i = 0; i < n; i ++ )
    {
    	for (int j = 0; j < 3; j ++ )
    	{
    		std::cin >> a[i][j];
    	}
    	std::sort(a[i].begin(), a[i].end());
    }
    std::sort(a.begin(), a.begin() + n, cmp1);

    for (int i = n - 1; i >= 0; i -- )
    {
    	mpl[a[i][0]] = i;
    }
    for (int i = 0; i < n; i ++ )
    {
    	mpr[a[i][0]] = i;
    }

    CDQ(0, n);

    if (pd)
    	std::cout << "Yes" << "\n";
    else
    	std::cout << "No" << "\n";
}

int main()
{
    IOS;
    int t = 1;
    // std::cin >> t;
    while (t -- )
        solve();
    return 0;
}

