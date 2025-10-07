#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 定义常量，N是物品数量的最大值加一些余量，M是背包容量的最大值加一些余量
const int N = 507, M = 1e5 + 7;

// w数组存储每个物品的重量（或体积），v数组存储每个物品的价值
int w[N], v[N];

// dp数组用于动态规划，dp[i][j]表示前i个物品在容量为j时的最大价值
ll dp[M];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n, m; cin >> m >> n;
	
	for(int i = 1; i <= n; i++) 
		cin >> w[i] >> v[i]; // 注意这里的w和v的定义与题目描述相反，应该是w[i]为重量，v[i]为价值

	// 思想和 01 背包一模一样。但此处不能反向循环，得正向循环，因为 dp[i][j]
 	//使用的都是同层的数据，正向可以取到正确数据，反向的话就取到了上一层 dp 的数据。
	for(int i = 1; i <= n; i++) // 遍历每个物品
		for(int j = v[i]; j <= m; j++) // 遍历每种可能的总容量
			dp[j] = max(dp[j], dp[j - v[i]] + w[i]);

	cout << dp[m] << '\n';

	return 0;
}
