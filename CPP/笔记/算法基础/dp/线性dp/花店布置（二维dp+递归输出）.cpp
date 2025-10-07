// Problem: Luogu P1854
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1854
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 100 + 7;

int dp[N][N], a[N][N], ans[N];

void print(int x, int y)
{
	if(!x || !y) return;
	if(dp[x - 1][y - 1] + a[x][y] == dp[x][y])//�����������Ͻ��� 
	{
		print(x - 1, y - 1);
		cout << y << ' ';
	}
	else print(x, y - 1);//����������
	//����������˼·����dp��ʱ����һ�µ� 
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, m; cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> a[i][j];
		
	memset(dp, 128, sizeof(dp));//��ʼ��Ϊ���� 
	for(int i = 0; i <= m; i++) dp[0][i] = 0;//�������һ�г�ʼ��Ϊ0 
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			dp[i][j] = max(dp[i - 1][j - 1] + a[i][j], dp[i][j - 1]);//̰�ģ���ǰ����Ų��Ż� 
		}
	}
	
	cout << dp[n][m] << '\n';
	print(n, m);//�ݹ���� 
	
	return 0;
}

// 3 5
// 7 23 -5 -24 16
// 5 21 -4 10 23
// -21 5 -4 -20 20
// 
// 53
// 2 4 5
