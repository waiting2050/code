#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 7;

vector<int> g[N];
int dfn[N], low[N], idx, cut, es;

//��������Ҫ��ȷ����������������ͼ�У�����������ͼ���ж�ǿ��ͨ����û�����壨��Ϊ����һ����
//�����ͨ��һ����ǿ��ͨ�ģ����������ǲ���Ҫcol��stk��Ҳ����Ҫtot,top��

//�����ȶ���һ��x��"���ض���y������˼��y�������У�����������һ������Իص�x�ĸ�������

//������������ 
//1.��c�Ǵ˴�tarjan�ĸ�����ôcֻҪ�������������ϵĲ��ض���y���Ϳ���˵������һ�����
//2.��r���Ǵ˴�tarjan�ĸ�����ôcֻ��Ҫ����һ�����ض��ӣ������丸��������ͨ�鹹����һ�����ض��ӣ����Ϳ���˵��c��һ�����
//ps:��Ҫע�⣬���ǵ�tarjan���̻ṹ��һ����������ֻ������!dfny�Ķ���y���ܱ�����Ϊ���ӣ������ʸ��ж��Ƿ���"���ض���"

//��ߣ� 
//���߷ǳ��򵥣�������tarjan�Ĺ����У����߸��������رߣ�Ȼ���ж϶��ӽ���Ƿ���һ����������
//�����Ķ��ӣ��������ڲ��γ���һ���������Լ��������޹ص�ǿ��ͨ�������ȼ���low[y]��df[x])���ɡ�

void tarjanp(int x, int pre)
{
	dfn[x] = low[x] = ++idx;
	
	int child = 0;
	for(auto& y : g[x])
	{
		if(y == pre) continue;
		if(!dfn[y]) 
		{
			tarjanp(y, x);
			low[x] = min(low[x], low[y]);
			child += low[y] >= dfn[x]; 
		}
		else low[x] = min(low[x], dfn[y]);
	}
	
	if(child >= 2 && !pre || child && pre) cut++;
}


void tarjans(int x, int pre)
{
	dfn[x] = low[x] = ++idx;
	
	for(auto& y : g[x])
	{
		if(y == pre) continue;
		if(!dfn[y]) 
		{
			tarjans(y, x);
			low[x] = min(low[x], low[y]);
			es += low[y] > dfn[x]; //���y���ص������������� 
		}
		else low[x] = min(low[x], dfn[y]);
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, m; cin >> n >> m;
	while(m--)
	{
		int x, y; cin >> x >> y;
		g[x].push_back(y), g[y].push_back(x);
	}
	
	tarjanp(1, 0);
	
	idx = 0;
	for(int i = 1; i <= n; i++) dfn[i] = low[i] = 0;
	tarjans(1, 0);
	
	cout << cut << ' ' << es;
	
	return 0;
}

//4 4
//1 2
//3 2
//2 4
//1 3
//
//1 1
