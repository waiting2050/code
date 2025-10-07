#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 7;
int dp[N];	// 动态规划表，用于存储每个容量下的最大价值

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int m, n; // 分别代表背包的最大容量和物品的数量
	cin >> m >> n;
	
	// 遍历每一个物品 //套了三重循环，时间复杂度较高 
	for(int i = 1; i <= n; i++)
	{
		int s, w, v; // 分别代表当前物品的数量、价值和体积
		cin >> s >> w >> v;
		
		// 对于每个物品，根据其数量进行循环处理
		while(s--)
			// 倒序遍历从背包的最大容量到当前物品的价值
			for(int j = m; j >= v; j--)
				// 确保当前容量可以容纳该物品，并更新动态规划表
				if(j >= v) 
					dp[j] = max(dp[j], dp[j - v] + w); // 更新为放入该物品后的最大价值
  	}
  	
  	  	cout << dp[m];
  	
  	return 0;
}
