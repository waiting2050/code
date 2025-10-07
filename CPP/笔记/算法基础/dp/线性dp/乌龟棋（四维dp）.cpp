// Problem: Luogu P1541
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1541
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 350 + 7, M = 40 + 7;

//由于用完所有的牌一定会到达终点，所以只考虑出牌顺序即可，也就是考虑当前回合选择四种类型牌的其中一种 
int dp[M][M][M][M], a[N], c[5];//dp[a][b][c][d]表示前进数为1,2,3,4的牌分别用了a,b,c,d张；c负责计数，前进数为i的牌有c[i]张 

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, m; cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= m; i++)
	{
		int x; cin >> x;
		c[x]++;
	}
	
	dp[0][0][0][0] = a[1];//一张牌不用的分值为a[1] 
	for(int i = 0; i <= c[1]; i++)
	{
		for(int j = 0; j <= c[2]; j++)
		{
			for(int u = 0; u <= c[3]; u++)
			{
				for(int v = 0; v <= c[4]; v++)
				{
					int t = i + j * 2 + u * 3 + v * 4 + 1;//这里+1因为默认从起点1开始，而不是0 
					if(i ^ 0) dp[i][j][u][v] = max(dp[i][j][u][v], dp[i - 1][j][u][v] + a[t]);
					if(j ^ 0) dp[i][j][u][v] = max(dp[i][j][u][v], dp[i][j - 1][u][v] + a[t]);
					if(u ^ 0) dp[i][j][u][v] = max(dp[i][j][u][v], dp[i][j][u - 1][v] + a[t]);
					if(v ^ 0) dp[i][j][u][v] = max(dp[i][j][u][v], dp[i][j][u][v - 1] + a[t]);
				}
			}
		}
	}
	
	cout << dp[c[1]][c[2]][c[3]][c[4]];//乌龟棋的特点是用完所有的牌刚好到达终点 
	
	return 0;
}

