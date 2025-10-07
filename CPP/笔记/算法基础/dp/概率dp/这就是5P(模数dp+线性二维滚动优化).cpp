// Problem: Luogu P11998
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P11998
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 7, MOD = 998244853;

ll dp[2][N];//dp[i][j]:ǰi���������j�ĸ���
ll a[N], p[N];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, m; cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> p[i];
	
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++)
	{
		int y = i & 1;
		for(int j = 0; j < m; j++) dp[y][j] = 0;//�����Ż��漰��+=��ʱ��ǵ��ȶԵ�ǰ��������0 
		
		for(int j = 0; j < m; j++)
		{
			//�������� �൱������һ����ͬj�������ȼ̳�һ�� 
			dp[y][j] = (dp[y][j] + dp[y ^ 1][j] * (1 - p[i] + MOD)) % MOD;
			
			//���Ե���� ֻ���ض���j���ܸ���
			int nj = (j + a[i]) % m;//ע��Ҫ��mȡģ 
			dp[y][nj] = (dp[y][nj] + dp[y ^ 1][j] * p[i]) % MOD;
        }
	}
	
	cout << dp[n & 1][0];//j==0��j%m==0�ܱ����� 
	
	return 0;
}

//5 5
//1 2 3 4 5
//499122427 499122427 499122427 499122427 499122427
//
//748683640
