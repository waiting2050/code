#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 507;
ll a[N], dp[N][N];//dp[i][j]表示以第i段结尾，划分j段的最优解 

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, k; cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	for(int i = 1; i <= n; i++) dp[i][1] = dp[i - 1][1] ^ a[i];
	for(int i = 1; i <= n; i++)//i遍历以每一个为结尾的可能情况 
	{
		for(int j = 2; j <= i && j <= k; j++)//要划分j段，若以1为单位，最多i段，并且不需要比题目上限k还多 
		{
			ll sum = a[i];//sum存储第j段的异或和 
			for(int t = i - 1; t >= j - 1; t--)//t从i-1开始，同时要确保能划分j-1段，t不能比j-1还小 
			{
				dp[i][j] = max(dp[i][j], dp[t][j - 1] + sum);
				sum ^= a[t];
			}
		}
	}
	
	cout << dp[n][k];//以n结尾，划分k段 
	
	return 0;
}

