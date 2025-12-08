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

const int N = 1e3 + 9;

struct Edge
{
	int x, w;//x是出点，w是权值
};

vector<Edge> g[N];	//注意g是二维的 
ll d[N], n, m;//d储存最短路，n个点，m条边
bitset<N> vis;//标志有没有走过

void dijkstra(int st)
{
	memset(d, 0x3f, sizeof(ll) * (n + 1));
	d[st] = 0;

	for (int i = 1; i <= n; i++)
	{
		 // 找出当前未被访问的顶点中，距离起始点最近的那个顶点u 
		int u = -1;
		for (int j = 1; j <= n; j++)//保证循环结束后，u被更新为距离元点最近且没被访问过的点
			if (!vis[j] && (u == -1 || d[j] < d[u])) u = j;//如果u被访问过，或者j没被访问过且元点到j的距离小于到u的距离，就更新u
														//因为每次找出来的u一定是最近的顶点，所以如果u被访问过 ，说明之前已经检查过u了 
		vis[u] = true;//表示u已经拓展过

		for (auto &ed : g[u])//更新路径，遍历从u开始的所有出边，找到最短路径并更新 
		{
			int v = ed.x,  w = ed.w;//v是点，w是权值，也就是路径长
			d[v] = min(d[v], d[u] + w);//如果当前点未被修改，并且新路径更好，就更新
		}//因为有!vis[v]，所以之前更新过的路径都会被跳过，实际这个循环只更新了一个点或者没更新
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

	cout << (d[n] >= 0x3f3f3f3f3f3f3f3f ? -1 : d[n]);//如果不能到达，就输出-1；否则输出路径长 

	return 0;
}
//3 3
//1 2 5
//2 3 2
//1 3 10
//
//7
