// Problem: Luogu P1807
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1807
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1500 + 7;

struct P
{
	int v, w;
};
vector<P> g[N];
int dp[N], rd[N];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	memset(dp, 128, sizeof(dp));//将除了1以外的点初始化为负无穷，确保每个节点只能由1来的路径更新 
	dp[1] = 0;

	int n, m; cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		int u, v, w; cin >> u >> v >> w;
		g[u].push_back({v, w});
		rd[v]++;
	}
	
	queue<int> q;
	for(int i = 1; i <= n; i++) if(!rd[i]) q.push(i);
	
	while(q.size())
	{
		int t = q.front(); q.pop();
		
		for(auto& [x, y] : g[t])
		{
			dp[x] = max(dp[x], dp[t] + y);
			rd[x]--;
			if(!rd[x]) q.push(x);
		}
	}
	
	cout << (dp[n] < -2e9 ? -1 : dp[n]);
	
	return 0;
}

//2 1
//1 2 1
//
//1
//
//2 0
//
//-1
