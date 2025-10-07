// Problem: Luogu P2340
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2340
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 8e5 + 7, M = 8e5, DIF = 4e5;//N开到两倍4e5，防止下标为负数时越界 

int dp[N];//dp[i]表示智商为i时的情商大小 

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	memset(dp, 128, sizeof(dp));
	dp[DIF] = 0;
	
	int n; cin >> n;
	for(int i = 1; i <= n; i++)//01背包，选或不选 
	{
		int s, f; cin >> s >> f;
		
		if(s >= 0)//如果为正，那么从上一行的靠左边转移，反向滚动  
		{
			for(int j = M; j >= s; j--)
				dp[j] = max(dp[j], dp[j - s] + f);
		}
		else//否则正向滚动 
		{
			for(int j = 0; j <= M + s; j++)//防止越界，s此时小于0 
				dp[j] = max(dp[j], dp[j - s] + f);
		}
	}
	
	int ans = -2e9;
	for(int i = DIF; i <= M; i++)
	//将i与dp[i]相加，也就是将智商与情商求和 
		if(dp[i] >= 0)
			ans = max(ans, dp[i] + i - DIF);//减去偏移量，4e5相当于偏移后的0 
	
	cout << ans;
	
	return 0;
}

//5
//-5 7
//8 -6
//6 -3
//2 1
//-8 -5
//
//8
