#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e6 + 7;
const int N = 107;
ll dp[N][N], a[N];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, m; cin >> n >> m;
	
	// 输入每种花的最大连续放置数量
	for(int i = 1; i <= n; i++) cin >> a[i];
	
    // 初始化dp数组，dp[0][0]表示没有选择任何花的情况下有一种方法（即什么都不做）
	dp[0][0] = 1;
	
    // 动态规划填表
	for(int i = 1; i <= n; i++)// 遍历每一类花
		for(int j = 0; j <= m; j++)// 尝试放置不同数量的花
			for(int k = 0; k <= j && k <= a[i]; k++)// 放置k个当前类型的花
				dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % mod; // 累加所有可能的方案，并对结果取模
	
    // 输出最终答案，即使用所有种类的花恰好放置m朵的方法数
	cout << dp[n][m];

	return 0;
}

// 2 4
// 3 2
// 
// 2
