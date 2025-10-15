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
	ll x, w;//x�ǳ��㣬w��Ȩֵ

	bool operator<(const Edge& v)const
	{
		return w == v.w ? x<v.x : w>v.w;//���ȶ��а�����������,���ȶ����Ƿ���
	}
};

vector<Edge> g[N];
ll d[N], n, m;//d�������·��n���㣬m����
bitset<N> vis;//��־��û���߹�
//ֻ�ܴ���Դ���·������һ���㵽������ľ��� 
void dijkstra(int st)
{
	memset(d, 0x3f, sizeof(ll) * (n + 1));
	d[st] = 0;

	priority_queue<Edge> pq;
	pq.push({st, d[st]});

	while (pq.size())
	{
		int x = pq.top().x; pq.pop();//ֻҪ����ͺã����ȶ��п����Լ�ʵ��ȡ������Դ������ĵ�

		if (vis[x]) continue;//��ֹ�ظ���ӣ���Ϊ���ȶ��е����ʣ����µ�һ�δ���ĵ�һ������̵ģ�֮���ظ���ӵĵ�ֱ����������
		vis[x] = true;

		for (auto& ed : g[x])//��g[x]Ϊ���㣬���������ܵ�������е�
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
		if (u ^ v) g[u].push_back({ v, w });//��ֹ�Ի�
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
