// Problem: 小红的gcd
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/123787/E
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// 其实与普通的网格图dp没什么区别，难点在于字符的顺序怎么考虑，比如cgc这个情况，要怎么避免前面使用过的字符不重复出现，因为情况很多
// 比如cgc,cgd,dcg...所以不可能用map之类的辅助标记手段。但是注意到题目给的字符只有三种，那么可以组成的排列其实是3!，那么直接列举
// 每个排列，并且对每个排列走一遍dp计算，最后求和即可。

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define pb push_back

const int P = 998244353;
const int N = 1e3 + 7;

int dx[] = {0, 1, 0};
int dy[] = {0, 0, 1};

int  n;
ll dp[N][N];
char a[N][N];

bool inmp(int x, int y) {return x >= 1 && x <= n && y >= 1 && y <= n;}

int calc(char c1, char c2, char c3)
{
	int sum = (n << 1) - 1;
	int k = sum / 3;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			dp[i][j] = 0;
	
	if(a[1][1] == c1) dp[1][1] = 1;
	else return 0;
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(!dp[i][j]) continue;
			
			for(int ii = 1; ii <= 2; ii++)
			{
				int ni = i + dx[ii];
				int nj = j + dy[ii];
				int step = ni + nj - 1;
				
				if(!inmp(ni, ni)) continue;
				
				char nd;
				if(step <= k) nd = c1;
				else if(step <= k << 1) nd = c2;
				else nd = c3;
				
				if(a[ni][nj] == nd) dp[ni][nj] = (dp[ni][nj] + dp[i][j]) % P;
			}
		}
	}
	
	return dp[n][n];
}

void solve()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cin >> a[i][j];
	
	ll ans = 0;
	string s = "cdg";
	do
	{
		ans = (ans + calc(s[0], s[1], s[2])) % P;
	}while(next_permutation(s.begin(), s.end()));
	
	cout << ans << '\n';
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int _; cin >> _;
	while(_--) solve();

	return 0;
}

// 2
// 2
// gc
// cd
// 5
// cccgg
// gggdg
// ddggd
// gggcd
// ddddd

// 2
// 3
