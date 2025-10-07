// Problem: Luogu P2758
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2758
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e3 + 7;

int dp[N][N];//dp[i][j]表示a的前i个字符和b的前j个字符相等所需的操作次数

//一共就四种操作：1.删除 2.插入. 3.替换 4.不变 
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	string a, b; cin >> a >> b;
	a = " " + a;
	b = " " + b;
	
	for(int i = 1; i < a.size(); i++) dp[i][0] = i;//此时需要删除i个字符 
	for(int j = 1; j < b.size(); j++) dp[0][j] = j;//此时需要插入i个字符 
	
	for(int i = 1; i < a.size(); i++)
	{
		for(int j = 1; j < b.size(); j++)
		{
			if(a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1];//如果当前字符相等，当然直接继承之前的状态（前i-1,j-1都相等所需的操作次数最短）//也就是不变 
			else dp[i][j] = min(min(dp[i - 1][j] + 1, dp[i][j - 1] + 1), dp[i - 1][j - 1] + 1);//否则分别从删除，插入，替换进行考虑） 
		}											//举个例子，替换意味着当前a[i]一定等于b[j]，那么只要前面的i-1能对应j-1即可 
	}
	
	cout << dp[a.size() - 1][b.size() - 1];
	
	return 0;
}

//sfdqxbw
//gfdgw
//
//4
