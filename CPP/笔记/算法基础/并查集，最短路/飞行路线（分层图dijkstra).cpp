#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e4 + 7;
int dis[N][17];//i表示节点数，j表示使用的免费卷数量

//分层图dijkstra，多了一个cnt表示使用了的免费卷数量 
struct Edge
{
	int x, w, cnt;
	
	bool operator < (const Edge& p) const
	{
		return w > p.w;
	}
};
vector<Edge> g[N];
int n, m, k;

void dijkstra(int st)
{
	bitset<17> vis[N];//注意这里N是一维，17是二维 
	priority_queue<Edge> pq;
	
	memset(dis, 0x3f, sizeof(dis));
	pq.push({st, dis[st][0] = 0, 0});
	
	while(pq.size())
	{
		int t = pq.top().x, ct = pq.top().cnt; pq.pop();
		
		if(vis[t][ct]) continue;
		vis[t][ct] = 1;
		
		for(auto& y : g[t])
		{
			//为什么两个if:因为可以选择用或不用
			//最大的变化一个是数组多了一维，另一个是多了这个if 
			if(ct < k && dis[y.x][ct + 1] > dis[t][ct] + 0)//这个+0可以替换（比如把免费改成半价，就变成+y.w/2） 
			{
				dis[y.x][ct + 1] = dis[t][ct] + 0;
				pq.push({y.x, dis[y.x][ct + 1], ct + 1});
			}
			if(dis[y.x][ct] > dis[t][ct] + y.w)
			{
				dis[y.x][ct] = dis[t][ct] + y.w;
				pq.push({y.x, dis[y.x][ct], ct});
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> n >> m >> k;
	int s, t; cin >> s >> t;
	
	for(int i = 1; i <= m; i++)
	{
		int a, b, c; cin >> a >> b >> c;
		g[a].push_back({b, c});
		g[b].push_back({a, c});
	}
	
	dijkstra(s);
	
	int ans = 0x7f7f7f7f;
	for(int i = 0; i <= k; i++) ans = min(ans, dis[t][i]);//注意这里是从0到k 
	
	cout << ans;
	
	return 0;
}

