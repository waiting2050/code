// Problem: CF 2167 F
// Contest: Codeforces - Codeforces Round 1062 (Div. 4)
// URL: https://codeforces.com/contest/2167/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// 题目就是让你求以每个节点为根，以任意k个点为一组，求每组的lca，再将所有lca放入一个集合，最后得到集合的size，
// 轮完以后，一共有n个根，那么有n个size，将其求和即为所求。
// 有这么一种朴素的想法，计算以每个为根时，每个节点的size，size>=k则一定有其为lca的情况，但是这样每个节点都要跑一遍dfs
// 与其以每个节点为根，然后求不同的lca个数，不如计算以每个节点为lca，该lca能为多少根节点做贡献，有三种情况
// 1.以这个点为子树，求出其size，只要size>=k,其对根节点路径上的所有点都有贡献
// 2.只要所有节点数>=k，就对该点本身有贡献
// 3.根节点路径上树的size+1（本身）>=k，就对子节点有贡献
// 为了提高效率，求size只跑一遍dfs

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define pb push_back

const int N = 2e5 + 7;

vector<int> g[N];

int n, k, sz[N];

ll dfs(int x, int pre)
{
	ll res = 0;
	sz[x] = 1;
	for(auto& y : g[x])
	{
		if(y == pre) continue;
		res += dfs(y, x);
		sz[x] += sz[y];
	}
	
	if(n >= k) res++;
	if(sz[x] >= k) res += n - sz[x];
	for(auto& y : g[x])
	{
		if(y == pre) continue;
		if(n - sz[y] >= k) res += sz[y];
	}
	
	return res;
}

void solve()
{
	cin >> n >> k;
	for(int i = 1; i <= n; i++) g[i].clear();
	for(int i = 1; i <= n; i++) sz[i] = 0;
	
	for(int i = 1; i < n; i++)
	{
		int u, v; cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	
	cout << dfs(1, 0) << '\n';
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int _; cin >> _;
	while(_--) solve();

	return 0;
}

// 4
// 2 2
// 1 2
// 5 3
// 1 2
// 1 3
// 1 4
// 1 5
// 6 3
// 1 2
// 1 3
// 2 4
// 2 5
// 3 6
// 10 5
// 5 6
// 4 9
// 3 9
// 2 6
// 2 8
// 8 9
// 6 10
// 1 6
// 4 7


// 2
// 9
// 17
// 35