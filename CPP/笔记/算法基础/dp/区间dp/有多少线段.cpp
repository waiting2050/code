#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 507;
int a[N][N], dp[N][N];//dp[i][j]表示在[i,j]间有多少线段 

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, m, q; cin >> n >> m >> q;
	
	for(int i = 1; i <= m; i++)
	{
		int l, r; cin >> l >> r;
		a[l][r]++;
	}
	
	for(int len = 1; len <= n; len++)
		for(int i = 1, j = i + len - 1; j <= n; j++, i++)
			//从大区间逐步缩小到小区间（加上本来存在于区间内部的），同时减去重复部分，加上刚好以i,j为左右端点的 
			dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] + a[i][j];
	
	while(q--)
	{
		int x, y; cin >> x >> y;
		cout << dp[x][y] << '\n';
	}
	
	return 0;
}

