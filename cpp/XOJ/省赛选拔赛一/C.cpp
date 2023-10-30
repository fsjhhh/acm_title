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
const int N=1e5+10;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;

int n,k;
string s;
PLL a[N], b[N];

void solve()
{
    cin >> n >> k;
    cin >> s;
    LL x = 0, y = 0;
    a[0] = {0, 0};
    LL maxx = 0;
    LL dx, dy;
    for(int i = 0;i < n;i++)
    {
        if(s[i] == 'R')
        {
        	x ++ ;
        }
        else if(s[i] == 'L')
        {
        	x -- ;
        }
        else if(s[i] == 'U')
        {
            y ++ ;
        }
        else if(s[i] == 'D')
        {
            y -- ;
        }
        a[i] = {x, y};
    }
    
    dx = a[n - 1].first, dy = a[n - 1].second;
    for (int i = 0; i < n; i ++ )
    {
    	PLL z = a[i];
    	maxx = std::max(maxx, abs(z.first) + abs(z.second));
    	z.first = (z.first + dx * (k - 1));
    	z.second = (z.second + dy * (k - 1));
    	maxx = std::max(maxx, abs(z.first) + abs(z.second));
    }
    std::cout << maxx << "\n";

}

int main()
{
    IOS;
    int t = 1;
    cin >> t;
    while(t -- )
        solve();

    return 0;
}