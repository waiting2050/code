#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <random>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cmath>
using namespace std;
using ll = long long;

const int N = 5e3 + 10;
int a[N];

bool dp[N][20007];//ÄÚ´æ³¬ÏÞ

void solve(void)
{
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];

	dp[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= 5e3; j++)
		{
			dp[i][j] = dp[i - 1][j];
			if (j >= a[i]) dp[i][j] |= dp[i - 1][j - a[i]];
		}
	}
	ll cnt = 0;
	for (int i = 0; i <= 5e3; i++)cnt += dp[n][i];

	cout << cnt;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t = 1;
	while (t--) solve();

	return 0;
}
//3
//1 1 5

//6
