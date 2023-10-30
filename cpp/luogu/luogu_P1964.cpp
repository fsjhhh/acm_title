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
#define IOS ios::sync_with_stdio(false); \
            cin.tie(0);              \
            cout.tie(0);
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;

const int N = 1e5 + 10;
int cnt[N], v[N], w[N];
map<string, int> ma;
int f[N];

struct Goods
{
	int v, w;
};

void solve()
{
	int m, n;
	cin >> m >> n;
	m = 21 - m;
	int cn = 0;
	while (n -- )
	{
		int _cnt, _v, _w;
		string name;
		cin >> _cnt >> _v >> _w >> name;
		if (!ma.count(name))
		{
			cnt[++ cn ] = _cnt;
			v[cn] = _v;
			w[cn] = _w;
			ma[name] = cn;
		}
		else
		{
			int t = ma[name];
			cnt[t] += _cnt;
		}
	}

	vector<Goods> goods;
	for (auto it : ma)
	{
		int t = it.second;
		int num = cnt[t] / w[t];
		int cnum = (cnt[t] - num * w[t]);
		goods.push_back({1, v[t] * cnum});
		//cout << cnum << endl;
		//cout << num << endl;
		int k = 1;
		while (k < num)
		{
			goods.push_back({k, v[t] * k * w[t]});
			num -= k;
			k *= 2;
		}
		if (num > 0)
		{
			goods.push_back({num, v[t] * num * w[t]});
		}
	}


	for (auto it : goods)
	{
		for (int j = m; j >= it.v; j -- )
		{
			f[j] = max(f[j], f[j - it.v] + it.w);
		}
	}

	cout << f[m] << endl;

}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
