#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 107;

ll a[N][N], sum[N][N];
double ans[N];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, m; cin >> n >> m;
	
	memset(a, 0x3f, sizeof(a));
	for(int i = 1; i <= m; i++)
	{
		int u, v, w; cin >> u >> v >> w;
		a[u][v] = a[v][u] = w;
		sum[u][v] = sum[v][u] = 1;//����u��v֮��϶������٣�����һ�����· 
	} 
	for(int i = 1; i <= n; i++) a[i][i] = 0;
	
	for(int k = 1; k <= n; k++)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				if(a[i][j] > a[i][k] + a[k][j])//����и���·���͸��²�����sum 
				{
					a[i][j] = a[i][k] + a[k][j];
					sum[i][j] = sum[i][k] * sum[k][j];
				}
				else if(a[i][j] == a[i][k] + a[k][j])//�������һ���ڵ㣬���нڵ������·�ϣ��ͼ��� 
				{
					sum[i][j] += sum[i][k] * sum[k][j];
				}
			}
		}
	}
	
	for(int k = 1; k <= n; k++)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				//����ڵ㲻�������յ㣬���Ҹýڵ������·�� 
				if(i ^ j && i ^ k && k ^ j && a[i][j] == a[i][k] + a[k][j]) ans[k] += 1.0 * sum[i][k] * sum[k][j] / sum[i][j];
			}
		}
	}
	
	for(int i = 1; i <= n; i++) printf("%.3f\n", ans[i]);
		
	return 0;
}

// 4 4
// 1 2 1
// 2 3 1
// 3 4 1
// 4 1 1
// 
// 1.000
// 1.000
// 1.000
// 1.000
