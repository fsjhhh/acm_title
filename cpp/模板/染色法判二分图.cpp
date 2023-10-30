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

const int N = 1e5 + 10;
int h[N], e[2 * N], ne[2 * N], idx;
int color[N], n, m; 

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

bool dfs(int u, int c)// �Ϸ�����true ���Ϸ�����false 
{
	color[u] = c;
	for(int i = h[u]; i != -1; i = ne[i]) // ������������� 
	{
		int j = e[i];
		if(!color[j]) // �����ǰ��δȾɫ�ͽ���Ⱦɫ���ж��Ƿ�Ϸ� 
		{
			if(!dfs(j, 3 - c))
				return false;
		}
		else if(color[j] == c)// ����Ѿ�Ⱦɫ�� ���ж����ڵ��������ڵ���ɫ�Ƿ���ͬ 
		{
				return false;
		}
	}
	return true;
}

void solve()
{
	// ������ͼ����Ⱦɫ
	// �������ڵ�֮�䲻������ͬ��ɫ
	// �����ܳ�����������1 ����ף� 2 �����
	// ������: 1(1) -> 2(2) -> 3(1) -> 1(2) ����1ì�� ���Բ��ܳ��������� 
	// �ж��Ƿ�Ϸ����ж��Ƿ��������� 
	
	memset(h, -1, sizeof h);
	cin >> n >> m;
	
	while(m -- )
	{
		int a, b;
		cin >> a >> b;
		add(a, b), add(b, a);
	}
	
	bool pd = true; // �Ƕ���ͼΪtrue ����Ϊfalse 
	for(int i = 1; i <= n; i ++ ) // ѭ��ÿ���ڵ� 
	{
		if(!color[i]) // �����ǰ��δȾɫ 
		{
			if(!dfs(i, 1)) // ����Ϳɫ�� ���ж��Ƿ�Ϸ� 
			{
				pd = false;
				break;
			}
		}
	}
	
	if(pd) cout << "Yes" << endl;
	else cout << "No" << endl;
	
}

int main()
{
	IOS;
	int t = 1;
	while(t -- )
		solve();
		
	return 0;
}

