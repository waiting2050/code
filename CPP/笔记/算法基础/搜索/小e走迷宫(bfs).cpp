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

const int N = 1e3 + 7;
bitset<N>vis[N], mp[N];//vis��֦��mp�洢�ϰ���
int d[N][N], n, m;//d��¼Ҫ�߼���
int dx[] = { 0, 0, -1, 1 };//��ʾ����
int dy[] = { 1, -1, 0, 0 };
pair<int, int> pre[N][N];//�洢���·��������Щ��

bool inmp(int x, int y)//�ж��Ƿ��ڵ�ͼ���ڲ���û�г����߽�
{
	return x >= 1 && x <= n && y >= 1 && y <= m;
}

void bfs(int sx, int sy)
{
	queue<pair<int, int>> q;//�洢�ڵ�
	q.push({ sx, sy });
	vis[sx][sy] = true;

	while (q.size())
	{
		int x = q.front().first;//ȡ������Ԫ��
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = dx[i] + x;
			int ny = dy[i] + y;//������ӽڵ�

			if (inmp(nx, ny) && !vis[nx][ny] && !mp[nx][ny])//�ж��ӽڵ��Ƿ����Ҫ��
			{
				vis[nx][ny] = true;
				pre[nx][ny] = { x, y };//nx,ny����һ���㣬Ҳ�������·����ÿһ����
				d[nx][ny] = d[x][y] + 1;
				q.push({ nx, ny });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) 
		{
			int temp; cin >> temp;
			mp[i][j] = temp;
		}

	bfs(1, 1);

	for (int i = n, j = m, _i = i; i ^ 1 || j ^ 1; i = pre[i][j].first, j = pre[_i][j].second, _i = i)//������·��
		cout << i << ' ' << j << '\n';

	if (!d[n][m]) cout << -1;
	else cout << d[n][m];

	return 0;
}
//5 5
//0 1 0 0 0
//0 0 0 1 0
//1 1 0 1 0
//0 0 1 0 0
//1 0 0 1 0
//
//10
