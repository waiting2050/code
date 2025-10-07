// Problem: Luogu P4170
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4170
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 50 + 7;

int dp[N][N];//����[l,r]������Ϳɫ���� 

//���������1.������AAABBBBAAA 2.���У�AAAABBBB
//���������Ӧ����ת�Ʋ��ԣ����һ(a[l]==a[r])��dp[i][j]��dp[i + 1][j]��dp[i][j - 1]ת�ƶ���
//							�������dp[i][j]�Ӷϵ�ת�ƶ��� 

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	string a; cin >> a;
	a = " " + a;
	int n = a.size() - 1;
	
	memset(dp, 0x3f, sizeof(dp));
	for(int i = 1; i <= n; i++) dp[i][i] = 1;
	
	for(int len = 2; len <= n;len++)
	{
		for(int i = 1, j = i + len - 1; j <= n; i++, j++)
		{
			if(a[i] == a[j]) dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]);
			for(int k = i; k < j; k++) dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
		}
	}
	
	cout << dp[1][n];
	
	return 0;
}

//AAAAA
//
//1
//
//
//RGBGR
//
//3
