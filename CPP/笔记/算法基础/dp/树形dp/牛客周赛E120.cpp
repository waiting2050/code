// Problem: 无穷无尽的树
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/123788/E
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// 其实类似于求树的直径，状态转移如果有新的最大值，就继承->cnt[x]=cnt[y]；否则相等的话个数增加cnt[x]+=cnt[y]。
// 比较麻烦的点在于怎么先删除叶子节点，这里用一个状态dp去标记。

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define pb push_back

const int N = 2e5 + 7;

vector<int> g[N];
int dp[N], cnt[N];

void dfs(int x, int pre)
{
	if(g[x].size() == 1 && x ^ 1)
	{
		dp[x] = -1;
		return;
	}
	
	cnt[x] = 1; // 虽然会给所有非叶节点都赋值为1，但是后面dp[y]一定>mx
	int mx = 0;     // 所以如果是新的叶节点，会被赋值为1；如果不是，就会被正确子节点更新。所以实际cnt[x]=1只对新的叶子结点有用
	for(auto& y : g[x])
	{
		if(y == pre) continue;
		
		dfs(y, x);
		
		if(dp[y] != -1)
		{
			if(dp[y] > mx) mx = dp[y], cnt[x] = cnt[y];
			else if(dp[y] == mx) cnt[x] += cnt[y];
		}
	}
	dp[x] = mx + 1;
}

void solve()
{
	int n; cin >> n;
	for(int i = 1; i < n; ++i)
	{
		int u, v; cin >> u >> v;
		g[u].pb(v), g[v].pb(u);
	}
	
	dfs(1, 0);
	
	for(int i = 1; i <= n; ++i) cout << cnt[i] << ' ';
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int _ = 1;
	while(_--) solve();

	return 0;
}

// 6
// 1 2
// 2 3
// 2 4
// 4 5
// 3 6

// 2 2 1 1 0 0