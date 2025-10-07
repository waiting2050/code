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

int a[N][N], dp[N][N][N][N];//dp[i][j][x][y]两条路分别到(i,j)与(x,y)的最优解 

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	int x, y, w;
	while(cin >> x >> y >> w) a[x][y] = w;
	
	//既然要两条路一起走，如果开成二维，只单走一路考虑其最优解，之后再将路径还原置0，然后重复另一条路，局部最优未必全局最优
	//因此开成四维，两条路同时考虑 
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
					if(i == u && j == v) dp[i][j][u][v] -= a[i][j];//避免走过的路置没置0再走一次 
					//这地方是防止a[i][j]和a[u][v]计算两次，只要这部分没重复，那么dp肯定也不会重复（因为a[i][j]才是子问题，dp只是记录结果） 
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
