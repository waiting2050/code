#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//跟普通的dijkstra比起来只是多了一个c计数数组 

const int N = 1e6 + 7, MOD = 100003;
struct Edge
{
	int x, w;
	
	bool operator < (const Edge& p) const
	{
		return w > p.w;
	}
};
vector<Edge> g[N];
int d[N], c[N];
bitset<N> vis;

void dijkstra(int st)
{
	memset(d, 0x3f, sizeof(d));
	
	priority_queue<Edge> pq;
	pq.push({st, d[st] = 0});
	c[st] = 1;//初始化 
	
	while(pq.size())
	{
		int x = pq.top().x; pq.pop();
		
		if(vis[x]) continue;
		vis[x] = 1;
		
		for(auto& y : g[x])
		{
			if(d[y.x] > d[x] + y.w)
			{
				d[y.x] = d[x] + y.w;
				pq.push({y.x, d[y.x]});
			}
			//相当于判断到子节点是不是最短，如果是，把上一个点到子节点的路径数都加上 
			if(d[y.x] == d[x] + y.w) c[y.x] = (c[y.x] + c[x]) % MOD;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, m; cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		int u, v; cin >> u >> v;
		g[u].push_back({v, 1});//不用处理重边或自环，dijkstra算法会自己排除(vis) 
		g[v].push_back({u, 1});
	}
	
	dijkstra(1);
	
	for(int i = 1; i <= n; i++)
		cout << c[i] << '\n';
	
	return 0;
}

//5 7
//1 2
//1 3
//2 4
//3 4
//2 3
//4 5
//4 5
//
//1
//1
//1
//2
//4
