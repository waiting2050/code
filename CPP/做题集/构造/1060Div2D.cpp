// Problem: CF 2154 D
// Contest: Codeforces - Codeforces Round 1060 (Div. 2)
// URL: https://codeforces.com/contest/2154/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// 1.删除无关紧要的叶子节点不会影响结果； 2.树是天然的二分图，因此每次移动dep的奇偶性必然不同
// 要找到唯一确定的路径，就得删除不确定的路径，因此尽可能想办法删除叶子结点，节点越少不确定度越小
// 删除的时候要注意：1.所在的节点不能删除；2.到目标节点的路径上的点不能删
// 于是将所有点染成两种颜色，每次删除另一种颜色的点，情况1就不会发生；记录每个点的出度，出度>=1就不是叶子结点
// 到目标路径的点的出度一定不为0

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int N = 2e5 + 7;

int cd[N], fa[N];
vector<int> g[N];
bitset<N> col;

void dfs(int x, int pre)
{
	for(auto& y : g[x])
	{
		if(y == pre) continue;
		fa[y] = x;		
		col[y] = col[x] ^ 1;
		cd[x]++;
		dfs(y, x);		
	}
}

void solve()
{
	int n; cin >> n;
	col.reset();
	for(int i = 1; i <= n; i++) g[i].clear();
	for(int i = 1; i <= n; i++) cd[i] = fa[i] = 0;
	
	for(int i = 1; i < n; i++)
	{
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	dfs(n, 0); // 反向遍历，确保目标路径上的点出度不为0，防止误删

	vector<int> lf[3];
	for(int i = 1; i <= n; i++) if(!cd[i]) lf[col[i]].push_back(i);
	
	vector<pair<int, int>> ans;
	int cl = col[1];
	for(int i = 1; i < n; i++) // 循环时从1出发后，1被不被删都无所谓了
	{
		if(lf[cl ^ 1].empty()) // 没有另一种颜色的叶子结点，先走一步
		{                      // 叶子节点是肯定存在的，只是某种颜色的点可能不存在
			ans.push_back({1, -1});
			cl ^= 1;
		}
		
		int nx = lf[cl ^ 1].back();
		lf[cl ^ 1].pop_back();
		ans.push_back({2, nx});
		
		cd[fa[nx]]--;
		if(!cd[fa[nx]]) lf[col[fa[nx]]].push_back(fa[nx]);
		
		ans.push_back({1, -1});
		cl ^= 1;
	}
	
	cout << ans.size() << '\n';
	for(auto& [x, y] : ans)
	{
		if(x == 1) cout << 1 << '\n';
		else cout << 2 << ' ' << y << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int _; cin >> _;
	while(_--) solve();

	return 0;
}

// 4
// 5
// 1 2
// 2 3
// 1 5
// 5 4
// 2
// 1 2
// 4
// 1 2
// 1 3
// 1 4
// 6
// 1 2
// 1 3
// 3 4
// 4 5
// 4 6
// 
// 2
// 2 2
// 1
// 
// 1
// 1
// 
// 5
// 2 2
// 1
// 1
// 2 3
// 1
// 
// 9
// 2 2
// 1
// 2 1
// 1
// 2 3
// 1
// 1
// 2 5
// 1
// =