// Problem: Luogu P1004
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1004
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 9 + 7;

int a[N][N], dp[N][N][N][N];//dp[i][j][x][y]����·�ֱ�(i,j)��(x,y)�����Ž� 

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	int x, y, w;
	while(cin >> x >> y >> w) a[x][y] = w;
	
	//��ȻҪ����·һ���ߣ�������ɶ�ά��ֻ����һ·���������Ž⣬֮���ٽ�·����ԭ��0��Ȼ���ظ���һ��·���ֲ�����δ��ȫ������
	//��˿�����ά������·ͬʱ���� 
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			for(int u = 1; u <= n; u++)
			{
				for(int v = 1; v <= n; v++)
				{
					dp[i][j][u][v] += max(max(dp[i - 1][j][u - 1][v], dp[i][j - 1][u - 1][v]), 
					max(dp[i - 1][j][u][v - 1], dp[i][j - 1][u][v - 1])) + a[i][j] + a[u][v];
					if(i == u && j == v) dp[i][j][u][v] -= a[i][j];//�����߹���·��û��0����һ�� 
					//��ط��Ƿ�ֹa[i][j]��a[u][v]�������Σ�ֻҪ�ⲿ��û�ظ�����ôdp�϶�Ҳ�����ظ�����Ϊa[i][j]���������⣬dpֻ�Ǽ�¼����� 
				}
			}
		}
	}
	
	cout << dp[n][n][n][n];
	
	return 0;
}

// 8
// 2 3 13
// 2 6  6
// 3 5  7
// 4 4 14
// 5 2 21
// 5 6  4
// 6 3 15
// 7 2 14
// 0 0  0
// 
// 67
