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

const int N = 510, M = 1e5 + 10;
int h[N], e[M], ne[M], idx;
int match[N];
bool st[N];

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

bool find(int x)
{
	for(int i = h[x]; i != -1; i = ne[i]) // �������б� 
	{
		int j = e[i];
		if(!st[j]) // ���û���ҹ� 
		{
			st[j] = true; // ��Ϊ�ҹ� 
			if(match[j] == 0 || find(match[j])) // ���û����� �� ���Ů����Ե��������ҵ���һ���ͷ���true 
			{
				match[j] = x;
				return true;
			}
		}
	}
	return false; // ��������Ծͷ���false 
}

void solve()
{
	// �������㷨 �Ǹ���һ������ͼ�������ƥ������ 
	// ����Ϊ��Ůƥ�� 
	
	memset(h, -1, sizeof h);
	int n1, n2, m;
	cin >> n1 >> n2 >> m; // ����ͼ���������Լ����� ��Ⱦɫ�е�������ɫ��n1 Ϊ�У� n2 ΪŮ 
	while(m -- )
	{
		int a, b;
		cin >> a >> b;
		add(a, b);
	}
	
	int cnt = 0;
	for(int i = 1; i <= n1; i ++ ) // ������������ 
	{
		memset(st, false, sizeof st);  // ÿ��Ů��ֻ��һ�Σ���ÿ����֮ǰ��������Ů����Ϊδ�ҹ� 
		
		if(find(i)) // �������������п��ϵ�Ů��������i�йصı� �ܽ������cnt��һ 
			cnt ++ ;
	}
	
	cout << cnt << endl;
	
}

int main()
{
	IOS;
	int t = 1;
	while(t -- )
		solve();
		
	return 0;
}

