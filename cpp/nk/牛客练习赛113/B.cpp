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

const int mod = 1e9 + 7;
std::string s;

void solve()
{
    LL ans = 1;
    int cnt = 0;
    std::cin>>s;
    int f=0;
    for(int i=0,j=s.size()-1;i<=j;i++,j--)
    {
        if(s[i]=='?'&&s[j]=='?')cnt++;
        if(s[i]!='?'&&s[j]!='?'&&s[i]!=s[j]){ans=0;f=1;break;}
    }
    if(f==1){std::cout<<0<<std::endl;return ;}
    LL sum=1;
    if(!cnt)std::cout<<ans<<std::endl;
    else
    {
        for(int i=0;i<cnt;i++)
        sum=(sum*26)%mod;
    std::cout<<sum%mod;
    }
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

