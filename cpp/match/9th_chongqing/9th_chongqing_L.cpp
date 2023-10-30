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

int a[11], b[11];

void solve()
{
	for (int i = 1; i <= 20; i ++ ) cin >> a[i];
	for (int i = 1; i <= 20; i ++ ) cin >> b[i];

	int a1 = 5, b1 = 5, a2 = 0, b2 = 0;
	for (int i = 1; i <= 10; i ++ )
	{
		if(i % 2 == 1)
        {
            if(a[(i + 1) / 2] == 1) a2 ++ ;
            a1 -- ;
        }
        else
        {
            if(b[(i + 1) / 2] == 1) b2 ++ ;
            b1 -- ;
        }
         
        if(a2 - b2 > b1 || b2 - a2 > a1)
        {
        	cout << (i + 1) / 2 << endl;
            cout << a2 << ":" << b2 << endl;
            return ;
        }
        if(i == 10)
        {
            for (int j = 1; j <= 10; j ++ )
            {
            	if (a[(i + 1) / 2 + j] != b[i / 2 + j])
            	{
            		cout << (i + 1) / 2 + j << endl;
            		cout << a2 + a[(i + 1) / 2 + j] << ":" << b2 + b[(i + 1) / 2 + j] << endl;
                    return ;
            	}
            	else
            	{
            		a2 += a[i / 2 + j];
            		b2 += b[i / 2 + j];
            	}
            }
        }
	} 

}

int main()
{
    IOS;
    int t = 1;
    while(t -- )
        solve();

    return 0;
}
