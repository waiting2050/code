#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 定义全局变量用于存储测试用例的数量T（总时间/容量）和物品数量M
int T, M;

// dp数组用于动态规划，dp[i][j]表示前i个物品在容量为j时的最大价值
int dp[2][1007];
// t数组存储每个物品所需的时间（或体积）
int t[107];
// v数组存储每个物品的价值
int v[1007];

// solve函数用于解决单个背包问题实例
void solve()
{
	for(int i = 0; i <= T; i++) dp[0][i] = 0;
	// 读入每个物品的时间和价值
	for(int i = 1; i <= M; i++) cin >> t[i] >> v[i];
	
	// 动态规划求解过程
	for(int i = 1; i <= M; i++) // 遍历每个物品
	{
		int y = i & 1;
		for(int j = 0; j <= T; j++) // 遍历每种可能的总时间/容量
		{
			if(j >= t[i]) // 如果当前容量j足够放下第i个物品
				dp[y][j] = max(dp[y ^ 1][j], dp[y ^ 1][j - t[i]] + v[i]); // 更新最大价值
			else 
				dp[y][j] = dp[y ^ 1][j]; // 否则，不选择该物品，保持之前的最大价值
		}
	}
	
	cout << dp[M & 1][T] << '\n';
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

//以下是滚动优化 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 107, MOD = 1e6 + 7;

int dp[3][N];//选到第几种花，选了多少
int a[N];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, m; cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++)
	{
		int y = i & 1;
		
		for(int j = 0; j <= m; j++)
		{
			dp[y][j] = 0;//注意这里要初始化，因为只有两层，且是累加的形式，不同层数据可能重复加（比如1，3层） 
			for(int k = 0; k <= j && k <= a[i]; k++)
			{
				dp[y][j] = (dp[y][j] + dp[y ^ 1][j - k]) % MOD;//同层的数据可以累加 
			}
		}
	}
	
	cout << dp[n & 1][m];
	
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
