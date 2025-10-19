#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 7;

vector<int> g[N];
int col[N];

bool dfs(int x)
{
	for(auto& y : g[x])
	{
		if(col[y] == -1) // col����ͬʱҲ��vis��������� 
		{
			col[y] = col[x] ^ 1;
			if(!dfs(y)) return false;
		}
		else if(col[x] == col[y]) return false;
	}
	
	return true;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, m; cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	for(int i = 1; i <= n; i++) col[i] = -1; // �����е���Ϊδ���ʣ���ΪҪ�����������ʣ����Գ�ֵ��Ϊ0 
	
	bool flag = false;
	for(int i = 1; i <= n; i++) // ��Ϊͼ��һ����ͨ������Ҫ����ÿ���� 
	{
		if(col[i] == -1)
		{
			col[i] = 0;
			if(!dfs(i)) flag = true; // ֻҪ��һ�鲻�Ƕ���ͼ���ͱ��Ϊtrue 
		}
	}
	
	cout << (flag ? "NO\n" : "YES\n");
	
	return 0;
}

// 4 4
// 1 2 
// 2 3
// 3 1
// 1 4
// 
// NO
// 
// 
// 4 4
// 1 2 
// 2 3
// 3 4
// 1 4
// 
// YES
