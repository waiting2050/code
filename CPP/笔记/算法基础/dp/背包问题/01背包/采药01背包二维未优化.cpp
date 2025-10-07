#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//01背包 
// 定义全局变量用于存储测试用例的数量T（总时间/容量）和物品数量M
int T, M;

// dp数组用于动态规划，dp[i][j]表示前i个物品在容量为j时的最大价值
int dp[107][1007];
// t数组存储每个物品所需的时间（或体积）
int t[107];
// v数组存储每个物品的价值
int v[1007];

// solve函数用于解决单个背包问题实例
void solve()
{
	// 读入每个物品的时间和价值
	for(int i = 1; i <= M; i++) 
		cin >> t[i] >> v[i];
	
	// 动态规划求解过程
	for(int i = 1; i <= M; i++) // 遍历每个物品
	{
		for(int j = 0; j <= T; j++) // 遍历每种可能的总时间/容量
		{
			if(j >= t[i]) // 如果当前容量j足够放下第i个物品
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - t[i]] + v[i]); // 更新最大价值
			else 
				dp[i][j] = dp[i - 1][j]; // 否则，不选择该物品，保持之前的最大价值
		}
	}
	
	cout << dp[M][T] << '\n';
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	while(cin >> T >> M)
	{
		if(T == 0 && M == 0) return 0;		
		solve();
	}
	
	return 0;
}

// 42 6
// 1 35
// 25 70
// 59 79
// 65 63
// 46 6
// 28 82
// 962 6
// 43 96
// 37 28
// 5 92
// 54 3
// 83 93
// 17 22
// 0 0
// 
// 117
// 334
