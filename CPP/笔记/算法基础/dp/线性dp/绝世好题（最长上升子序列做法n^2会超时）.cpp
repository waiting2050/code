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

int a[N], dp[N]; 

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	for(int i = 1; i <= n; i++)
	{
		dp[i] = 1;
		for(int j = 1; j < i; j++)//类似最长上升子序列 
		{
			if(a[i] & a[j]) dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	
	cout << *max_element(dp + 1, dp + 1 + n);
	
	return 0;
}
