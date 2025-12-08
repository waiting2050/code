#include <iostream>
#include <cstdio>
#include <string>
#include <climits>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <random>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
using namespace std;
using ll = long long;

const int N = 2e5 + 9;

struct Edge
{
	ll x, w;//x是出点，w是权值

	bool operator<(const Edge& v)const
	{
		return w == v.w ? x<v.x : w>v.w;//优先队列按照升序排列,优先队列是反的
	}
};

vector<Edge> g[N];
ll d[N], n, m;//d储存最短路，n个点，m条边
bitset<N> vis;//标志有没有走过
//只能处理单源最短路，即从一个点到各个点的距离 
void dijkstra(int st)
{
	memset(d, 0x3f, sizeof(ll) * (n + 1));
	d[st] = 0;

	priority_queue<Edge> pq;
	pq.push({st, d[st]});

	while (pq.size())
	{
		int x = pq.top().x; pq.pop();//只要出点就好，优先队列可以自己实现取出距离源点最近的点

		if (vis[x]) continue;//防止重复入队，因为优先队列的性质，导致第一次处理的点一定是最短的，之后重复入队的点直接跳过即可
		vis[x] = true;

		for (auto& ed : g[x])//以g[x]为出点，遍历它所能到达的所有点
		{
			int y = ed.x, w = ed.w;
			if (!vis[y] && d[y] > d[x] + w)
			{
				d[y] = d[x] + w;
				pq.push({ y, d[y]});
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v, w; cin >> u >> v >> w;
		if (u ^ v) g[u].push_back({ v, w });//防止自环
	}

	dijkstra(1);

	cout << (d[n] >= 0x3f3f3f3f ? -1 : d[n]);

	return 0;
}
//3 3
//1 2 5
//2 3 2
//1 3 10
//
//7
