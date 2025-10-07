#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// ai:= 序列中的第 i 个数（下标从 1 开始）
// dp(i):= 以 ai 为结尾的子序列的最大长度 
// 由于我们要求子序列严格单调上升，那么如果 j<i 且 aj<ai，下一个元素 ai 就可以接到 aj 的后面，那么 dp(i)=dp(j)+1.
// 为了让子序列最长，我们遍历 [1,i)，取最大值即可。
const int N = 1e3 + 7;
ll a[N], dp[N];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	for(int i = 1; i <= n; i++)
	{
		//注意j从0开始，因为j=0时，由于dp=max(dp,dp+1),会将dp[1]赋值为1
		for(int j = 0; j < i; j++)
			if(a[j] <= a[i]) dp[i] = max(dp[i], dp[j] + 1ll);
	}
			
	ll ans = 0;
	for(int i = 1; i <= n; i++) ans = max(ans, dp[i]);
	
	cout << ans;
  	
  	return 0;
}

// 6
// 1 5 3 4 7 6
// 
// 4
