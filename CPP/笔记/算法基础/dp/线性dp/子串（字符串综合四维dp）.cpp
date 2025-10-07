// Problem: Luogu P2679
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2679
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e3 + 7, M = 207;
const ll P = 1000000007;

ll dp[2][M][M][2];//dp[i][j][k][t]a字符串前i位分成k段与b前j位匹配且用/不用当前字符的方案数

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, m, k; cin >> n >> m >> k;
	string a, b; cin >> a >> b;
	a = " " + a, b = " " + b;
	
	for(int i = 1; i <= n; i++)
	{
		int y = i & 1;
		dp[y ^ 1][0][0][0] = 1;
		for(int j = 1; j <= m; j++)
		{
			for(int t = 1; t <= k ;t++)
			{
				//如果当前位相等，那么第j位肯定是现在选上的，之前肯定是j-1，再考虑前i-1位选不选，划分几段 
				if(a[i] == b[j]) dp[y][j][t][1] = (dp[y ^ 1][j - 1][t][1] + dp[y ^ 1][j - 1][t - 1][1] + dp[y ^ 1][j - 1][t - 1][0]) % P;
				else dp[y][j][t][1] = 0;//如果不匹配还要选，那么肯定凑不出一样的b串 
				dp[y][j][t][0] = (dp[y ^ 1][j][t][0] + dp[y ^ 1][j][t][1]) % P;//当前位不选的话，前i-1位肯定匹配了j项并划分了t段，再考虑选不选 
			}
		}
	}
	
	cout << (dp[n & 1][m][k][1] + dp[n & 1][m][k][0]) % P;//最后肯定是n，m，k但是最后一位选不选都有可能 
	
	return 0;
}

//6 3 3
//aabaab
//aab
//
//7
