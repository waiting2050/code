// Problem: Luogu CF607B
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF607B
// Memory Limit: 500 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 500 + 7;

int a[N], dp[N][N];//消除区间[i,j]的最小代价

//状态转移方程是非常普通的区间dp，但是加上了回文的条件，就要额外的更多考虑 
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	memset(dp, 0x3f, sizeof(dp));
	for(int i = 1; i <= n; i++) dp[i][i] = 1;//长度为1的串必然是回文串
	for(int i = 1; i < n; i++) dp[i][i + 1] = dp[i][i] + (a[i] != a[i + 1]);//长度为2的回文串需要特别初始化 
	
	for(int len = 3; len <= n; len++)//长度为1，2已经初始化完成，从长度3开始 
	{
		for(int i = 1, j = i + len - 1; j <= n; i++, j++)
		{
			//若左右端点相等，被包含在内的区间里可能有很多待消除的回文子串，
			//一定存在某个回文子串（在其余回文子串消除以后还剩下的那个）能再加上这两个端点 
			if(a[i] == a[j]) dp[i][j] = dp[i + 1][j - 1];
			for(int k = i; k < j; k++) 	dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
		}
	}
	
	cout << dp[1][n];
	
	return 0;
}

//3
//1 2 1
//
//1
//
//
//3
//1 2 3
//
//3
//
//
//7
//1 4 4 2 3 2 1
//
//2
