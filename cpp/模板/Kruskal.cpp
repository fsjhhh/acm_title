#include <iostream>
#include <cstring>
#include <algorithm>
#define IOS ios::sync_with_stdio(0); \
			cin.tie(0);              \
			cout.tie(0);
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

const int N = 2e5 + 10;
int p[N], n, m; // ���鼯 

struct Edgs // �ṹ���ͼ 
{
	int a, b, w;
}edgs[N];

bool cmp(Edgs x, Edgs y) // sort���cmp���� 
{
	return x.w < y.w;
}

int find(int x) // ���鼯find���� 
{
	if(p[x] != x) p[x] = find(p[x]);
	return p[x];
}

void solve()
{
	cin >> n >> m;
	for(int i = 1; i <= m; i ++ )
	{
		int a, b, w;
		cin >> a >> b >> w;
		edgs[i] = {a, b, w};
	}
	
	sort(edgs + 1, edgs + m + 1, cmp); // ��Ȩ������ 
	
	for(int i = 1; i <= n; i ++ ) p[i] = i; // ���鼯��ʼ�� 
	
	int res = 0, cnt = 0;
	for(int i = 1; i <= m; i ++ )
	{
		int a = edgs[i].a, b = edgs[i].b, w = edgs[i].w;
		
		a = find(a), b = find(b);
		
		if(a != b) // a, b����ͬһ�����鼯�� �ͽ����Ǽ���ͬһ���鼯�� 
		{
			p[a] = b;
			res += w;
			cnt ++ ;
		}
	}
	
	if(cnt < n - 1) cout << "impossible" << endl; // �����ı�С��n - 1 �ʹ������е㲻����ͨ�� 
	else cout << res << endl;
	
}

int main()
{
	IOS;
	int t = 1;
	while(t -- )
		solve();
		
	return 0;
}

