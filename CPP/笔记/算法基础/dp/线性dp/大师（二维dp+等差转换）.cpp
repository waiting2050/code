// Problem: Luogu P4933
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4933
// Memory Limit: 500 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e3 + 7, P = 998244353, V = 2e4 + 7;

ll dp[N][V * 2], a[N];//dp[i][j]以i为结尾公差为j的方案数

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	ll ans = 0;
	for(int i = 1; i <= n; i++)//枚举以每个数结尾 
	{
		for(int j = i - 1; j >= 1; j--)//枚举i以前的每个数，顺便枚举公差 
		{
			int diff = a[i] - a[j] + 1;//计算公差 
			dp[i][diff] = (dp[i][diff] + dp[j][diff] + 1) % P;//dp[j][diff]的方案数+只有两个数j,i的方案
			ans = (ans + dp[j][diff] + 1) % P;//同上，注意这里要加上dp[j][diff]而不是dp[i][diff]，否则会重复计算 
		}
		//ps:如果一个数前面有三种方案，那么这个数可任意接在三种方案后面（公差相同），再加上新产生的前一个数与这个数的方案 
	}
	
	cout << (ans + n) % P;//还要加上只有一座塔的方案数 
	
	return 0;
}

// 8
// 13 14 6 20 27 34 34 41
// 
// 50
