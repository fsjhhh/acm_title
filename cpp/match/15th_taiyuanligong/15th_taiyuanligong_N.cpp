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
#define IOS std::ios::sync_with_stdio(false); \
            std::cin.tie(0);              \
            std::cout.tie(0);

typedef long long LL;
typedef std::pair<int, int> PII;
typedef std::pair<LL, LL> PLL;
const int INF = 0x3f3f3f3f;
const LL INFL = 0x3f3f3f3f3f3f3f3f;

char a[15], b[15], ans[15];

std::vector<int> add(std::vector<int> A,std::vector<int> B)
{
    std::vector<int> C;
    int t=0;
    for(int i=0;i<A.size()||i<B.size();i++)
    {
        if(i<A.size()) t+=A[i];
        if(i<B.size()) t+=B[i];
         C.push_back(t%10);
        t/=10;
        
    }
    if(t) C.push_back(t);
    return C;
    
}

void solve()
{
	std::cin >> a >> b;
	int n = strlen(a);
	int m = strlen(b);
	int t = std::min(n, m);
    int t2, pd1 = 0, pd2 = 0;
    if (n >= m)
    {
        t2 = n;
        pd1 = 1;
    }
    else
    {
        t2 = m;
        pd2 = 1;
    }
    int j = 0;
    std::vector<int> a1, a2;
    for (int i = t - 1; i >= 0; i -- )
    {
        a1.push_back(a[i] - '0');
        a2.push_back(b[i] - '0');
    }
    std::vector<int> c = add(a1, a2);
    for (int i = c.size() - 1; i >= 0; i -- )
        std::cout << c[i];
    for (int i = t; i < t2; i ++ )
    {
        if (pd1)
            std::cout << a[i];
        else
            std::cout << b[i];
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
