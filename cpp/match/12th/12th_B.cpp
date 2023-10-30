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

const double PI = acos(-1);

LL max_area_triangles(LL n) {
    if (n % 2 == 0) {
        return n + 2;
    } else {
        return n;
    }
}

void solve()
{
	LL n;
    cin >> n;
    if (n == 3)
    {
        cout << "1" << endl;
        return ;
    }
    if (n == 4)
    {
        cout << "4" << endl;
        return ;
    }
    cout << max_area_triangles(n) << endl;
}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
