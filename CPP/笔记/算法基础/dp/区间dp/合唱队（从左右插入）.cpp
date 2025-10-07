// Problem: Luogu P3205
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3205
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//区间 dp 有一个性质——大区间包含小区间，这道题就符合这样的一个性质:

const int N = 1e3 + 7, P = 19650827;

int dp[N][N][2], a[N];//dp[i][j][0]表示从第i个人到第j个人组成的子队列，第i个人从左边插入的总的情况数（1则表示j从右边插入） 

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) dp[i][i][0] = 1;//不用再初始化dp[i][i][1]，否则会重复计数。
	//从之后的状态转移也可以看出新的dp会由前两个状态(第三维分别是0,1)转移
	
	for(int len = 1; len <= n; len++)//区间长 
	{
		for(int i = 1, j = i + len - 1; j <= n; i++, j++)//左右端点 
		{
			//其实无非就四种转移，新的左插在旧的左/右，新的右插在旧的左/右 
			if(a[i] < a[i + 1]) dp[i][j][0] += dp[i + 1][j][0];
			if(a[i] < a[j]) dp[i][j][0] += dp[i + 1][j][1];
			if(a[j] > a[i]) dp[i][j][1] += dp[i][j - 1][0];
			if(a[j] > a[j - 1]) dp[i][j][1] += dp[i][j - 1][1];
			dp[i][j][0] %= P, dp[i][j][1] %= P;
		}
	}
	
	cout << (dp[1][n][0] + dp[1][n][1]) % P;
	
	return 0;
}

// 4
// 1701 1702 1703 1704
// 
// 8
