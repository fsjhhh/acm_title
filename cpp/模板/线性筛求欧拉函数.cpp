#include <iostream>
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
#define IOS ios::sync_with_stdio(0); \
			cin.tie(0);              \
			cout.tie(0);
using namespace std;

const int INF = 0x3f3f3f3f;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

const int N = 1e6 + 10;
LL prime[N], phi[N], cnt = 0;
bool st[N];

// N��ŷ������ = N(1 - 1 / p1)(1 - 1 / p2) ������ (1 - 1 / pk);
// p1, p2, p3, ������ , pk ΪN��������

LL get_oula(int n) // ��ŷ������
{
    phi[1] = 1; // 1��ŷ��������1
    for(int i = 2; i <= n; i ++ ) // ����ɸ
    {
        if(!st[i]) prime[cnt ++ ] = i, phi[i] = i - 1; // ����������ʹ洢�� ������ŷ��������������һ
        for(int j = 0; prime[j] <= n / i; j ++ ) // ��������
        {
            st[prime[j] * i] = true; // ����С������prime[j]ɸ��prime[j] * i
            if(i % prime[j] == 0) // ���i��prime[j]�ı���prime[j] * i����������С������ɸ��
            {
                phi[prime[j] * i] = phi[i] * prime[j]; // prime[j] * i��ŷ��������phi[i] * prime[j];
                                                       // i % prime[j] == 0; phi[i] �г���(1 - 1 / prime[j])
                                                       // phi[prime[j] * i] = phi[i] * prime[j];
                break;
            }
            phi[prime[j] * i] = phi[i] * (prime[j] - 1); // prime[j] * i��ŷ��������phi[i] * (prime[j] - 1)
                                                         // i % prime[j] != 0; phi[i]��û�г�(1 - 1 / prime[j]);
                                                         // phi[prime[j] * i] = phi[i] * prime[j] * (1 - 1 / prime[j])
                                                         // phi[prime[j] * i] = phi[i] * (prime[j] - 1);
        }
    }
    
    LL res = 0;
    for(int i = 1; i <= n; i ++ ) // ���
        res += phi[i];
    return res;
}

void solve()
{
	int n;
	cin >> n;
	LL res = get_oula(n);
	
	cout << res << endl;
}

int main()
{
	IOS;
	int t = 1;
	while(t -- )
		solve();
		
	return 0;
}

