// Problem: AT ABC418 D
// Contest: AtCoder - AtCoder Beginner Contest 418
// URL: https://atcoder.jp/contests/abc418/tasks/abc418_d
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//处理这类字符串或数列的操作问题时，寻找不变量（操作前后保持不变的某个值）的方法往往很有效。
//00->1,0少2；01/10->,0没少；11->1,0没少，通过观察发现0的数量的奇偶性是不变的
//所以可以得出结论，所有0的个数为偶数的子串都是美丽的 

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 7;

int dp[N][2]; //dp[i][0]表示以第i位结尾，0的个数为偶数的所有子串数量
		      //这里的以i结尾是从1到i，2到i，3到i等等，不是特指从1到i 

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	string s; cin >> s;
	s = "?" + s;
	
	for(int i = 1; i <= n; i++)
	{
		if(s[i] == '0')
		{
			dp[i][0] = dp[i - 1][1]; //当前位置的0会使0数量+1，之前0是奇数加上变偶数；如果当前数单独存在，即从i到i那么0个数会为奇数 
			dp[i][1] = dp[i - 1][0] + 1;
		}
		else
		{
			dp[i][0] = dp[i - 1][0] + 1;
			dp[i][1] = dp[i - 1][1];
		}
	}
	
	ll ans = 0;
	for(int i = 1; i <= n; i++) ans += dp[i][0]; //加上以每个位置结尾，0是偶数个数的情况 
	
	cout << ans;
	
	return 0;
}

//3
//110
//
//3
//
//
//30
//011011100101110111100010011010
//
//225
