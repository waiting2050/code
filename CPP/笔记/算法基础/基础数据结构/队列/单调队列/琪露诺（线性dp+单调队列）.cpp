// Problem: Luogu P1725
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1725
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 7;

int dp[N], a[N], dq[N];//dp表示第i个位置的最大魔法值 

//对每个位置，他可以移动到[i+l,i+r]区域，相当于每个i，可以从[i-r,i-l]里面的最大值转移过来，但是这样可能会达到1e10复杂度 
//考虑到从某个固定区间的最大值转移过来，所以使用单调队列 

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, l, r; cin >> n >> l >> r;
	for(int i = 0; i <= n; i++) cin >> a[i];
	
	memset(dp, 128, sizeof(dp));//因为输入值可能有负的，所以初始化为很大的负值(char从[0,255],正值0~127，初始化128直接溢出为最大的负值) 
	dp[0] = 0;
	
	//难点在于如何限定转移在[i-r,i-l]这个区间 
	int hh = 1, tt = 0, ans = -2e9;
	for(int i = l; i <= n; i++)//注意从l开始 
	{
		while(tt >= hh && dq[hh] < i - r) hh++;
		while(tt >= hh && dp[dq[tt]] <= dp[i - l]) tt--;
		
		dq[++tt] = i - l;//注意这里存的是i-l，所以最后的[n-l+1,n]是不会入队的。通过这个限制了<=i-l的范围。 
		dp[i] = dp[dq[hh]] + a[i];
		
		if(i + r > n) ans = max(ans, dp[i]);
	}
	
	cout << ans;
	
	return 0;
}

//5 2 3
//0 12 3 11 7 -2
//
//11
