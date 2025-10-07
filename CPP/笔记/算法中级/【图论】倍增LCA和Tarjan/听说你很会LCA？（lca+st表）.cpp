#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//如果只用循环跑lca，复杂度到nq，所以考虑每次只跑一次lca，对象为范围里dfn序最大和最小
//最值可以用st表维护，但是要考虑清楚题目给的编号和dfn序之间的转换，用两个哈希表完成 

const int N = 2e5 + 7, T = 20;

vector<int> g[N];
int dep[N], fa[N][30], idx, stmi[N][30], stmx[N][30], mp[N], lg2[N], id[N];

void dfs(int x)
{
	dep[x] = dep[fa[x][0]] + 1;
	mp[x] = ++idx;
	id[idx] = x;
	
	for(int i = 1; i <= T; i++)
		fa[x][i] = fa[fa[x][i - 1]][i - 1];
	
	for(auto& y : g[x]) dfs(y);
}

int lca(int x, int y)
{
	if(dep[x] < dep[y]) swap(x, y);
	
	for(int i = T; i >= 0; i--)
		if(dep[fa[x][i]] >= dep[y]) x = fa[x][i];
	
	if(x == y) return x;
	for(int i = T; i >= 0; i--)
		if(fa[x][i] ^ fa[y][i]) x = fa[x][i], y = fa[y][i];
	
	return fa[x][0];
}

int getmin(int l, int r)
{
	int k = lg2[r - l + 1];
	return min(stmi[l][k], stmi[r - (1 << k) + 1][k]);
}

int getmax(int l, int r)
{
	int k = lg2[r - l + 1];
	return max(stmx[l][k], stmx[r - (1 << k) + 1][k]);
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	for(int i = 2; i <= n; i++) lg2[i] = lg2[i >> 1] + 1;
	
	for(int i = 2; i <= n; i++)
	{
		cin >> fa[i][0];
		g[fa[i][0]].push_back(i);
	}
	
	dfs(1);
	for(int i = 1; i <= n; i++) stmi[i][0] = stmx[i][0] = mp[i];
	for(int j = 1; j <= lg2[n]; j++)
	{
		for(int i = 1; i + (1 << j) - 1 <= n; i++)
		{
			stmi[i][j] = min(stmi[i][j - 1], stmi[i + (1 << (j - 1))][j - 1]);
			stmx[i][j] = max(stmx[i][j - 1], stmx[i + (1 << (j - 1))][j - 1]);
		}
	}
	
	int q; cin >> q;
	while(q--)
	{
		int l, r; cin >> l >> r;
		int u = id[getmin(l, r)], v = id[getmax(l, r)];
		
		cout << lca(u, v) << '\n';
	}
	
	return 0;
}

// 5 
// 1 1 2 2
// 3
// 2 3
// 4 5
// 5 5
// 
// 1
// 2
// 5
