// Problem: Luogu P2858
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2858
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e3 + 7;

int dp[N][N], a[N];//dp[i][j]表示[i,j]这个区间最多能赚多少钱 

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	//关于初始化：当len=1时,i=j，dp[i][j](即dp[i][i])已经被初始化了 
	for(int len = 1; len <= n; len++)
		for(int i = 1, j = i + len - 1; j <= n; i++, j++)
			//n-len+1:总天数-剩余的天数+1=当前已储存的天数
			dp[i][j] = max(dp[i + 1][j] + a[i] * (n - len + 1), dp[i][j - 1] + a[j] * (n - len + 1));
	
	cout << dp[1][n];
	
	return 0;
}

//5
//1
//3
//1
//5
//2
//
//43
