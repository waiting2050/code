#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 3e3 + 7;

vector<int> g[N];
int vis[N], dfn, p[N]; //p[i]表示编号为i的人对应的男友 

//能都成功配对 
bool dfs(int x)
{
	for(auto& y : g[x])
	{
		if(vis[y] == dfn) continue; //如果下一个节点在本轮更新过了，就跳过 
		vis[y] = dfn; //否则在本轮更新
		
		if(!p[y] || dfs(p[y])) //如果没有匹配的，或者已匹配的可以更换 
		{
			p[y] = x; //那就牛了 
			return true;
		}
	}
	
	return false; //配对失败 
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
		dfn++; //每一个dfn代表不同的轮次，用于简化vis数组的清除 
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
