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

const int N = 1e5 + 9;
vector<int> g[N];//һά�洢���ڵ㣬��ά�洢�ӽڵ�

bitset<N> vis;//��¼�Ƿ��߹�

//void dfs(int x)
//{
//	if (vis[x]) return; //�߹��ͻ���
//	vis[x] = true;
//
//	for (auto& y : g[x]) dfs(y);//���ӽڵ����
//}
//dfsҲ������ô�޸�
void dfs(int x)
{
	vis[x] = true;

	for (auto& y : g[x])
	{
		if (vis[y]) continue;//���жϷ���ѭ�������߹���������ǰ�ӽڵ�

		dfs(y);
	}
}

void solve()
{
	int n, m; cin >> n >> m;
	while (m--)
	{
		int u, v; cin >> u >> v;
		if (u ^ v)g[u].push_back(v);//���u��v����ȣ������γ��Ի���������
	}

	dfs(1);//�Ӹ��ڵ㿪ʼ����
	
	for (int i = 1; i <= n; i++) if (vis[i]) cout << i << ' ';
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t = 1;
	while (t--) solve();

	return 0;
}
//5 3
//1 2
//2 4
//4 5
//
//1 2 4 5
