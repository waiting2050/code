#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define pb push_back

const int INF = 0x3f3f3f3f;
const int N = 1e3 + 7;

struct Edge
{
	ll v, w;
	
	bool operator<(const Edge& p) const
	{
		return w > p.w;
	}
};

vector<Edge> g[N];
ll n, d[N], c[N];
bitset<N> vis;

void dijsktra(int st)
{
	priority_queue<Edge> pq;
	for(int i = 1; i <= n; ++i) d[i] = INF;
	pq.push({st, d[st] = 0});
	
	while(pq.size())
	{
		ll x = pq.top().v; pq.pop();
		
		if(vis[x]) continue;
		vis[x] = 1;
		
		for(auto& y : g[x])
		{
			if(d[y.v] > d[x] + y.w)
			{
				d[y.v] = d[x] + y.w;
				pq.push({y.v, d[y.v]});
			}
		}
	}
}

int dfs(int st, int ed)
{
	if(c[st] != -1) return c[st];
	if(st == ed) return 1;
	
	int cnt = 0;
	for(auto& y : g[st])
	{
		int v = y.v;
		if(d[v] < d[st]) cnt += dfs(v, ed);
	}
	
	return c[st] = cnt;
}

void solve()
{
	int m; cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		int u, v, w; cin >> u >> v >> w;
		g[u].pb({v, w}), g[v].pb({u, w});
	}
	int st, ed; cin >> st >> ed;
	
	dijsktra(ed);
	
	if(d[st] == INF)
	{
		cout << -1;
		return;
	}
	
	for(int i = 1; i <= n; ++i) c[i] = -1;
	
	cout << dfs(st, ed);
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int _ = 1;
	while(_--) solve();

	return 0;
}

// 4  4
// 1 4 5
// 1 3 3
// 2 3 10
// 2 4 10
// 1 2

// 2