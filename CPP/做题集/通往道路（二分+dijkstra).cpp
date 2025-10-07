#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e4 + 7;
int v[N], d[N], n, b;
struct Edge
{
	int x, w;
	
	bool operator < (const Edge& p) const
	{
		return w > p.w;
	}
};
vector<Edge> g[N];
bitset<N> vis;

bool dijkstra(int st, int mid)
{
	//�ж�ε��ã��ǵó�ʼ�� 
	vis.reset();
	memset(d, 0x3f, sizeof(d));
	
	priority_queue<Edge> pq;
	pq.push({st, d[st] = 0});

	while(pq.size())
	{
		int x = pq.top().x; pq.pop();
		
		if(vis[x]) continue;
		vis[x] = 1;
		if(v[x] > mid) continue;//����һ�ζԼ۸���ж� 
		
		for(auto& y : g[x])
		{
			if(d[y.x] > d[x] + y.w)
			{
				d[y.x] = d[x] + y.w;
				pq.push({y.x, d[y.x]});
			}
		}
	}
	
	return (d[n] <= b ? 1 : 0);
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int m, l, r = 0; cin >> n >> m >> b;
	for(int i = 1; i <= n; i++)
	{
		cin >> v[i];
		r = max(r, v[i]);
	}
	l = max(v[1], v[n]);
	
	for(int i = 1; i <= m; i++)
	{
		int u, v, w; cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	
	//��ֹl��r��ȵ��������tle 
	if(l == r)
	{
		if(dijkstra(1, r)) cout << r;
		else cout << "AFK";
		
		return 0;	
	}
	
	while(l + 1 != r)
	{
		int mid = (l + r) >> 1;
		if(dijkstra(1, mid)) r = mid;
		else l = mid;
	}
	
	//�߽������Ҫ�ر��ǣ���Ϊ��Ϊl��r�����п��ܵ� 
	if(dijkstra(1, l)) cout << l;
	else if(dijkstra(1, r)) cout << r;
	else cout << "AFK";
	
	return 0;
}

//4 4 8
//8
//5
//6
//10
//2 1 2
//2 4 1
//1 3 4
//3 4 3
//
//10
