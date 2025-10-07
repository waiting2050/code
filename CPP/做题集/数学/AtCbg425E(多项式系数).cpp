// Problem: AT ABC425 E
// Contest: AtCoder - UNIQUE VISION Programming Contest 2025 Autumn (AtCoder Beginner Contest 425)《独特视角编程大赛 2025 年秋季（AtCoder 初级赛 425）》
// URL: https://atcoder.jp/contests/abc425/tasks/abc425_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// https://blog.csdn.net/shulianghan/article/details/109197933 可以看这个了解多项式系数

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int N = 5007;

ll c[N][N];
int p;

void solve()
{
	int n; cin >> n;
	ll ans = 1, sum = 0;
	while(n--) //这里要反过来求，设总和s，求c(s,tn),c(s-tn,tn-1)...c(t1,t1)即s里选tn个，再从s-tn里选tn-1个
	{
		int t; cin >> t;
		sum += t;
		ans = (ans * c[sum][t]) % p;
	}
	cout << ans << '\n';
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int _; cin >> _ >> p;
	
	c[0][0] = 1;
	for(int i = 1; i < N; i++)
	{
		c[i][0] = 1;
		for(int j = 1; j <= i; j++)
		{
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % p; //求组合数
		}
	}
	
	while(_--) solve();

	return 0;
}

// 3 1000000000
// 2
// 2 2
// 5
// 1 1 1 1 1
// 6
// 1 2 3 4 5 6
// 
// 6
// 120
// 230379200
// 
// 
// 3 998244353
// 1
// 1
// 3
// 4 2 5
// 10
// 500 500 500 500 500 500 500 500 500 500
// 
// 1
// 6930
// 261233246