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

const int N = 60;
int fa[N];//���ڵ�

vector<int> g[N];//graph,�൱�ڶ�ά����g[][],�ڶ������vector

void dfs(int x)
{
	cout << x << ' ';
	for (auto& y : g[x]) //������ǰ���ڵ�������ӽڵ�
		dfs(y);//��ÿ���ӽڵ�dfs
}

void bfs(int rt)
{
	queue<int> q;
	q.push(rt);//�����ڵ����
	while (q.size())//�����зǿ�
	{
		int x = q.front(); q.pop();//ȡ������
		cout << x << ' ';
		for (auto& y : g[x]) q.push(y);//�����׵������ӽڵ�����
	}
}//����1�Ǹ���������2��3.��ô�����1����2��3��ӣ������ν�2��3���ӽڵ����

void solve()
{
	int n; cin >> n;
	for (int i = 2; i <= n; i++) 
	{
		cin >> fa[i];
		g[fa[i]].push_back(i);//��һ����Ÿ��ڵ㣬�ڶ�������ӽڵ�
	}
	//iҪ��1��ʼ����Ϊ���ڵ��1��ʼ
	for (int i = 1; i <= n; i++) sort(g[i].begin(), g[i].end());//���ӽڵ��������

	dfs(1);//�ӵ�һ�����ڵ㿪ʼ
	cout << '\n';
	bfs(1);
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t = 1;
	while (t--) solve();

	return 0;
}
//4
//1 1 2
//
//1 2 4 3
//1 2 3 4
