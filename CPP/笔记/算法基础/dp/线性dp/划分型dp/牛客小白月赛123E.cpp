// Problem: 轮符雨
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/122725/E
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define pb push_back

const int P = 1e9 + 7;
const int N = 100 + 7;

// dp[i][j]为用若干段恰好凑出总长度i且累计得分为j的段长序列的数量
ll dp[N][N * N >> 1];

void solve()
{
	int n, t; cin >> n >> t;
	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= t; j++)
			dp[i][j] = 0;
	
	dp[0][0] = 2; // 因为最开始可以选择1或0
	for(int i = 0; i <= n; i++)
	{
		for(int j = 0; j <= min(t, i * (i - 1) / 2); j++)
		{
			if(!dp[i][j]) continue; // 优化1
			
			for(int l = 1; i + l <= n; l++)
			{
				int v = j + ((l - 1) * l >> 1);
				if(v > t) break; // 优化2
				dp[i + l][v] = (dp[i + l][v] + dp[i][j]) % P;
			}
		}
	}
	
	cout << dp[n][t] << '\n';
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int _; cin >> _;
	while(_--) solve();

	return 0;
}

// 2
// 3 1
// 4 3

// 4
// 4


// 1
// 91 78

// 259448003
