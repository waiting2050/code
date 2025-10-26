// Problem: AT ABC429 E
// Contest: AtCoder - Polaris.AI Programming Contest 2025（AtCoder Beginner Contest 429）Polaris.AI 编程竞赛 2025（AtCoder 初学者竞赛 429）
// URL: https://atcoder.jp/contests/abc429/tasks/abc429_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// 这道题必须经过两个安全节点和一个危险节点。那朴素的想，不如对每一个危险节点，去找两个最近的安全节点。
// 但是这样时间复杂度太高，那不如反过来，由每一个安全节点往外扩散，每扩散到一个点，若这个点最近安全距离没更新则
// 由这个点更新，同理更新第二近安全节点（注意最近与第二近节点不同，可以用辅助数组记录节点编号），最后对每个危险节点记录距离和即可

// 于是需要两个数组，一个记录距离，一个记录上游节点编号，bfs队列需要存结构体，也需要距离和上游节点编号，还需要当前节点编号

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define pb push_back

const int N = 2e5 + 7;

// from：记录上游节点，即从哪个安全节点转移而来；to：当前节点
struct P
{
	int from, to;
	int dis;
};

int f[N][2], d[N][2];

vector<int> g[N];

void solve()
{
	int n, m; cin >> n >> m;
	while(m--)
	{
		int u, v; cin >> u >> v;
		g[u].pb(v), g[v].pb(u);
	}
	
	queue<P> q;
	string s; cin >> s;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == 'S')
		{
			q.push({i + 1, i + 1, 0});
			f[i + 1][0] = i + 1;
		}
	}
	
	while(q.size())
	{
		auto [from, to, dis] = q.front(); q.pop(); // 这里千万别加引用，不然re
		
		for(auto& y : g[to])
		{
			if(!f[y][0])
			{
				f[y][0] = from;
				d[y][0] = dis + 1;
				q.push({from, y, dis + 1});
			}
			else if(!f[y][1] && f[y][0] != from)
			{
				f[y][1] = from;
				d[y][1] = dis + 1;
				q.push({from, y, dis + 1});
			}
		}
	}
	
	for(int i = 1; i <= n; i++) if(s[i - 1] == 'D') cout << d[i][0] + d[i][1] << '\n';
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int _ = 1;
	while(_--) solve();

	return 0;
}

// 5 5
// 1 2
// 1 3
// 2 3
// 3 4
// 4 5
// SSDDS

// 2
// 3


// 3 2
// 1 2
// 2 3
// SSD

// 3