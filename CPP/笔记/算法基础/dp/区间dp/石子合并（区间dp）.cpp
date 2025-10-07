#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 307;
const int inf = 2e9;
int a[N], dp[N][N], prefix[N];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) prefix[i] = prefix[i - 1] + a[i];
	
	// 动态规划填表		//注意这里的len是指有几个点，比如有一个区间[1,1]，就是长度为1.[1,2]就是长度为2
	for(int len = 2; len <= n; len++) // 遍历所有可能的区间长度，从2开始直到n
	{
		for(int i = 1, j = i + len - 1; j <= n; i++, j++) // 遍历所有可能的起点i和终点j，保持区间长度为len
		{
            // 初始化当前区间的dp值为无穷大
			dp[i][j] = inf;
            
            // 尝试在区间[i, j]内的每一个位置k进行分割，计算合并代价并取最小值
			for(int k = i; k < j; k++)
			{
                // 更新dp[i][j]为左边区间[i, k]与右边区间[k+1, j]合并的最小代价加上合并这两个区间本身的代价（即整个区间的和）
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + prefix[j] - prefix[i - 1]);
			}
		}
	}

    // 输出最终答案，即将所有元素合并成一个石子堆所需的最小代价
	cout << dp[1][n];

	return 0;
}

//3
//3 5 4
//
//20
