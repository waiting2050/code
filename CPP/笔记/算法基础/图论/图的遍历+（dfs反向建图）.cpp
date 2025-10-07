// Problem: Luogu P3916
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3916
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 7;

vector<int> g[N];
int d[N];

void dfs(int x, int pre)
{
	if(d[x]) return;//类似于记忆化搜索 
	d[x] = pre;
	for(auto& y : g[x]) dfs(y, pre);
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, m; cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		int u, v; cin >> u >> v;
		if(u ^ v) g[v].push_back(u);//注意细节：反向建图 
	}
	
	//如果正向建图并且遍历可能会爆栈，而且会重复更新多次 
	//因为问的是最大节点，于是反向遍历，从大到小更新，确保只要更新就一定是最优 
	for(int i = n; i >= 1; i--) dfs(i, i);
	
	for(int i = 1; i <= n; i++) cout << d[i] << ' ';
	
	return 0;
}

//4 3
//1 2
//2 4
//4 3
//
//4 4 3 4 
