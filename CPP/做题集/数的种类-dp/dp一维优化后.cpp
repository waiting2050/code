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

const int N = 5e3 + 10, M = 5e5 + 9;
int a[N];
bool dp[M];

void solve(void)
{
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];

	dp[0] = 1;//一个数字都不选也是一种情况 
	for (int i = 1; i <= n; i++)
	{
		for (int j = 5e5; j >= a[i]; j--)//要从后往前遍历，不然可能会重复计算 
		{
			dp[j] |= dp[j - a[i]];//j-a[i]得到下标为j的元素a[i]个位置以前的元素是1或0 
		}//如果是1，那么就说明它可以组成加上a[i]以后得到的数字 。 
	}
	ll cnt = 0;
	for (int i = 0; i <= 5e5; i++) cnt += dp[i];

	cout << cnt;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t = 1;
	while (t--) solve();

	return 0;
}
