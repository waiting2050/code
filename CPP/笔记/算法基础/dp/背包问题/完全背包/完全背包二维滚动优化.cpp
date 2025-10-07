#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 定义常量，N是物品数量的最大值加一些余量，M是背包容量的最大值加一些余量
const int N = 507, M = 1e5 + 7;

// w数组存储每个物品的重量（或体积），v数组存储每个物品的价值
int w[N], v[N];

// dp数组用于动态规划，dp[i][j]表示前i个物品在容量为j时的最大价值
int dp[2][M];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, m; cin >> m >> n;
	
	for(int i = 1; i <= n; i++) 
		cin >> w[i] >> v[i]; // 注意这里的w和v的定义与题目描述相反，应该是w[i]为重量，v[i]为价值

	// 动态规划求解过程
	for(int i = 1; i <= n; i++) // 遍历每个物品
	{
		int y = i & 1;
		for(int j = 0; j <= m; j++) // 遍历每种可能的总容量
		{
			if(j >= v[i]) // 如果当前容量j足够放下第i个物品
				dp[y][j] = max(dp[y ^ 1][j], dp[y][j - v[i]] + w[i]); // 更新最大价值
			else 
				dp[y][j] = dp[y ^ 1][j]; // 否则，不选择该物品，保持之前的最大价值
		}
	}

	cout << dp[n & 1][m] << '\n';

	return 0;
}
