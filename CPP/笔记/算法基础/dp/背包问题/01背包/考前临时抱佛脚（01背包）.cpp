// Problem: 
//     P2392 kkksc03考前临时抱佛脚
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2392
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int a[5], dp[1207], mytime[21];
//对于一道题只有两个状态，一是加到左脑，二是加到右脑，所以是01背包
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	for(int i = 1; i <= 4; i++) cin >> a[i];
	
	int ans = 0;
	for(int i = 1; i <= 4; i++)
	{
		int sum = 0;
		for(int j = 1; j <= a[i]; j++)
		{
			cin >> mytime[j];
			sum += mytime[j];
		}
		
		for(int j = 1; j <= a[i]; j++)
		{
			for(int k = sum >> 1; k >= mytime[j]; k--)
			{
				dp[k] = max(dp[k], dp[k - mytime[j]] + mytime[j]);//时间（即所花费代价）和价值是一样的，所以减去mytie再加上 
			}
		}
		ans += sum - dp[sum >> 1];//与下面一句其实是等效的，因为dp[sum>>1]一定<=sum/2,所以sum-dp肯定>dp 
		//ans += max(dp[sum >> 1], sum - dp[sum >> 1]);//因为实际时间是由花费较多的部分决定，所以取大 
		
		memset(dp, 0, sizeof(dp));
	}
	
	cout << ans;
		
	return 0;
}

