#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 3e3 + 7;

vector<int> g[N];
int vis[N], dfn, p[N]; //p[i]��ʾ���Ϊi���˶�Ӧ������ 

//�ܶ��ɹ���� 
bool dfs(int x)
{
	for(auto& y : g[x])
	{
		if(vis[y] == dfn) continue; //�����һ���ڵ��ڱ��ָ��¹��ˣ������� 
		vis[y] = dfn; //�����ڱ��ָ���
		
		if(!p[y] || dfs(p[y])) //���û��ƥ��ģ�������ƥ��Ŀ��Ը��� 
		{
			p[y] = x; //�Ǿ�ţ�� 
			return true;
		}
	}
	
	return false; //���ʧ�� 
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, m, k; cin >> n >> m >> k;
	while(k--)
	{
		int x, y; cin >> x >> y;
		g[x].push_back(y);
	}
	
	int sum = 0;
	for(int i = 1; i <= n; i++)
	{
		dfn++; //ÿһ��dfn����ͬ���ִΣ����ڼ�vis�������� 
		if(dfs(i)) sum++;
	}
	
	cout << sum;
	
	return 0;
}

// 3 4 5
// 1 1
// 1 2
// 1 3
// 2 1
// 3 4
// 
// 3
