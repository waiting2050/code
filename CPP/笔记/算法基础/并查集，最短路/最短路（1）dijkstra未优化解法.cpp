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
	int x, w;//x�ǳ��㣬w��Ȩֵ
};

vector<Edge> g[N];	//ע��g�Ƕ�ά�� 
ll d[N], n, m;//d�������·��n���㣬m����
bitset<N> vis;//��־��û���߹�

void dijkstra(int st)
{
	memset(d, 0x3f, sizeof(ll) * (n + 1));
	d[st] = 0;

	for (int i = 1; i <= n; i++)
	{
		 // �ҳ���ǰδ�����ʵĶ����У�������ʼ��������Ǹ�����u 
		int u = -1;
		for (int j = 1; j <= n; j++)//��֤ѭ��������u������Ϊ����Ԫ�������û�����ʹ��ĵ�
			if (!vis[j] && (u == -1 || d[j] < d[u])) u = j;//���u�����ʹ�������jû�����ʹ���Ԫ�㵽j�ľ���С�ڵ�u�ľ��룬�͸���u
														//��Ϊÿ���ҳ�����uһ��������Ķ��㣬�������u�����ʹ� ��˵��֮ǰ�Ѿ�����u�� 
		vis[u] = true;//��ʾu�Ѿ���չ��

		for (auto &ed : g[u])//����·����������u��ʼ�����г��ߣ��ҵ����·�������� 
		{
			int v = ed.x,  w = ed.w;//v�ǵ㣬w��Ȩֵ��Ҳ����·����
			d[v] = min(d[v], d[u] + w);//�����ǰ��δ���޸ģ�������·�����ã��͸���
		}//��Ϊ��!vis[v]������֮ǰ���¹���·�����ᱻ������ʵ�����ѭ��ֻ������һ�������û����
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

	cout << (d[n] >= 0x3f3f3f3f3f3f3f3f ? -1 : d[n]);//������ܵ�������-1���������·���� 

	return 0;
}
//3 3
//1 2 5
//2 3 2
//1 3 10
//
//7
