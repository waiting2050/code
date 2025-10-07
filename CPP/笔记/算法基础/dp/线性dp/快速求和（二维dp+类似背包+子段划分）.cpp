// Problem: Luogu P1874
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1874
// Memory Limit: 500 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int M = 47, N = 1e5 + 7;

//常见的dp划分方式，一维表示到i为止，二维表示某种状态 
int num[M][M], dp[M][N];//num[i][j]从i加到j的和，dp[i][j]前i位加到j的加号数量

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	string s; cin >> s;
	int n; cin >> n;
	
	int m = s.size();
	for(int i = 1; i <= m; i++)
	{
		for(int j = i; j <= m; j++)
		{
			num[i][j] = num[i][j - 1] * 10 + (s[j - 1] - '0');
			if(num[i][j] > n) num[i][j] = 0x3f3f3f3f;//这个很重要，一旦超过，设置为不可达。（不然可能re或wa） 
		}
	}
	
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0] = -1;//正常初始化为0，但是比如dp[1][num[1][1]]会被dp[0][0]+1更新为0.因为是在两个数中间添加加号，而dp是根据数字去设计，所以
	//num+num+num，+比num少1，因此初始化为-1，修正这种误差 
	
	for(int i = 1; i <= m; i++)
	{
		for(int k = 0; k <= n; k++)
		{
			for(int j = 0; j < i; j++)
			{
				//类似于背包模型和子段划分 
				if(k >= num[j + 1][i]) dp[i][k] = min(dp[i][k], dp[j][k - num[j + 1][i]] + 1);
			}
		}
	}
	
	cout << (dp[m][n] >= 0x3f3f3f3f ? -1 : dp[m][n]);
	
	return 0;
}

// 99999
// 45
// 
// 4
