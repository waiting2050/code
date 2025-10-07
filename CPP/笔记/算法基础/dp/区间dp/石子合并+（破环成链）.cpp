// Problem: Luogu P1880
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1880
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 100 + 7;

//dp[i][j]��ʾ�ϲ�����[i,j]����С����
int mx[N * 2][N * 2], mi[N * 2][N * 2], a[N * 2], pre[N * 2];//mi/mx�ֱ𴢴���С/���� 

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i], a[i + n] = a[i];//�ƻ����� 
	for(int i = 1; i <= (n << 1); i++) pre[i] = pre[i - 1] + a[i];
	
	int m = n << 1;
	for(int len = 2; len <= m; len++)
	{
		for(int i = 1, j = i + len - 1; j <= m; i++, j++)
		{
			mi[i][j] = INT_MAX;//mxĬ����0��������ʽ�ĳ�ʼ�� 
			for(int k = i; k < j; k++)
			{
				mx[i][j] = max(mx[i][j], mx[i][k] + mx[k + 1][j] + pre[j] - pre[i - 1]);
				mi[i][j] = min(mi[i][j], mi[i][k] + mi[k + 1][j] + pre[j] - pre[i - 1]);
			}
		}
	}
	
	int ansmi = INT_MAX, ansmx = 0;
	for(int i = 1; i <= n; i++)
	{
		//���ڻ���������������[1,n]������һ������Ϊ��㶼�ǿ��Ե� 
		ansmi = min(ansmi, mi[i][i + n - 1]);
		ansmx = max(ansmx, mx[i][i + n - 1]);
	}
	
	cout << ansmi << '\n' << ansmx;
	
	return 0;
}

//4
//4 5 9 4
//
//43
//54
