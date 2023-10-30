#include<iostream>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<cmath>

using namespace std;

typedef pair<int,int> PII;
typedef pair<long long,long long> PLL;
typedef long long ll;
typedef __int128 z;
const int N=1e5+10,INF=0x3f3f3f3f,mod=998244353;

z ksm(z a,z b,z p=mod)
{
    z res=1;
    while(b)
    {
        if(b&1) res=(res*a)%p;
        b>>=1;
        a=(a%p*a%p)%p;
    }
    return res%p;
}

void solve()
{
    ll n;
    cin>>n;

    if(n==2)
    {
        cout << 7 <<endl;
        return ;
    }
    
    ll t = (ksm(n % mod, n) - (n - 1) % mod + mod) % mod;

    cout<< t % mod << "\n";

}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    //cin>>t;

    while(t--)
      solve();

    return 0;
}