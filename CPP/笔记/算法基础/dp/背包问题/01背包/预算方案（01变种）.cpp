// Problem: Luogu P1064
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1064
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 3.2e4 + 7, M = 67;

int p[M][3], v[M][3];//�۸���Ҫ�ȣ�[Mi][j]��ʾ��Mi��j������Ʒ��j=0�������� 
ll dp[N];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, m; cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		int x, y, q; cin >> x >> y >> q;
		if(!q)
		{
			v[i][q] = y;
			p[i][q] = x;
		}
		else if(!v[q][1])
		{
			v[q][1] = y;
			p[q][1] = x;
		}
		else
		{
			v[q][2] = y;
			p[q][2] = x;
		}
	}
	
	//��01�����Ĳ�֮ͬ�����������ֿ��ܣ���ֻ��ѡ������������²���ѡ���������� 
	for(int i = 1; i <= m; i++)
	{
		for(int j = n; j >= 0; j--)
		{
			//dp[j]=dp[j]��һ�ּ̳У���ʾʲô����ѡ 
			if(j >= p[i][0]) dp[j] = max(dp[j], dp[j - p[i][0]] + p[i][0] * v[i][0]);//ֻѡ���� 
			if(j >= p[i][0] + p[i][1]) dp[j] = max(dp[j], dp[j - p[i][0] - p[i][1]] + p[i][0] * v[i][0] + p[i][1] * v[i][1]);//ѡ�����͸���1 
			if(j >= p[i][0] + p[i][2]) dp[j] = max(dp[j], dp[j - p[i][0] - p[i][2]] + p[i][0] * v[i][0] + p[i][2] * v[i][2]);//ѡ�����͸���2 
			if(j >= p[i][0] + p[i][1] + p[i][2]) dp[j] = max(dp[j], dp[j - p[i][0] - p[i][1] - p[i][2]] + p[i][0] * v[i][0] + p[i][1] * v[i][1] + p[i][2] * v[i][2]);//ѡ�����͸���1��2 
		}
	}
	
	cout << dp[n];
	
	return 0;
}


// 1000 5
// 800 2 0
// 400 5 1
// 300 5 1
// 400 3 0
// 500 2 0
// 
// 
// 2200
