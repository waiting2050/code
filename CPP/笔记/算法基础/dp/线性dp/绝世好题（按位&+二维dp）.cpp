// Problem: Luogu P4310
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4310
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 7;

int a[N], b[32], dp[32][N];//dp[i][j]i表示2的幂次方上的数（从1到31），j表示a[i]，dp表示累积到当前的长度 

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= 31; i++) b[i] = 1 << (i - 1);//预处理b，表达出<=31的2每个幂次 
	
	for(int i = 1; i <= n; i++)
	{
		int mx = 0;
		for(int j = 1; j <= 31; j++)//对每一个a，遍历找每一个可能转移过来的路径，并且找出长度最长的那条路 
		{
			//这里的路径指的是（比如3=011，3可以从010（2）或001（1）转移，那么1，2就是3的路径）
			//如果可以从该路径过来，那么记录并比较得到最大值 
			if(a[i] & b[j]) mx = max(mx, dp[j][i - 1]);//注意这里i是列，j是行 
		}
		mx++;//最长路径长度+1 
		for(int j = 1; j <= 31; j++)
		{
			if(a[i] & b[j]) dp[j][i] = mx;//如果当前点在最长路径上，就更新为mx 
			else dp[j][i] = dp[j][i - 1];//否则就继承前一个 
		}
	}
	
	int ans = 0;
	for(int i = 1; i <= 31; i++) ans = max(ans, dp[i][n]);
	
	cout << ans;
	
	return 0;
}

//3
//1 2 3
//
//2
//
//
//7
//13 16 9 12 4 4 18
//
//5
