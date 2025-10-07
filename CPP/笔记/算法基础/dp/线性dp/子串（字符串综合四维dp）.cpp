// Problem: Luogu P2679
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2679
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e3 + 7, M = 207;
const ll P = 1000000007;

ll dp[2][M][M][2];//dp[i][j][k][t]a�ַ���ǰiλ�ֳ�k����bǰjλƥ������/���õ�ǰ�ַ��ķ�����

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, m, k; cin >> n >> m >> k;
	string a, b; cin >> a >> b;
	a = " " + a, b = " " + b;
	
	for(int i = 1; i <= n; i++)
	{
		int y = i & 1;
		dp[y ^ 1][0][0][0] = 1;
		for(int j = 1; j <= m; j++)
		{
			for(int t = 1; t <= k ;t++)
			{
				//�����ǰλ��ȣ���ô��jλ�϶�������ѡ�ϵģ�֮ǰ�϶���j-1���ٿ���ǰi-1λѡ��ѡ�����ּ��� 
				if(a[i] == b[j]) dp[y][j][t][1] = (dp[y ^ 1][j - 1][t][1] + dp[y ^ 1][j - 1][t - 1][1] + dp[y ^ 1][j - 1][t - 1][0]) % P;
				else dp[y][j][t][1] = 0;//�����ƥ�仹Ҫѡ����ô�϶��ղ���һ����b�� 
				dp[y][j][t][0] = (dp[y ^ 1][j][t][0] + dp[y ^ 1][j][t][1]) % P;//��ǰλ��ѡ�Ļ���ǰi-1λ�϶�ƥ����j�������t�Σ��ٿ���ѡ��ѡ 
			}
		}
	}
	
	cout << (dp[n & 1][m][k][1] + dp[n & 1][m][k][0]) % P;//���϶���n��m��k�������һλѡ��ѡ���п��� 
	
	return 0;
}

//6 3 3
//aabaab
//aab
//
//7
