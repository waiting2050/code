// Problem: 小苯的xor图
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/115861/E
// Memory Limit: 2048 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//一条长度为2的简单路径，只要中间节点不同就是一条新路，比如ABC和BAC。因为节点虽然一样，但是方向不同，但ABC和CBA是一样的。 

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 7, P = 998244353;

vector<int> g[N];
int a[N];
ll ans;
bitset<N> vis;

void dfs(int x) //为什么dfs不写成dfs(x, pre)，因为这道题是可能有环的，用vis标记不用担心环 
{
	if(vis[x]) return;
	vis[x] = 1;
	
	for(auto& y : g[x]) dfs(y);
	
	for(int i = 30; i >= 0; i--) //这个循环放外面，c数组可以只开2维。对于每一位，遍历所有节点 
	{
		int c[2] = {0, 0};
		for(auto& y : g[x]) //贡献法，对于每个新节点与中心节点异或后的当前位，查找出现过的对应节点的数量，计算并统计 
		{												//对应节点：当前位与1异或后的数字。1是目标数字，只有为1才需要修改 
			int mask = a[x] >> i & 1;
			int cur = a[y] >> i & 1;
			cur ^= mask;
			
			ans = (ans + (1ll << i) * c[cur ^ 1]) % P; //注意1优先级问题，括号里的先算可能导致爆int 
			c[a[y] >> i & 1]++;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, m; cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	for(int i = 1; i <= m; i++)
	{
		int u, v; cin >> u >> v;
		g[u].push_back(v), g[v].push_back(u);
	}
	
	dfs(1);
	
	cout << ans;
	
	return 0;
}

// 5 5
// 1 2 3 4 5
// 1 3
// 1 5
// 1 2
// 2 5
// 2 4
// 
// 
// 35
