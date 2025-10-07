// Problem: Luogu P1140
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1140
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 100 + 7;

int d[6][6] =
{
	{0,  0,  0,  0,  0,  0},
	{0,  5, -1, -2, -1, -3},
	{0, -1,  5, -3, -2, -4},
	{0, -2, -3,  5, -2, -2},
	{0, -1, -2, -2,  5, -1},
	{0, -3, -4, -2, -1,  0}
};
unordered_map<char, int> mp;
int a[N], b[N], dp[N][N];//a的前i个碱基和b的前j个碱基的最大相似度

//每一位无非三种情况，1.非空对非空，2.非空对空，3.空对非空。4.空对空（不存在） 
//任何一位碱基都有可能和空碱基对上，但是不用关心到底插入多少空碱基，只需要使每一位碱基都有对应就可以 

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
	mp['A'] = 1, mp['C'] = 2, mp['G'] = 3, mp['T'] = 4;
	
	int n; cin >> n;
	for(int i = 1; i <= n; i++)
	{
		char ch; cin >> ch;
		a[i] = mp[ch];
	}
	
	int m; cin >> m;
	for(int i = 1; i <= m; i++)
	{
		char ch; cin >> ch;
		b[i] = mp[ch];
	}
	
	//由状态转移方程推得，从i-1/j-1/[i-1,j-1]来，可以得知最初始从dp[0][0]或dp[i][0]或dp[0][i]来 
	for(int i = 1; i <= n; i++) dp[i][0] = dp[i - 1][0] + d[a[i]][5];
	for(int i = 1; i <= m; i++) dp[0][i] = dp[0][i - 1] + d[5][b[i]];
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			dp[i][j] = max(dp[i - 1][j - 1] + d[a[i]][b[j]], max(dp[i - 1][j] + d[a[i]][5], dp[i][j - 1] + d[5][b[j]]));
	
	cout << dp[n][m];
	
	return 0;
}

//7 AGTGATG
//5 GTTAG
//
//14
